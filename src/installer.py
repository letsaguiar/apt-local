import tarfile
import click
import os

import github
import config

from typing import Dict, List

def get_installed_packages() -> List:
	return (os.listdir("./sources"))

def get_command_value(package_config: Dict, command: Dict, key: str) -> str:
	return (
		command[key].format(
			version=package_config["version"]
		)
	)

def install(package_config: Dict, package_release: Dict) -> None:
	for command in package_config["commands"]:
		match command["command"]:
			case "download":
				package_asset = github.get_package_asset(
					package_release, get_command_value(package_config, command, "asset")
				)

				github.download_package_asset(
					package_asset, get_command_value(package_config, command, "destination")
				)
			case "extract":
				file = tarfile.open(get_command_value(package_config, command, "source"))
				file.extractall(get_command_value(package_config, command, "destination"))
				file.close()
			case "copy":
				os.system(
					"".join((
						"cp -r ",
						get_command_value(package_config, command, 'source'), " ",
						get_command_value(package_config, command, 'destination')
					))
				)


def clean_installation() -> None:
	os.system("rm -rf downloads && mkdir downloads")

def uninstall(package_name: str) -> None:
	os.system(f"rm -rf sources/{package_name}")

def build_local_path() -> None:
	installed_packages = get_installed_packages()
	fd = open('local-path.txt', 'w')

	for package in installed_packages:
		package_config = config.get_package_config(package)
		fd.write(f"sources/{package_config['path']}\n")

	fd.close()

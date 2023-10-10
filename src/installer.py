import wget
import tarfile
import click
import os

import config

from typing import Dict

def download_and_extract(package_config: Dict, package_asset: Dict) -> None:
	download_name = f"downloads/{package_config['name']}.tar.gz"
	source_name = f"sources/{package_config['name']}"

	try:
		wget.download(package_asset["browser_download_url"], out=download_name)

		file = tarfile.open(download_name)
		file.extractall(source_name)
		file.close()
	except:
		click.echo("Unable to download package binary")
		exit()

def build_local_path() -> None:
	installed_packages = os.listdir('./sources')
	fd = open('local-path.txt', 'w')

	for package in installed_packages:
		package_config = config.get_package_config(package)
		fd.write(f"sources/{package_config['name']}/{package_config['path']}\n")

	fd.close()

def clean_installation() -> None:
	os.system("rm -rf downloads && mkdir downloads")

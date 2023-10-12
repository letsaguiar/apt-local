import click
import os

import config
import github
import installer

@click.group()
def cli():
	pass

@click.command()
@click.argument('package')
def list(package: str):
	"""List available versions of PACKAGE."""

	package_config = config.get_package_config(package)
	package_releases = github.get_package_release_all(package_config["github_url"])

	for release in package_releases:
		click.echo(release["tag_name"])

@click.command()
@click.argument('package_name')
@click.option('--release', '-r', help='github tag_name of the desired release')
def install(package_name: str, release: str):
	"""Install PACKAGE desired version

	Installs the version of PACKAGE defined by -r or --release.
	If no release option is provided, installs the last one.
	"""

	if package_name in installer.get_installed_packages():
		click.confirm(f"Previous {package_name} version found. Do you want to override it and install the newer version?", abort=True)

	# Get package config
	package_config = config.get_package_config(package_name)

	# Get package release
	if release:
		package_release = github.get_package_release(package_config['github_url'], release)
	else:
		package_release = github.get_package_release_latest(package_config['github_url'])

	# Update package config
	package_config.update(version=package_release["tag_name"])

	# Install
	installer.install(package_config, package_release)
	installer.build_local_path()
	installer.clean_installation()

@click.command()
@click.argument('package_name')
def remove(package_name: str):
	"""Removes PACKAGE from installed sources

	Removes PACKAGE from installed sources and its binary path from $PATH.
	"""
	if not package_name in installer.get_installed_packages():
		click.echo(f"{package_name} is not installed.")
		exit()

	click.confirm(f"Are you sure you want to uninstall {package_name}?", abort=True)
	installer.uninstall(package_name)
	installer.build_local_path()

@click.command()
def update():
	"""Updates apt-local source code and configs.

	Fetches github to pull the latest release of apt-local.
	"""
	os.system("git pull origin master > /tmp/null 2>&1")

cli.add_command(list)
cli.add_command(install)
cli.add_command(remove)
cli.add_command(update)

if __name__ == "__main__":
	cli()

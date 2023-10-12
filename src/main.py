import click

import config
import github
import installer

@click.group()
def cli():
    pass

@click.command()
@click.argument('package_name')
def list(package_name: str):
    package_config = config.get_package_config(package_name)
    package_releases = github.get_package_release_all(package_config["github_url"])

    for release in package_releases:
        click.echo(release["tag_name"])

@click.command()
@click.argument('package_name')
@click.option('--release', '-r', help='github tag_name of the desired release')
def install(package_name: str, release: str):
	if package_name in installer.get_installed_packages():
		click.confirm(f"Previous {package_name} version found. Do you want to override it and install the newer version?", abort=True)

	package_config = config.get_package_config(package_name)

	if release:
		package_release = github.get_package_release(package_config['github_url'], release)
	else:
		package_release = github.get_package_release_latest(package_config['github_url'])

	package_asset = github.get_package_asset(package_release, package_config["assets"]["linux"])

	installer.install(package_config, package_asset)
	installer.build_local_path()
	installer.clean_installation()

@click.command()
@click.argument('package_name')
def remove(package_name: str):
	if not package_name in installer.get_installed_packages():
		click.echo(f"{package_name} is not installed.")
		exit()

	click.confirm(f"Are you sure you want to uninstall {package_name}?", abort=True)
	installer.uninstall(package_name)
	installer.build_local_path()

cli.add_command(list)
cli.add_command(install)
cli.add_command(remove)

if __name__ == "__main__":
    cli()

import click
import wget
import tarfile
import os

import config
import github

@click.group()
def cli():
    pass

@click.command()
@click.argument('package_name')
def list(package_name: str):
    package_config = config.get_package_config(package_name)
    package_releases = github.get_package_releases(package_config["github_url"])

    for release in package_releases:
        click.echo(release["tag_name"])

@click.command()
@click.argument('package_name')
def install(package_name: str):
	package_config = config.get_package_config(package_name)
	selected_release = github.get_package_latest_release(package_config['github_url'])
	selected_asset = github.get_package_asset(selected_release, package_config["asset_name"])

	tar_name = f"downloads/{package_config['name']}.tar.gz"
	folder_name = f"sources/{package_config['name']}"
	wget.download(selected_asset["browser_download_url"], out=tar_name)

	tar_file = tarfile.open(tar_name)
	tar_file.extractall(folder_name)
	tar_file.close()

	with open(f"installer.txt", "a") as fd:
		fd.write(f"{os.getcwd()}/{folder_name}/{package_config['binary']}\n")

	os.system("rm -rf downloads && mkdir downloads")

cli.add_command(list)
cli.add_command(install)

if __name__ == "__main__":
    os.chdir('/home/leticia-aguiar/.apt-local')
    cli()

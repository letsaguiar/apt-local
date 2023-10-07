#!venv/bin/python3

import json
import click
import config
import github

@click.group()
def cli():
    pass

@click.command()
@click.argument('package_name')
def list(package_name: str):
    package_config = config.get_package_config(package_name)
    package_config = json.loads(package_config)

    package_releases = github.get_package_releases(package_config["github_url"])
    package_releases = json.loads(package_releases)

    for release in package_releases:
        click.echo(release["tag_name"])

cli.add_command(list)

if __name__ == "__main__":
    cli()

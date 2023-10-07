#!venv/bin/python3

import click
import config

@click.group()
def cli():
    pass

@click.command()
@click.argument('package_name')
def list(package_name: str):
    package_config = config.get_package_config(package_name)
    click.echo(package_config)

cli.add_command(list)

if __name__ == "__main__":
    cli()

#!venv/bin/python3

import click

@click.group()
def cli():
    pass

@click.command()
def list():
    pass

cli.add_command(list)

if __name__ == "__main__":
    cli()

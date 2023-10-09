import json
import click

from typing import Dict

def get_package_config(package_name: str) -> Dict:
    try:
        with open(f"configs/{package_name}.json") as fd:
            return (json.loads(fd.read()))
    except:
        click.echo(f"Unable to find {package_name} config file")
        exit()

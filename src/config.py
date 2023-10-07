import json

import click

class PackageConfig():
    name: str
    github_url: str

def get_package_config(package_name: str) -> PackageConfig:
    try:
        package_config: PackageConfig
        with open(f"configs/{package_name}.json") as fd:
            package_config = json.load(fd)
        return (package_config)
    except:
        click.echo(f"Unable to find {package_name} config file")
        exit()

import json
import click
import requests

from typing import Dict

def get_package_releases(github_url: str) -> Dict:
    try:
        package_releases = requests.get(f"{github_url}/releases").text 
        return (json.loads(package_releases))
    except:
        click.echo("Unable to fetch Github API")
        exit()

def get_package_latest_release(github_url) -> Dict:
    try:
        package_releases = requests.get(f"{github_url}/releases").text
        package_releases = json.loads(package_releases)

        return (package_releases[0])
    except:
        click.echo("Unable to fetch Github API")
        exit()

def get_package_asset(package_release: Dict, asset_name: str) -> Dict:
    for asset in package_release["assets"]:
        if asset["name"] == asset_name:
            return (asset)

    click.echo("Unable to find the selected asset")
    exit()

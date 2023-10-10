import json
import click
import requests

from typing import Dict

def get_package_release_all(github_url: str) -> Dict:
    try:
        package_releases = requests.get(f"{github_url}/releases").text
        return (json.loads(package_releases))
    except:
        click.echo("Unable to fetch Github API")
        exit()

def get_package_release_latest(github_url: str) -> Dict:
    try:
        package_releases = get_package_release_all(github_url)
        return (package_releases[0])
    except:
        click.echo("Unable to fetch Github API")
        exit()

def get_package_release(github_url: str, release: str) -> Dict:
    package_releases = get_package_release_all(github_url)

    for package_release in package_releases:
        if package_release["tag_name"] == release:
            return (package_release)

    click.echo("Unable to find the selected release")
    exit()

def get_package_asset(package_release: Dict, asset_name: str) -> Dict:
    for asset in package_release["assets"]:
        if asset["name"] == asset_name.format(version=package_release["tag_name"]):
            return (asset)

    click.echo("Unable to find the selected asset")
    exit()

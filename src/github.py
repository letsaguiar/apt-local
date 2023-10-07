import click
import requests

def get_package_releases(github_url: str) -> str:
    try:
        return (requests.get(f"{github_url}/releases").text)
    except:
        click.echo("Unable to fetch Github API")
        exit()

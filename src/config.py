import click

def get_package_config(package_name: str) -> str:
    try:
        with open(f"configs/{package_name}.json") as fd:
            return (fd.read())
    except:
        click.echo(f"Unable to find {package_name} config file")
        exit()

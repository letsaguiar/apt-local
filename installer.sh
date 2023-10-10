#!/bin/bash

cd $HOME/.apt-local

echo "> Creating python venv..."
python3 -m venv venv

echo "> Installing dependencies..."
source ./venv/bin/activate
pip install -r requirements.txt

echo "> Creating required directories"
mkdir downloads
mkdir sources

echo "> Creating required configs"
mkdir -p sources/apt-local
cp apt-local sources/apt-local
chmod +x sources/apt-local/apt-local
echo "$HOME/.apt-local/sources/apt-local" > installer.txt

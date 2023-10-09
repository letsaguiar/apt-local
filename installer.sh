#!/bin/bash

echo "> Creating python venv..."
python3 -m venv venv

echo "> Installing dependencies..."
source ./venv/bin/activate
pip install -r requirements.txt

echo "> Creating required directories"
mkdir downloads
mkdir sources

echo "> Creating required configs"
touch installer.txt

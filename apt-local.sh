export APT_LOCAL_DIR="$HOME/.apt-local"
export APT_LOCAL_VENV="$APT_LOCAL_DIR/venv"

if [ ! -d "$APT_LOCAL_DIR/venv" ];
then
	# Move to APT_LOCAL directory
	current_dir=$(pwd)
	cd $APT_LOCAL_DIR

	# Create python venv and install dependencies
	python3 -m venv venv
	source $APT_LOCAL_VENV/bin/activate
	pip install -r requirements.txt > /tmp/null

	# Move back to the original working directory
	deactivate
	cd $current_dir
fi

if [ ! -d "$APT_LOCAL_DIR/downloads" ];
then
	# Move to APT_LOCAL directory
	current_dir=$(pwd)
	cd $APT_LOCAL_DIR

	# Create downloads folder
	mkdir -p downloads > /tmp/null

	# Move back to the original working directory
	cd $current_dir
fi

if [ ! -d "$APT_LOCAL_DIR/sources" ];
then
	# Move to APT_LOCAL directory
	current_dir=$(pwd)
	cd $APT_LOCAL_DIR

	# Create sources folder
	mkdir -p sources > /tmp/null

	# Move back to the original working directory
	cd $current_dir
fi

apt-local() {
	# Move to APT_LOCAL directory
	current_dir=$(pwd)
	cd $APT_LOCAL_DIR
	source $APT_LOCAL_VENV/bin/activate

	# Create sources folder
	python3 ./src/main.py $@

	# Move back to the original working directory
	deactivate
	cd $current_dir
}

if [ -f "$APT_LOCAL_DIR/local-path.txt" ];
then
	binaries=( $(cat $APT_LOCAL_DIR/local-path.txt) )
	for binary in ${binaries[@]};
	do
		PATH=$PATH:$APT_LOCAL_DIR/$binary
	done
fi

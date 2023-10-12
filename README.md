<div align="center">
<h1 align="center">
<img src="https://raw.githubusercontent.com/PKief/vscode-material-icon-theme/ec559a9f6bfd399b82bb44393651661b08aaf7ba/icons/folder-markdown-open.svg" width="100" />
<br>apt-local</h1>

## 📖 Table of Contents
- [📖 Table of Contents](#-table-of-contents)
- [📍 Overview](#-overview)
- [🚀 Getting Started](#-getting-started)
    - [🔧 Installation](#-installation)
    - [🤖 Running](#-running)
- [🤝 Contributing](#-contributing)
- [📄 License](#-license)

---

## 📍 Overview
apt-local is a package manager that uses pre-compiled binaries to install linux applications locally, without root privileges. It's highly extendable and opened to open source community. With apt-local you can create your own plugins (or install instructions) as simple JSON files or you can install packages from our official list of supported packages.

With apt-local, managing packages is easier. All package's source code is located at `$APT_LOCAL_DIR/sources/<package_name>` and it's executable path is located at `$APT_LOCAL_DIR/local-path.txt`. Installing packages locally, just for your user, you also keep your system safer, protecting other users from any security breach.

## 🚀 Getting Started

### 🔧 Installation

1. Clone the apt-local repository:
```sh
git clone https://github.com/letsaguiar/apt-local ~/.apt-local
```

2. Add the following code to your shell config:
```sh
. "$HOME/.apt-local/apt-local.sh"
```

### 🤖 Running
Open a new terminal and type:
```sh
apt-local --help
```

## 🤝 Contributing
Contributions are always welcome! Please follow these steps:

1. Fork the project repository.

2. Create a new branch with a descriptive name (e.g., `new-feature-branch` or `bugfix-issue-123`).
```sh
git checkout -b new-feature-branch
```

3. Commit your changes with a clear commit message that explains the changes you've made.
```sh
git commit -m 'Implemented new feature.'
```

4. Push your changes to your forked repository
```sh
git push origin new-feature-branch
```

5. Create a new pull request describing the changes you've made and why they're necessary.

The project maintainers will review your changes and provide feedback or merge them into the main branch.

## 📄 License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for additional info.

---


## QtImageViewer app

This is a simple Qt-based application which communicates with https://jsonplaceholder.typicode.com/
It allows to see users, albums and photos providing by {JSON} Placeholder
​

## Prerequisites

- Minimal Qt version is 5.15
- Compiler with C++17 support
​

## Build & Run

There are two general ways of "How To" Build & Run QtImageViewer application.

**Way 1:**
- Use QtCreator to build the project (QtImageViewer.pro)
- In order to run QtImageViewer application it's needed to set Run configuration to "app"
- In order to run unit test it's needed to set Run configuration to "test"

**Way 2 (tested only on Ubuntu 20.04.4 LTS):**
- Open Terminal in QtImageViewer application root folder
- There is a `build_run.sh` script inside, it's possible to use it in a 3 different ways:
  * Run `./build_run.sh` command in Terminal in order just to build QtImageViewer application
  * Run `./build_run.sh run` command in Terminal in order to build & run QtImageViewer application
  * Run `./build_run.sh test` command in Terminal in order to build the app and run unit tests

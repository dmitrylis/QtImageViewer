#!/bin/bash

qmake QtImageViewer.pro
qmake
make

LD_LIBRARY_PATH=$LD_LIBRARY_PATH:"./src"
export LD_LIBRARY_PATH

if [[ $1 == run ]]; then
    echo "Starting application..."
    exec "./app/app"
elif [[ $1 == test ]]; then
    echo "Starting unit tests..."
    exec "./tests/tests"
fi

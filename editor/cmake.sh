#!/bin/sh

if [[ $1 == "-d" ]]; then
    mkdir debug
    cd debug
    cmake -DCMAKE_BUILD_TYPE=Debug ..
    make
fi

if [[ $1 == "-ce" ]]; then
    mkdir build
    cd build/
    cmake ..
    make
    ./portal-editor
    cd ..
    rm -r build/
fi

if [[ $1 == "-c" ]]; then
    mkdir build
    cd build/
    cmake ..
    make
    cd ..
fi

if [[ $1 == "-e" ]]; then
    cd build/
    ./portal-editor
    cd ..
fi


if [[ $1 == "-clean" ]]; then
    rm -r build/
    rm -r debug/
fi

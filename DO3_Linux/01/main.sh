#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Requred one parameter"
    exit 1
fi

source ./is-string
result=$(is-string "$1")

echo $result

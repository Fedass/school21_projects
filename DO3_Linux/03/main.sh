#!/bin/bash

if [[ $# > 4 ]]; then
    echo "Too many params"
    exit 1
fi

source ./print-params
results=$(print-params $1 $2 $3 $4)
echo -e "$results"

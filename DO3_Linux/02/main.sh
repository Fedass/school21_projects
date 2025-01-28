#!/bin/bash

if [ $# -ne 0 ]; then
    echo "Do not enter the params!"
    exit 1
fi

source ./print-params
results=$(print-params)

printf "%s\n" "$results"

source ./save-params
save-params "$results"

#!/bin/bash

if [[ $# > 0 ]]; then
    echo "No params required!"
    exit 1
fi

source ./config-scan

source ./print-params
results=$(print-params $(config-scan))
echo -e "$results"

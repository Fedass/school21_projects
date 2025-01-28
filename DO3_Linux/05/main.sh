#!/bin/bash
 { 
    start=$(date +%s%3N)
    if [ ! $# -eq 1 ]; then
        echo "Required one param!"
        exit 1
    fi

    if [ ! -d $1 ]; then
        echo "Directory $1 not found"
        exit 1
    fi

    if [ ! -r $1 ]; then
        echo "Directory $1 is not available for reading"
    fi

    source ./print-dir

    result=$(print-dir $1)
    printf "%s\n" "$result"

    end=$(date +%s%3N) 
    elapsed=$((end - start))
    elapsed_seconds=$(echo "scale=2; $elapsed / 1000" | bc)
    echo "Script execution time (in seconds) = $elapsed_seconds"
} 2>&1
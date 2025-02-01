#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Too many params!"
    exit 1
fi

option="$1"

if ! [[ "$option" =~ ^[1-4]$ ]]; then
    echo "Error: Invalid option. Must be 1, 2, 3, or 4."
    exit 1
fi

log_files=$(ls ../04/nginx_log_day_*.log 2>/dev/null)
if [ -z "$log_files" ]; then
    echo "Error: No log files found (nginx_log_day_*.log)"
    exit 1
fi

case "$option" in
    1)  awk '{print $0}' $log_files | sort -k9,9n 
        ;;
    2)  awk '{print $1}' $log_files | sort | uniq 
        ;;
    3)  awk '$9 ~ /^[45][0-9][0-9]$/' $log_files
        ;;
    4)  awk '$9 ~ /^[45][0-9][0-9]$/ {print $1}' $log_files | sort | uniq 
        ;;
esac






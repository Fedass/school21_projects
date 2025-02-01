#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Required 1 param!"
    exit 1
fi

method="$1"

if ! [[ "$method" =~ ^[1-3]$ ]]; then
    echo "Error: Invalid method. Method must be 1, 2, or 3."
    exit 1
fi

delete_file_or_folder() {
    local path="$1"
    if [[ -e "$path" ]]; then
        if [[ -f "$path" ]]; then
            if sudo rm -f "$path"; then
                echo "Deleted file: $path"
            else
                echo "Error: Failed to delete file $path" >&2
            fi
        elif [[ -d "$path" ]]; then
            if sudo rm -rf "$path"; then
                echo "Deleted directory: $path"
            else
                echo "Error: Failed to delete directory $path" >&2
            fi
        fi
    else
        echo "Error: $path does not exist."
    fi
}

if [ "$method" -eq 1 ]; then
    read -p "Enter the path to the log file: " log_file

    if [ ! -r "$log_file" ]; then
        echo "Error: Log file $log_file does not exist or is not readable." >&2
        exit 1
    fi

    while IFS= read -r line; do
        if [[ "$line" =~ ^/ ]]; then
            path=$(echo "$line" | cut -d '|' -f 1 | xargs)
            delete_file_or_folder "$path"
        fi
    done < "$log_file"

elif [ "$method" -eq 2 ]; then
    read -p "Enter the start time (YYYY-MM-DD HH:MM): " start_time
    read -p "Enter the end time (YYYY-MM-DD HH:MM): " end_time

    start_timestamp=$(date -d "$start_time" +%s 2>/dev/null)
    end_timestamp=$(date -d "$end_time" +%s 2>/dev/null)

    if [ -z "$start_timestamp" ] || [ -z "$end_timestamp" ]; then
        echo "Error: Invalid date/time format."
        exit 1
    fi

    find / -regextype posix-extended -regex '.*/[a-z]+_[0-9]{6}' 2>/dev/null | while read -r path; do
        creation_time=$(stat -c %Y "$path" 2>/dev/null)
        if [ -n "$creation_time" ] && [ "$creation_time" -ge "$start_timestamp" ] && [ "$creation_time" -le "$end_timestamp" ]; then
            delete_file_or_folder "$path"
        fi
    done

elif [ "$method" -eq 3 ]; then
    read -p "Enter the name mask (characters_underlining_date): " name_mask
    find / -name "*$name_mask*" 2>/dev/null | while read -r path; do
        delete_file_or_folder "$path"
    done
fi

find / -type d -empty -delete 2>/dev/null

echo "Cleanup completed successfully."

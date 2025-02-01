#!/bin/bash

if [ "$#" -ne 6 ]; then
    echo "Required 6 params!"
    exit 1
fi

abs_path="$1"
num_subfolders="$2"
folder_letters="$3"
num_files="$4"
file_letters="$5"
file_size="${6%kb}"

if [[ "$abs_path" != /* ]]; then
    echo "Error: The path must be an absolute path starting with /."
    exit 1
fi

if [ "$num_subfolders" -le 0 ]; then
    echo "The number of subfolders must be greater than zero."
    exit 1
fi

if [ ${#folder_letters} -gt 7 ]; then
    echo "The list of letters must contain no more than 7 characters."
    exit 1
fi

if [ "$num_files" -le 0 ]; then
    echo "The number of files must be greater than zero."
    exit 1
fi

if [ "$file_size" -gt 100 ]; then
    echo "Error: File size must be less than or equal to 100kb."
    exit 1
fi

date=$(date +"%d%m%y")
log_file="log_$date.txt"

echo "Log file for script $0 run on $date" > $log_file
echo "Parameters: $@" >> $log_file
echo "Created folders and files:" >> $log_file

generate_random_string() {
    local template_string="$1"
    local random_string=""
    for (( i=0; i<${#template_string}; i++ )); do
        char=${template_string:$i:1}
        repeat=$(( ( RANDOM % 5 )  + 2 ))
        for (( j=0; j<$repeat; j++ )); do
            random_string+=$char
        done
    done
    echo "$random_string"
}

for ((i=1; i<=num_subfolders; i++)); do
    folder_name=$(generate_random_string "$folder_letters")
    folder_name+="_$date"

    if ! mkdir -p "$abs_path/$folder_name"; then
        echo "Error: Failed to create folder $abs_path/$folder_name" >&2
        exit 1
    fi

    for ((j=1; j<=num_files; j++)); do
        file_name=$(generate_random_string "${file_letters%%.*}")
        file_name+="_$date"
        file_ext=$(generate_random_string "${file_letters#*.}")

        if ! dd if=/dev/zero of="$abs_path/$folder_name/$file_name.$file_ext" bs=1024 count=$file_size >/dev/null 2>&1; then
            echo "Error: Failed to create file $abs_path/$folder_name/$file_name.$file_ext" >&2
            exit 1
        fi

        creation_date=$(stat -c %y "$abs_path/$folder_name/$file_name.$file_ext")
        size_in_bytes=$(stat -c %s "$abs_path/$folder_name/$file_name.$file_ext")
        echo "$abs_path/$folder_name/$file_name.$file_ext | $creation_date | $size_in_bytes bytes" >> $log_file
        
        free_space=$(df --output=avail / | tail -n 1)
        if [ "$free_space" -lt 1048576 ]; then
            echo "Warning: Less than 1GB of free space left on the / partition. Stopping script." >&2
            exit 1
        fi
    done
done

echo "End of log file." >> $log_file
echo "Script completed successfully. See $log_file for details."

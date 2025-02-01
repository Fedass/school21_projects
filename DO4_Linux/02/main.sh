#!/bin/bash

if [ "$#" -ne 3 ]; then
    echo "Required 3 params!"
    exit 1
fi

if [ ${#1} -gt 7 ]; then
    echo "The list of letters for folder names must contain no more than 7 characters."
    exit 1
fi

file_letters_array=(${2//./ })
if [ ${#file_letters_array[0]} -gt 7 ] || [ ${#file_letters_array[1]} -gt 3 ]; then
    echo "The list of letters for file names must contain no more than 7 characters before the dot and no more than 3 characters after the dot."
    exit 1
fi

folder_letters="$1"
file_letters="$2"
file_size="${3%Mb}"

if [ "$file_size" -gt 100 ]; then
    echo "Error: File size must be less than or equal to 100Mb"
    exit 1
fi

date=$(date +"%d%m%y")
log_file="log_$date.txt"

echo "Log file for script $0 run on $date" > $log_file
echo "Parameters: $@" >> $log_file
echo "Created folders and files:" >> $log_file

start_time=$(date +%s)

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
    
    while [ ${#random_string} -lt 5 ]; do
        char=${template_string:$(( RANDOM % ${#template_string} )):1}
        random_string+=$char
    done
    
    echo "$random_string"
}

dirs=($(find / -type d -not -path "*bin*" -not -path "*sbin*"))

for ((i=1; i<=100; i++)); do
    folder_name=$(generate_random_string "$folder_letters")
    folder_name+="_$date"

    abs_path=${dirs[$(( RANDOM % ${#dirs[@]} ))]}
    
    if ! mkdir -p "$abs_path/$folder_name"; then
        echo "Error: Failed to create folder $abs_path/$folder_name" >&2
        continue
    fi
    
    num_files=$(( ( RANDOM % 10 ) + 1 ))
    
    for ((j=1; j<=num_files; j++)); do
        file_name=$(generate_random_string "${file_letters%%.*}")
        file_name+="_$date"
        file_ext=$(generate_random_string "${file_letters#*.}")

        if ! dd if=/dev/zero of="$abs_path/$folder_name/$file_name.$file_ext" bs=$((1024*1024)) count=$file_size >/dev/null 2>&1; then
            echo "Error: Failed to create file $abs_path/$folder_name/$file_name.$file_ext" >&2
            continue
        fi
        
        creation_date=$(stat -c %y "$abs_path/$folder_name/$file_name.$file_ext")
        size_in_bytes=$(stat -c %s "$abs_path/$folder_name/$file_name.$file_ext")
        
         echo "$abs_path/$folder_name/$file_name.$file_ext | $creation_date | $size_in_bytes bytes" >> $log_file
        
         free_space=$(df --output=avail / | tail -n 1)
         if [ "$free_space" -lt 1048576 ]; then
             echo "Warning: Less than 1GB of free space left on the / partition. Stopping script." >&2
             break 2
         fi
        
    done
    
done

end_time=$(date +%s)
total_time=$((end_time - start_time))

echo "End of log file." >> $log_file
echo "Start time: $(date -d @$start_time)" >> $log_file
echo "End time: $(date -d @$end_time)" >> $log_file
echo "Total running time: $total_time seconds" >> $log_file
echo "Start time: $(date -d @$start_time)"
echo "End time: $(date -d @$end_time)"
echo "Total running time: $total_time seconds"
echo "Script completed successfully. See $log_file for details."

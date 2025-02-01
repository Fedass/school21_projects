#!/bin/bash

if [ $# -ne 0 ]; then
    echo "Script runs without parameters"
    exit 1
fi

response_codes=(200 201 400 401 403 404 500 501 502 503)
methods=(GET POST PUT PATCH DELETE)
agents=(
    "Mozilla/5.0"
    "Google Chrome/91.0"
    "Opera/77.0"
    "Safari/14.1"
    "Internet Explorer/11.0"
    "Microsoft Edge/91.0"
    "Crawler and bot"
    "Library and net tool"
)

generate_ip() {
    printf "%d.%d.%d.%d" "$((RANDOM % 256))" "$((RANDOM % 256))" "$((RANDOM % 256))" "$((RANDOM % 256))"
}

generate_date() {
    local log_day="$1"
    printf "%02d/Jan/2025:%02d:%02d:%02d +0000" "$log_day" "$((RANDOM % 24))" "$((RANDOM % 60))" "$((RANDOM % 60))"
}

generate_request_url() {
    local method="$1"
    printf "/%s/%07d" "$method" "$((RANDOM % 10000000))"
}

for log_day in {1..5}; do
    log_file="nginx_log_day_${log_day}.log"

    num_entries=$((RANDOM % 901 + 100))

    for ((entry = 1; entry <= num_entries; entry++)); do
        ip=$(generate_ip)
        response_code=${response_codes[RANDOM % ${#response_codes[@]}]}
        method=${methods[RANDOM % ${#methods[@]}]}
        date=$(generate_date "$log_day")
        request_url=$(generate_request_url "$method")
        agent=${agents[RANDOM % ${#agents[@]}]}

        printf "%s - - [%s] \"%s %s HTTP/1.1\" %d %d \"%s\" \"%s\"\n" \
            "$ip" "$date" "$method" "$request_url" "$response_code" "$((RANDOM % 1000))" "-" "$agent"
    done | sort -k4 >>"$log_file"
done


# Response codes:
# 200 - OK: Запрос был успешным.
# 201 - Created: Запрос был успешным и был создан новый ресурс.
# 400 - Bad Request: Запрос был неправильно сформирован или недействителен.
# 401 - Unauthorized: Запрос требует аутентификации.
# 403 - Forbidden: Запрашивающий не имеет права доступа к запрашиваемому ресурсу.
# 404 - Not Found: Запрашиваемый ресурс не может быть найден.
# 500 - Internal Server Error: На сервере произошла ошибка при обработке запроса.
# 501 - Not Implemented: Запрашиваемый метод не поддерживается сервером.
# 502 - Bad Gateway: Сервер получил недействительный ответ от вышестоящего сервера при обработке запроса.
# 503 - Service Unavailable: Сервер в настоящее время не может обработать запрос из-за технического обслуживания или перегрузки.
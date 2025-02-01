#!/bin/bash

if [ "$#" -ne 0 ]; then
    echo -e "Error. The script must be run with 0 parameters."
    exit 1
fi

goaccess ../04/nginx_log_day_1.log --log-format=COMBINED > report.html
sudo mv report.html /var/www/html/

#http://localhost/report.html

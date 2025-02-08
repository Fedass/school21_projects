#!/bin/bash

gcc web_server.c -o web_server -lfcgi
spawn-fcgi -p 8080 ./web_server
sudo systemctl restart nginx
docker cp nginx.conf my_nginx:/etc/nginx/nginx.conf
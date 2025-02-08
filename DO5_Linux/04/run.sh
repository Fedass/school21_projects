#!/bin/bash

gcc -Wall -Werror -Wextra web_server.c -o web_server -lfcgi
spawn-fcgi -p 8080 web_server
nginx -g 'daemon off;'
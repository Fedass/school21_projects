FROM imported_nginx:latest
WORKDIR /home/
RUN apt-get update && apt-get install -y libfcgi-dev gcc spawn-fcgi
COPY ./web_server.c .
COPY ./nginx.conf /etc/nginx/nginx.conf
COPY ./run.sh .
ENTRYPOINT [ "../docker-entrypoint.sh" ]
CMD ["sh", "./run.sh"]
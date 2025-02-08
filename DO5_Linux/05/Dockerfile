FROM imported_nginx:latest

WORKDIR /home/

RUN apt-get update && \
    apt-get install -y libfcgi-dev gcc spawn-fcgi && \
    rm -rf /var/lib/apt/lists 

COPY ./web_server.c .
COPY ./nginx.conf /etc/nginx/nginx.conf
COPY ./run.sh .

RUN useradd -m shermanb && \
    chown -R shermanb:shermanb /etc/nginx/nginx.conf && \
    chown -R shermanb:shermanb /var/cache/nginx && \
    chown -R shermanb:shermanb /home && \
    touch /var/run/nginx.pid && \
    chown -R shermanb:shermanb /var/run/nginx.pid && \
    chmod u-s /usr/bin/newgrp && \ 
    chmod g-s /usr/bin/chage &&\
    chmod u-s /bin/mount && \
    chmod g-s /sbin/unix_chkpwd &&\
    chmod u-s /bin/umount && \
    chmod u-s /usr/bin/chfn && \
    chmod u-s /bin/su && \
    chmod g-s /usr/bin/expiry && \
    chmod u-s /usr/bin/passwd && \
    chmod u-s /usr/bin/gpasswd && \
    chmod u-s /usr/bin/chsh 

USER shermanb

HEALTHCHECK --interval=1m --timeout=10s \
  CMD curl -f http://localhost/ || exit 1
  
ENTRYPOINT [ "../docker-entrypoint.sh" ]
CMD ["sh", "./run.sh"]
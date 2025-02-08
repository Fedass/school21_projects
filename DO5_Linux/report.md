# Отчет по выполнению проекта DO5_SimpleDocker

## Part 1. Готовый докер

1. ##### Взял официальный докер-образ с **nginx** и выкачал его при помощи `docker pull`.
![1-1](images/image1.1.png)
> docker pull nginx

2. ##### Проверил наличие докер-образа через `docker images`.
![1-2](images/image1.2.png)
> docker images

3. ##### Запустил докер-образ через `docker run -d [image_id|repository]`.
![1-3](images/image1.3.png)
> docker run image

4. ##### Проверил, что образ запустился через `docker ps`.
![1-4](images/image1.4.png)
> starting image

5. ##### Посмотрел информацию о контейнере через `docker inspect [container_id|container_name]`.
![1-5](images/image1.5.png)
> inspect image

- ##### По выводу команды определил размер контейнера, список замапленных портов и ip контейнера.
- "IPAddress": "172.17.0.2"
- "80/tcp": null. Порт 80/tcp открыт, но не замаплен на хост.

![1-6](images/image1.6.png)
> docker size

6. ##### Остановил докер контейнер через `docker stop [container_id|container_name]`.
![1-7](images/image1.7.png)
> docker stop

7. ##### Проверил, что контейнер остановился через `docker ps`.
![1-8](images/image1.8.png)
> no running docker

8. ##### Запустил докер с портами 80 и 443 в контейнере, замапленными на такие же порты на локальной машине, через команду *run*.
![1-9](images/image1.9.png)
> docker run

9. ##### Проверил, что в браузере по адресу *localhost:80* доступна стартовая страница **nginx**.
![1-10](images/image1.10.png)
> localhost:80

10. ##### Перезапустил докер контейнер через `docker restart [container_id|container_name]`.
![1-11](images/image1.12.png)
> docker restart

11. ##### Проверил любым способом, что контейнер запустился.
![1-12](images/image1.13.png)
> docker ps

## Part 2. Операции с контейнером

1. ##### Прочитал конфигурационный файл *nginx.conf* внутри докер контейнера через команду *exec*.
![2-1](images/image2.1.png)
> nginx.conf

2. ##### Создал на локальной машине файл *nginx.conf*. Настроил в нем по пути */status* отдачу страницы статуса сервера **nginx**.
![2-2](images/image2.2.png)
> local nginx.conf

3. ##### Скопировал созданный файл *nginx.conf* внутрь докер-образа через команду `docker cp`.
![2-3](images/image2.3.png)
> docker cp nginx.conf

4. ##### Перезапустил **nginx** внутри докер-образа через команду *exec*.
![2-4](images/image2.4.png)
> docker exec nginx restart

5. ##### Проверил, что по адресу *localhost:80/status* отдается страничка со статусом сервера **nginx**.
![2-5](images/image2.5.png)
> localhost:80/status

![2-6](images/image2.6.png)
> curl localhost/status

6. ##### Экспортировал контейнер в файл *container.tar* через команду *export*.
![2-7](images/image2.7.png)
> docker export 

7. ##### Остановил контейнер.
![2-8](images/image2.8.png)
> docker stop

8. ##### Удалил образ через `docker rmi [image_id|repository]`, не удаляя перед этим контейнеры.
![2-9](images/image2.9.png)
> docker rmi

9. ##### Удалил остановленный контейнер.
![2-10](images/image2.10.png)
> docker rm 

10. ##### Импортировал контейнер обратно через команду *import*.
![2-11](images/image2.11.png)
> docker import

11. ##### Запустил импортированный контейнер.
![2-12](images/image2.12.png)
> docker run

12. ##### Проверил, что по адресу *localhost:80/status* отдается страничка со статусом сервера **nginx**.
![2-13](images/image2.13.png)
> localhost:80/status

## Part 3. Мини веб-сервер

1. ##### Написал мини-сервер на **C** и **FastCgi**, который будет возвращать простейшую страничку с надписью `Hello World!`.
![3-1](images/image3.1.png)
> web_server.c

2. ##### Запустил написанный мини-сервер через *spawn-fcgi* на порту 8080.
![3-2](images/image3.2.png)
> start web_server

3. ##### Написал свой *nginx.conf*, который будет проксировать все запросы с 81 порта на *127.0.0.1:8080*.
![3-3](images/image3.3.png)
> nginx.conf

4. ##### Проверил, что в браузере по *localhost:81* отдается написанная страничка.
![3-4](images/image3.4.png)
> localhost:81

5. ##### Положил файл *nginx.conf* по пути *./nginx/nginx.conf* 
![3-5](images/image3.5.png)
> docker cp nginx.conf


## Part 4. Свой докер

1. #### Написал свой докер-образ, который:
##### 1) собирает исходники мини сервера на FastCgi из [Части 3](#part-3-мини-веб-сервер);
##### 2) запускает его на 8080 порту;
##### 3) копирует внутрь образа написанный *./nginx/nginx.conf*;
##### 4) запускает **nginx**.

![4-1](images/image4.1.png)
> Dockerfile

![4-2](images/image4.2.png)
> run.sh

2. ##### Собрал написанный докер-образ через `docker build` при этом указав имя и тег.
##### Проверил через `docker images`, что все собралось корректно.
![4-3](images/image4.3.png)
> docker build & images

3. ##### Запустил собранный докер-образ с маппингом 81 порта на 80 на локальной машине и маппингом папки *./nginx* внутрь контейнера по адресу, где лежат конфигурационные файлы **nginx**'а (см. [Часть 2](#part-2-операции-с-контейнером)).
![4-4](images/image4.4.png)
> docker run

4. ##### Проверил, что по localhost:80 доступна страничка написанного мини сервера.
![4-5](images/image4.5.png)
> localhost:80

5. ##### Дописал в *./nginx/nginx.conf* проксирование странички */status*, по которой надо отдавать статус сервера **nginx**.
![4-6](images/image4.6.png)
> localhost:80/status

6. ##### Перезапустил докер-образ.
![4-7](images/image4.7.png)
> docker restart


7. ##### Проверил, что теперь по *localhost:80/status* отдается страничка со статусом **nginx**
![4-8](images/image4.8.png)
> localhost:80/status


## Part 5. **Dockle**

1. ##### Просканировал образ из предыдущего задания через `dockle [image_id|repository]`.
![5-1](images/image5.1.png)
> dockle my_nginx:1

2. ##### Исправил образ так, чтобы при проверке через **dockle** не было ошибок и предупреждений.
![5-2](images/image5.2.png)
> changed Dockerfile

![5-3](images/image5.3.png)
> dockle my_nginx:2 without errors

3. Запустил образ и проверил статус странички.

![5-4](images/image5.4.png)
> localhost:80/status


## Part 6. Базовый **Docker Compose**

1. ##### Написал файл *docker-compose.yml*, с помощью которого:
##### 1) Поднимаю докер-контейнер из [Части 5](#part-5-инструмент-dockle) _(он должен работать в локальной сети, т. е. не нужно использовать инструкцию **EXPOSE** и мапить порты на локальную машину)_.
##### 2) Поднимаю докер-контейнер с **nginx**, который будет проксировать все запросы с 8080 порта на 81 порт первого контейнера.

##### Замапил 8080 порт второго контейнера на 80 порт локальной машины.
![6-1](images/image6.1.png)
> docker-compose.yml

![6-2](images/image6.2.png)
> proxy_nginx.conf

2. ##### Остановил все запущенные контейнеры. Собрал и запустил проект с помощью команд `docker-compose build` и `docker-compose up`.
![6-3](images/image6.3.png)
> doсker compose build & up

3. ##### Проверил, что в браузере по *localhost:80* отдается написанная тобой страничка, как и ранее.
![6-4](images/image6.4.png)
> localhost:80

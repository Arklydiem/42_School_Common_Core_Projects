FROM debian:buster

RUN apt update && apt install mariadb-server mariadb-client -y \
 && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/run/mysqld && chown -R mysql:mysql /var/run/mysqld && chmod 777 /var/run/mysqld

EXPOSE 3306

COPY ./tools/mariadb.sh /usr/local/bin/
COPY ./conf/wordpress_db.sql /usr/local/bin/
RUN chmod +x /usr/local/bin/mariadb.sh
RUN chmod +x /usr/local/bin/wordpress_db.sql

ENTRYPOINT [ "/usr/local/bin/mariadb.sh" ]
CMD ["mysqld", "--bind-address=0.0.0.0"]

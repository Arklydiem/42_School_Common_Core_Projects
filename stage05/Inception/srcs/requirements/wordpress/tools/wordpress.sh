#!/bin/bash

if [ -f ./wp-config.php ]
then
	echo "Wordpress is already downloaded and configured"
else

	wget http://wordpress.org/latest.tar.gz
	tar xfz latest.tar.gz
	chown -R www-data:www-data /var/www/html/wordpress
	mv wordpress/* .
	rm -rf wordpress
	rm -rf latest.tar.gz
	sed -i "s/username_here/$MYSQL_USER/g" wp-config-sample.php
	sed -i "s/password_here/$MYSQL_PASSWORD/g" wp-config-sample.php
	sed -i "s/localhost/$MYSQL_HOSTNAME/g" wp-config-sample.php
	sed -i "s/database_name_here/$MYSQL_DATABASE/g" wp-config-sample.php
	cp wp-config-sample.php wp-config.php
fi

exec "$@"

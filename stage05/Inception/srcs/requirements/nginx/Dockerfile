FROM debian:buster

RUN apt-get update \
&& apt-get install nginx -y \
openssl

RUN mkdir /etc/nginx/ssl_cert

RUN openssl req -x509 -nodes -days 365 -newkey rsa:4096 \
	-keyout /etc/nginx/ssl_cert/argomez.key \
	-out /etc/nginx/ssl_cert/argomez.crt \
	-sha256 -subj "/C=FR/ST=FRANCE/L=ANGOULEME/O=42 ANGOULEME/OU=/argomez/CN=argomez/"

COPY ./conf/nginx.conf /etc/nginx/conf.d/

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]

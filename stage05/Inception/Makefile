
all:
	mkdir -p /home/argomez/data/mariadb /home/argomez/data/wordpress
	docker compose -f srcs/docker-compose.yml up -d

down:
	docker compose -f srcs/docker-compose.yml down

stop:
	docker stop $$(docker ps -qa)

prune:
	docker system prune --force

fclean: stop down
	-docker rm -f $$(docker ps -a -q)
	-docker rmi -f $$(docker images -a -q)
	-docker volume rm $$(docker volume ls -q)
	-docker system prune --force --all
	-docker volume prune --force
	-docker network prune --force
	-sudo rm -rf /home/argomez/data	
	

re: fclean all

.PHONY: down prune all fclean stop re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    README.md                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/15 22:15:29 by kkaman            #+#    #+#              #
#    Updated: 2025/11/15 22:37:27 by kkaman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#FT_PRINTF
Work on both mandatory and bonus section of the project

###How to use tester?
####using main.c
change the ft_printf(" ",) with your input

run bash make
cc -Wall -Wextra -Werror main.c libftprintf.a -o ft_printf
./ftprintf

run valgrind to check for memory leak
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_printf

####Tripoullie
in printfTester/Dockerfile replace with
```
FROM debian:bookworm-slim
RUN apt-get update && apt-get -y upgrade && apt-get install -y git build-essential clang valgrind \
    && mkdir /project
WORKDIR /project
```
run bash docker make command
make dockera

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 17:57:28 by hyunghki          #+#    #+#              #
#    Updated: 2024/08/28 16:51:34 by hyunghki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= miniRT
CFLAGS= -Wall -Werror -Wextra
LDFLAGS= \
-Lmlx -lmlx -framework OpenGL -framework Appkit -lm
DEBUG_FLAGS= -g3 -fsanitize=address
INCLUDE= \
-Iresources/includes \
-Imlx
SRC_DIR=resources/srcs/
SRCS= $(SRC_DIR)get_next_line/get_next_line_bonus.c \
	   $(SRC_DIR)get_next_line/get_next_line_utils_bonus.c \
	   $(SRC_DIR)utils/lst_bonus.c \
	   $(SRC_DIR)utils/memmory_bonus.c \
	   $(SRC_DIR)utils/number_bonus.c \
	   $(SRC_DIR)utils/print_bonus.c \
	   $(SRC_DIR)utils/split_bonus.c \
	   $(SRC_DIR)utils/str_bonus.c \
	   $(SRC_DIR)parse/interface_bonus.c \
	   $(SRC_DIR)parse/utils_bonus.c \
	   $(SRC_DIR)parse/mk_struct_bonus.c \
	   $(SRC_DIR)parse/mk_struct2_bonus.c \
	   $(SRC_DIR)render/interface_bonus.c \
	   $(SRC_DIR)render/print_image_bonus.c \
	   $(SRC_DIR)render/get_bump_info_bonus.c \
	   $(SRC_DIR)calculate/interface_bonus.c \
	   $(SRC_DIR)calculate/hit_chk_bonus.c \
	   $(SRC_DIR)calculate/hit_chk2_bonus.c \
	   $(SRC_DIR)calculate/u_v_color.c \
	   $(SRC_DIR)calculate/hit_chk_utils_bonus.c \
	   $(SRC_DIR)calculate/lights_bonus.c \
	   $(SRC_DIR)vector/operator_bonus.c \
	   $(SRC_DIR)vector/operator2_bonus.c \
	   $(SRC_DIR)vector/coord_cal_bonus.c \
	   $(SRC_DIR)vector/coord_cal2_bonus.c \
	   $(SRC_DIR)main_bonus.c
OBJS= $(SRCS:.c=.o)

all: $(NAME)

.PHONY: re clean fclean

re:
	make fclean
	make all

clean:
	@make clean -C mlx
	rm -f $(OBJS)

fclean:
	make clean
	rm -f $(NAME)

$(NAME): $(OBJS)
	@make -C mlx
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

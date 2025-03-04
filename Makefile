NAME = fdf

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = src/OctoLIB

FT = main \
    parsing/map_parsing parsing/check_file_name \
	algo/fdf algo/event algo/utils algo/proj\

SOURCES = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(FT)))
OBJS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(FT)))

LIB = $(LIB_DIR)/libft.a

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB) include/minilibx-linux/libmlx.a -lX11 -lXext -lm -lz

$(LIB):
	@$(MAKE) -C $(LIB_DIR)

bonus:
	$(MAKE) -C $(CHECKER_DIR)

clean:
	@$(MAKE) clean -C $(LIB_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C $(LIB_DIR)
	rm -f $(NAME)


re: fclean all

.PHONY: all clean fclean re bonus
 

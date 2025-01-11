# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 11:53:48 by abetemps          #+#    #+#              #
#    Updated: 2025/01/11 04:30:39 by abetemps         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# GENERAL SETTINGS =======================================================================
CC = cc
CFLAGS = -Wall -Werror -Wextra
PREFIX_EXE = lib
SUFFIX_EXE = .a
NAME = $(addsuffix $(SUFFIX_EXE),improved_libft)
# NAME_PRINT = $(addsuffix $(SUFFIX_EXE),imp_lib_print)
NAME_PRINT = $(addprefix $(PREFIX_EXE),imp_lib_print.a)
NAME_READ = $(addsuffix $(SUFFIX_EXE),imp_lib_read)
NAME_UTILS = $(addsuffix $(SUFFIX_EXE),imp_lib_utils)

# COMPONENTS =============================================================================
COMPONENTS :=	PRINT \
				READ \
				UTILS

# FUNCTIONS ==============================================================================
define generate_var_sources_dir
DIR_$(1) = $$(addprefix $$(DIR_SRC), $(shell echo $(1) | tr '[:upper:]' '[:lower:]')/)
endef

define generate_var_sources
SRC_$(1) = $$(addprefix $$(DIR_$(1)),$$(F_$(1)))
endef

define generate_var_objects
OBJ_$(1) = $$(patsubst %.c,%.o,$$(SRC_$(1)))
endef

# FILES ==================================================================================
F_INC = 	improved_libft.h
F_PRINT =  	ft_printf.c \
			ft_printf_utils.c
F_READ = 	get_next_line.c
F_UTILS =	ft_atoi.c \
			ft_freestr_tab.c \
			ft_isprint.c \
			ft_lstdelone.c \
			ft_lstsize.c \
			ft_memset.c \
			ft_strjoin.c \
			ft_strncmp.c \
			ft_substr.c \
			ft_bzero.c \
			ft_isalnum.c \
			ft_itoa.c \
			ft_lstiter.c \
			ft_memchr.c \
			ft_split.c \
			ft_strlcat.c \
			ft_strndup.c \
			ft_tolower.c \
			ft_calloc.c \
			ft_isalpha.c \
			ft_lstadd_back.c \
			ft_lstlast.c \
			ft_memcmp.c \
			ft_stradd.c \
			ft_strlcpy.c \
			ft_strnstr.c \
			ft_toupper.c \
			ft_count_words.c \
			ft_isascii.c \
			ft_lstadd_front.c \
			ft_lstmap.c \
			ft_memcpy.c \
			ft_strchr.c \
			ft_strlen.c \
			ft_strrchr.c \
			ft_uintlen.c \
			ft_freestr.c \
			ft_isdigit.c \
			ft_lstclear.c \
			ft_lstnew.c \
			ft_memmove.c \
			ft_striteri.c \
			ft_strmapi.c \
			ft_strtrim.c


# DIR ==================================================================================
DIR_INC = include/
DIR_SRC = src/
DIR_OBJ = obj/
$(foreach comp,$(COMPONENTS),$(eval $(call generate_var_sources_dir,$(comp))))

# INCLUDE ==============================================================================
INCLUDE = $(addprefix $(DIR_INC),$(F_INC))

# SOURCES =============================================================================
$(foreach comp,$(COMPONENTS),$(eval $(call generate_var_sources,$(comp))))


# OBJECTS =============================================================================
$(foreach comp,$(COMPONENTS),$(eval $(call generate_var_objects,$(comp))))

# RULES ===============================================================================
# versions ----------------------------------------------------------------------------
all : $(NAME)
print : $(NAME_PRINT)
read : $(NAME_READ)
utils : $(NAME_UTILS)

# objects -----------------------------------------------------------------------------
OBJECTS := $(foreach comp, $(COMPONENTS), $(OBJ_$(comp)))

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@


# make --------------------------------------------------------------------------------
$(NAME): $(OBJECTS) $(INCLUDE)
	ar rcs $(NAME) $(OBJECTS) $(INCLUDE)

$(NAME_PRINT): $(OBJ_PRINT) $(OBJ_UTILS) $(INCLUDE)
	ar rcs $(NAME_PRINT) $(OBJ_PRINT) $(OBJ_UTILS) $(INCLUDE)

$(NAME_READ): $(OBJ_READ) $(OBJ_UTILS) $(INCLUDE)
	ar rcs $(NAME_READ) $(OBJ_READ) $(OBJ_UTILS) $(INCLUDE)

$(NAME_UTILS): $(OBJ_UTILS) $(INCLUDE)
	ar rcs $(NAME_UTILS) $(OBJ_UTILS) $(INCLUDE)

clean:
	rm $(OBJECTS)

fclean: clean
	rm -f $(NAME) $(NAME_PRINT) $(NAME_READ) $(NAME_UTILS)

re: fclean all

.PHONY: all print read utils clean fclean re
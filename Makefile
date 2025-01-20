# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 11:53:48 by abetemps          #+#    #+#              #
#    Updated: 2025/01/20 12:13:50 by abetemps         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# GENERAL SETTINGS =======================================================================
CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = lib-improved.a
.SLIENT:

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
OBJ_$(1) = $$(patsubst $$(DIR_SRC)%.c,$$(DIR_OBJ)/%.o,$$(SRC_$(1)))
endef

# FILES ==================================================================================
F_INC := 	lib_improved.h
F_PRINT :=  ft_printf.c \
			ft_printf_utils.c
F_READ := 	get_next_line.c
F_UTILS :=	ft_atoi.c \
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
DIR_OBJ = $(addsuffix objects, $(DIR_SRC))
$(foreach comp,$(COMPONENTS),$(eval $(call generate_var_sources_dir,$(comp))))

# INCLUDE ==============================================================================
INCLUDE = $(addprefix $(DIR_INC),$(F_INC))

# SOURCES =============================================================================
$(foreach comp,$(COMPONENTS),$(eval $(call generate_var_sources,$(comp))))


# OBJECTS =============================================================================
$(foreach comp,$(COMPONENTS),$(eval $(call generate_var_objects,$(comp))))

OBJECTS := $(foreach comp, $(COMPONENTS), $(OBJ_$(comp)))

$(DIR_OBJ):
	mkdir -p $@

$(DIR_OBJ)/%.o: $(DIR_SRC)%.c $(DIR_INC)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -I $(DIR_INC) -o $@

# RULES ===============================================================================
# make --------------------------------------------------------------------------------
all : $(NAME)

$(NAME): $(DIR_OBJ) $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)
	@echo ✨ $(NAME) compiled ✨

clean:
	rm -rf $(DIR_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

# debug --------------------------------------------------------------------------------

print-%:
	@echo $($(patsubst print-%,%,$@))

.DEFAULT_GOAL = all

.PHONY: all print read utils clean fclean re print-%
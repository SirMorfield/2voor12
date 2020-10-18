# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: joppe <joppe@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2020/08/23 17:53:14 by joppe         #+#    #+#                  #
#    Updated: 2020/10/19 00:25:22 by joppe         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


NAME      	:= 2voor12

CC          := gcc
CFLAGS      := -Wall -Wextra -Werror -Wuninitialized

HEADERDIR	:= includes
SRCDIR      := src
BUILDDIR    := obj
SRCEXT      := c
OBJEXT      := o
LIBS		:= -I../ft_lib/includes/ -L../ft_lib/bin/ -lft

SOURCES     := $(shell find $(SRCDIR) -type f -name '*.$(SRCEXT)')
OBJECTS     := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))

$(NAME): all

all: directories $(OBJECTS)
	$(CC) $(CFLAGS) -I ${HEADERDIR}/ $(OBJECTS) -o $(NAME) ${LIBS}

clean:
	/bin/rm -rf $(BUILDDIR)/*

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

directories:
	@mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	$(CC) $(CFLAGS) -I ${HEADERDIR}/ -c $< -o $@ $(LIBS)

.PHONY: all clean fclean re directories

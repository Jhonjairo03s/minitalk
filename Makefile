# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhvalenc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/13 16:10:59 by jhvalenc          #+#    #+#              #
#    Updated: 2025/05/13 18:01:53 by jhvalenc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre de los ejecutables
NAME_SERVER = server
NAME_CLIENT = client

# Compilador y flags
CC = cc
CFLAGS = -Wall -Werror -Wextra
# CFLAGS += -g # Para depuración

# Directorio y nombre de la librería ft_printf
# AJUSTA 'libftprintf.a' si tu librería ft_printf tiene otro nombre (e.g., ft_printf.a)
PRINTF_DIR = ./ft_printf
PRINTF_LIB_NAME = libftprintf.a # O el nombre que genere tu Makefile de ft_printf
PRINTF_LIB = $(PRINTF_DIR)/$(PRINTF_LIB_NAME)
# Flags para incluir la cabecera de ft_printf y enlazar la librería
PRINTF_CFLAGS = -I$(PRINTF_DIR)
PRINTF_LFLAGS = -L$(PRINTF_DIR) -lftprintf # AJUSTA '-lftprintf' si el nombre de la lib es diferente (e.g. -lft si es libft.a)

# Archivos fuente de Minitalk
SRCS_SERVER = server.c
SRCS_CLIENT = client.c
SRCS_UTILS = ft_atoi.c # ft_atoi sigue siendo parte de Minitalk directamente

# Archivos de cabecera de Minitalk (ft_printf.h se maneja con PRINTF_CFLAGS)
HEADERS = minitalk.h

# Archivos objeto de Minitalk
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_UTILS = $(SRCS_UTILS:.c=.o)

# Comando para eliminar archivos
RM = rm -f

# Regla principal: Compila la librería ft_printf y luego los ejecutables de Minitalk
all: $(PRINTF_LIB) $(NAME_SERVER) $(NAME_CLIENT)

# Regla para compilar la librería ft_printf
# Llama al Makefile dentro del directorio ft_printf
$(PRINTF_LIB):
	@echo "Compilando la librería ft_printf..."
	@$(MAKE) -C $(PRINTF_DIR)

# Regla para crear el ejecutable del servidor
$(NAME_SERVER): $(OBJS_SERVER) $(PRINTF_LIB) # Depende de la librería ft_printf
	$(CC) $(CFLAGS) $(OBJS_SERVER) -o $(NAME_SERVER) $(PRINTF_LFLAGS)
	@echo "Servidor [$(NAME_SERVER)] compilado y enlazado con ft_printf!"

# Regla para crear el ejecutable del cliente
$(NAME_CLIENT): $(OBJS_CLIENT) $(OBJS_UTILS) $(PRINTF_LIB) # Depende de la librería ft_printf
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(OBJS_UTILS) -o $(NAME_CLIENT) $(PRINTF_LFLAGS)
	@echo "Cliente [$(NAME_CLIENT)] compilado y enlazado con ft_printf!"

# Reglas de compilación para los .c de Minitalk (server, client, utils)
# %.o: %.c $(HEADERS) -> $(HEADERS) incluye minitalk.h que incluye ft_printf/ft_printf.h
# Por lo tanto, necesitamos $(PRINTF_CFLAGS) para que el compilador encuentre ft_printf/ft_printf.h
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(PRINTF_CFLAGS) -c $< -o $@

# Regla para limpiar archivos objeto de Minitalk
clean:
	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_UTILS)
	@echo "Archivos objeto de Minitalk (.o) eliminados."
	@echo "Limpiando la librería ft_printf..."
	@$(MAKE) -C $(PRINTF_DIR) clean # Llama a 'clean' en el Makefile de ft_printf

# Regla para limpiar todo (objetos y ejecutables de Minitalk y ft_printf)
fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)
	@echo "Ejecutables de Minitalk eliminados."
	@echo "Limpieza profunda de la librería ft_printf..."
	@$(MAKE) -C $(PRINTF_DIR) fclean # Llama a 'fclean' en el Makefile de ft_printf
	# Si tu Makefile de ft_printf no elimina la librería con fclean,
	# podrías añadir $(RM) $(PRINTF_LIB) aquí.

# Regla para recompilar todo
re: fclean all

.PHONY: all clean fclean re $(PRINTF_LIB)

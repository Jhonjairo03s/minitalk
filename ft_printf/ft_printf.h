/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:49:45 by jhvalenc          #+#    #+#             */
/*   Updated: 2025/02/17 12:57:27 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

int				ft_printf(const char *format, ...);
char			*ft_itoa(int n);
char			*ft_itoa_unsigned(unsigned int n);
char			*ft_itoa_hex_min(unsigned int n);
char			*ft_itoa_hex_may(unsigned int n);
char			*ft_itoa_ptr(unsigned long long int n);
size_t			ft_strlen(const char *str);
int				ft_print_decimal_int(int d);
int				ft_print_hex_lower(unsigned int x);
int				ft_print_hex_upper(unsigned int X);
int				ft_print_int(int i);
int				ft_print_pointer(void *p);
int				ft_print_string(char *str);
int				ft_print_unsigned_int(unsigned int u);
int				ft_print_char(int ch);

#endif

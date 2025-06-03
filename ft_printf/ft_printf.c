/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:49:04 by jhvalenc          #+#    #+#             */
/*   Updated: 2025/02/20 17:48:28 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_chars(const char *format, int counter, va_list args)
{
	int				printed_chars;
	char			ch;
	char			*str;

	printed_chars = 0;
	if (format[counter] == 'c')
	{
		ch = va_arg(args, int);
		printed_chars += ft_print_char(ch);
	}
	else if (format[counter] == 's')
	{
		str = va_arg(args, char *);
		printed_chars += ft_print_string(str);
	}
	return (printed_chars);
}

static int	ft_handle_ints(const char *format, int counter, va_list args)
{
	int				printed_chars;
	int				d;
	int				i;
	unsigned int	u;

	printed_chars = 0;
	if (format[counter] == 'd')
	{
		d = va_arg(args, int);
		printed_chars += ft_print_decimal_int(d);
	}
	else if (format[counter] == 'i')
	{
		i = va_arg(args, int);
		printed_chars += ft_print_int(i);
	}
	else if (format[counter] == 'u')
	{
		u = va_arg(args, unsigned int);
		printed_chars += ft_print_unsigned_int(u);
	}
	return (printed_chars);
}

static int	ft_handle_hex(const char *format, int counter, va_list args)
{
	int				printed_chars;
	unsigned int	x;

	printed_chars = 0;
	if (format[counter] == 'x')
	{
		x = va_arg(args, unsigned int);
		printed_chars += ft_print_hex_lower(x);
	}
	else if (format[counter] == 'X')
	{
		x = va_arg(args, unsigned int);
		printed_chars += ft_print_hex_upper(x);
	}
	return (printed_chars);
}

static int	ft_handle_ptr(const char *format, int counter, va_list args)
{
	int				printed_chars;
	void			*p;

	printed_chars = 0;
	if (format[counter] == 'p')
	{
		p = va_arg(args, void *);
		printed_chars += ft_print_pointer(p);
	}
	else if (format[counter] == '%')
	{
		printed_chars += write(1, "%", 1);
	}
	return (printed_chars);
}

int	ft_printf(const char *format, ...)
{
	int				counter;
	int				printed_chars;
	va_list			args;

	counter = 0;
	printed_chars = 0;
	va_start(args, format);
	while (format[counter] != '\0')
	{
		if (format[counter] == '%')
		{
			counter++;
			printed_chars += ft_handle_chars(format, counter, args);
			printed_chars += ft_handle_ints(format, counter, args);
			printed_chars += ft_handle_hex(format, counter, args);
			printed_chars += ft_handle_ptr(format, counter, args);
		}
		else
		{
			printed_chars += write(1, &format[counter], 1);
		}
		counter++;
	}
	va_end(args);
	return (printed_chars);
}

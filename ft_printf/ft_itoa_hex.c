/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:14:04 by jhvalenc          #+#    #+#             */
/*   Updated: 2024/12/24 12:42:17 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	count_digits(long long int n)
{
	size_t				count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		count++;
		n = n / 16;
	}
	return (count);
}

static void	fill_string_min(char *str, long long int n, size_t length)
{
	int	digit;

	if (n == 0)
	{
		str[0] = '0';
		return ;
	}
	while (n > 0)
	{
		digit = n % 16;
		if (digit < 10)
			str[--length] = digit + '0';
		else
			str[--length] = digit - 10 + 'a';
		n = n / 16;
	}
}

static void	fill_string_may(char *str, long long int n, size_t length)
{
	int	digit;

	if (n == 0)
	{
		str[0] = '0';
		return ;
	}
	while (n > 0)
	{
		digit = n % 16;
		if (digit < 10)
			str[--length] = digit + '0';
		else
			str[--length] = digit - 10 + 'A';
		n = n / 16;
	}
}

char	*ft_itoa_hex_min(unsigned int n)
{
	size_t				length;
	char				*str;
	long long int		ln;

	ln = n;
	length = count_digits(ln);
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (str == NULL)
	{
		return (NULL);
	}
	str[length] = '\0';
	fill_string_min(str, ln, length);
	return (str);
}

char	*ft_itoa_hex_may(unsigned int n)
{
	size_t				length;
	char				*str;
	long long int		ln;

	ln = n;
	length = count_digits(ln);
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (str == NULL)
	{
		return (NULL);
	}
	str[length] = '\0';
	fill_string_may(str, ln, length);
	return (str);
}

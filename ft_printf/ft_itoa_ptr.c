/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:01:47 by jhvalenc          #+#    #+#             */
/*   Updated: 2025/02/17 19:09:22 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	count_digits(unsigned long long int n)
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

static void	fill_string(char *str, unsigned long long int n, size_t length)
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
	str[0] = '0';
	str[1] = 'x';
}

char	*ft_itoa_ptr(unsigned long long int n)
{
	size_t					length;
	char					*str;
	unsigned long long int	ln;

	ln = n;
	length = count_digits(ln);
	str = (char *)malloc(sizeof(char) * (length + 6));
	if (str == NULL)
		return (NULL);
	str[length + 2] = '\0';
	if (n == 0)
	{
		str[0] = '(';
		str[1] = 'n';
		str[2] = 'i';
		str[3] = 'l';
		str[4] = ')';
		str[5] = '\0';
		return (str);
	}
	fill_string(str, n, length + 2);
	return (str);
}

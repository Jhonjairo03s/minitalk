/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:52:25 by jhvalenc          #+#    #+#             */
/*   Updated: 2024/12/24 12:24:21 by jhvalenc         ###   ########.fr       */
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
		n = n / 10;
	}
	return (count);
}

static void	fill_string(char *str, long long int n, size_t length)
{
	if (n == 0)
	{
		str[0] = '0';
		return ;
	}
	while (n > 0)
	{
		str[--length] = (n % 10) + '0';
		n = n / 10;
	}
}

char	*ft_itoa_unsigned(unsigned int n)
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
	fill_string(str, ln, length);
	return (str);
}

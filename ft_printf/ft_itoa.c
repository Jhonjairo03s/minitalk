/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:43:19 by jhvalenc          #+#    #+#             */
/*   Updated: 2025/02/20 17:49:05 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	count_digits(int n)
{
	size_t				count;
	long long int		ln;

	count = 0;
	ln = n;
	if (ln == 0)
		return (1);
	if (ln < 0)
	{
		count++;
		ln = -ln;
	}
	while (ln > 0)
	{
		count++;
		ln = ln / 10;
	}
	return (count);
}

static void	fill_string(char *str, long long int ln, size_t length)
{
	if (ln == 0)
	{
		str[0] = '0';
		return ;
	}
	if (ln < 0)
	{
		str[0] = '-';
		ln = -ln;
	}
	while (ln > 0)
	{
		str[--length] = (ln % 10) + '0';
		ln = ln / 10;
	}
}

char	*ft_itoa(int n)
{
	size_t				length;
	char				*str;
	long long int		ln;

	length = count_digits(n);
	ln = n;
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (str == NULL)
		return (NULL);
	str[length] = '\0';
	fill_string(str, ln, length);
	return (str);
}

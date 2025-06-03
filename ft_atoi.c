/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:01:17 by jhvalenc          #+#    #+#             */
/*   Updated: 2024/12/17 12:22:44 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int		sing;
	int		result;
	size_t	counter;

	sing = 1;
	result = 0;
	counter = 0;
	while (str[counter] == ' ' || str[counter] == '\t'
		|| str[counter] == '\n' || str[counter] == '\r'
		|| str[counter] == '\v' || str[counter] == '\f')
		counter++;
	if (str[counter] == '-')
	{
		sing = -1;
		counter++;
	}
	else if (str[counter] == '+')
		counter++;
	while (str[counter] >= '0' && str[counter] <= '9')
	{
		result = result * 10 + (str[counter] - '0');
		counter++;
	}
	return (sing * result);
}

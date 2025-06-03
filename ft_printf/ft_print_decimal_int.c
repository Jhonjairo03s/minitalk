/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:30:06 by jhvalenc          #+#    #+#             */
/*   Updated: 2024/12/26 16:11:31 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_decimal_int(int d)
{
	int				printed_chars;
	char			*str;

	printed_chars = 0;
	str = ft_itoa(d);
	printed_chars = printed_chars + write(1, str, ft_strlen(str));
	free(str);
	return (printed_chars);
}

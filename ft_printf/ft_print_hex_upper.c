/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:05:48 by jhvalenc          #+#    #+#             */
/*   Updated: 2024/12/26 16:12:50 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_upper(unsigned int X)
{
	int				printed_chars;
	char			*str;

	printed_chars = 0;
	str = ft_itoa_hex_may(X);
	printed_chars = printed_chars + write(1, str, ft_strlen(str));
	free(str);
	return (printed_chars);
}

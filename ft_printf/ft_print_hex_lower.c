/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_lower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:57:20 by jhvalenc          #+#    #+#             */
/*   Updated: 2025/02/13 17:50:57 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_lower(unsigned int x)
{
	int				printed_chars;
	char			*str;

	printed_chars = 0;
	str = ft_itoa_hex_min(x);
	printed_chars = printed_chars + write(1, str, ft_strlen(str));
	free(str);
	return (printed_chars);
}

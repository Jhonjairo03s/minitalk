/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:16:04 by jhvalenc          #+#    #+#             */
/*   Updated: 2025/02/07 16:50:30 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *str)
{
	int	printed_chars;

	if (str == NULL)
	{
		return (ft_print_string("(null)"));
	}
	printed_chars = 0;
	printed_chars = printed_chars + write(1, str, ft_strlen(str));
	return (printed_chars);
}

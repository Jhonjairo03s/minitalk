/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:55:58 by jhvalenc          #+#    #+#             */
/*   Updated: 2024/12/24 15:15:14 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int ch)
{
	int	printed_chars;

	printed_chars = 0;
	printed_chars = printed_chars + write(1, &ch, 1);
	return (1);
}

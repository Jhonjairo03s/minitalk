/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:40:46 by jhvalenc          #+#    #+#             */
/*   Updated: 2024/12/26 16:13:24 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int i)
{
	int				printed_chars;
	char			*str;

	printed_chars = 0;
	str = ft_itoa(i);
	printed_chars = printed_chars + write(1, str, ft_strlen(str));
	free(str);
	return (printed_chars);
}

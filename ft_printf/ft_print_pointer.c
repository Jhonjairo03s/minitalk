/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:10:43 by jhvalenc          #+#    #+#             */
/*   Updated: 2024/12/26 16:13:54 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(void *p)
{
	int				printed_chars;
	char			*str;

	printed_chars = 0;
	str = ft_itoa_ptr((unsigned long long int)p);
	printed_chars = printed_chars + write(1, str, ft_strlen(str));
	free(str);
	return (printed_chars);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:01:08 by jhvalenc          #+#    #+#             */
/*   Updated: 2025/05/14 13:59:32 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <sys/types.h>

# include "ft_printf/ft_printf.h"

# define MAX_MESSAGE_LEN 1024

typedef struct s_server_state
{
	unsigned char	current_char;
	int				bits_received;
	char			message_buffer[MAX_MESSAGE_LEN + 1];
	int				buffer_index;
}	t_server_state;

void	send_char(pid_t server_pid, char c);
void	handle_signal(int sign, siginfo_t *info, void *context);
int		ft_atoi(const char *str);

#endif

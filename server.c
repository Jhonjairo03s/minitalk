/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:16:19 by jhvalenc          #+#    #+#             */
/*   Updated: 2025/05/14 14:17:08 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	print_and_reset_buffer(t_server_state *state)
{
	ft_printf("%s\n", state->message_buffer);
	state->buffer_index = 0;
	if (MAX_MESSAGE_LEN > 0)
	{
		state->message_buffer[0] = '\0';
	}
}

static void	process_received_char(t_server_state *state)
{
	if (state->buffer_index < MAX_MESSAGE_LEN)
	{
		state->message_buffer[state->buffer_index] = state->current_char;
		state->buffer_index++;
	}
	if (state->current_char == '\0' || state->buffer_index == MAX_MESSAGE_LEN)
	{
		if (state->buffer_index == MAX_MESSAGE_LEN && \
			state->message_buffer[MAX_MESSAGE_LEN - 1] != '\0')
			state->message_buffer[MAX_MESSAGE_LEN] = '\0';
		print_and_reset_buffer(state);
	}
}

static void	send_ack(pid_t client_pid)
{
	if (client_pid > 0)
	{
		if (kill(client_pid, SIGUSR1) == -1)
		{
			perror("Servidor: Error al enviar ACK SIGUSR1 al cliente");
		}
	}
}

void	handle_signal(int sign, siginfo_t *info, void *context)
{
	static t_server_state	state = {0, 0, {0}, 0};
	pid_t					client_pid;

	(void)context;
	client_pid = info->si_pid;
	state.current_char = state.current_char << 1;
	if (sign == SIGUSR2)
	{
		state.current_char = state.current_char | 1;
	}
	state.bits_received++;
	if (state.bits_received == 8)
	{
		process_received_char(&state);
		state.bits_received = 0;
	}
	send_ack(client_pid);
}

int	main(void)
{
	pid_t				pid_server;
	struct sigaction	sa_serv;

	pid_server = getpid();
	ft_printf("Servidor PID: %d\n", pid_server);
	sa_serv.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa_serv.sa_mask);
	sa_serv.sa_sigaction = handle_signal;
	if (sigaction(SIGUSR1, &sa_serv, NULL) == -1)
	{
		perror("Error al registrar SIGUSR1 en servidor");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa_serv, NULL) == -1)
	{
		perror("Error al registrar SIGUSR2 en servidor");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		pause();
	}
	return (0);
}

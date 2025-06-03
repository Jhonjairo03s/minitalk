/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:47:16 by jhvalenc          #+#    #+#             */
/*   Updated: 2025/05/15 15:49:51 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_ack_received = 0;

static void	ack_handler(int sign)
{
	(void)sign;
	g_ack_received = 1;
}

static void	ft_send_bit_and_wait_ack(pid_t server_pid, int signal_for_data_bit)
{
	int	timeout_counter;

	g_ack_received = 0;
	if (kill(server_pid, signal_for_data_bit) == -1)
	{
		if (signal_for_data_bit == SIGUSR1)
			perror("Cliente: Error al enviar bit de datos SIGUSR1");
		else
			perror("Cliente: Error al enviar bit de datos SIGUSR2");
		exit(EXIT_FAILURE);
	}
	timeout_counter = 0;
	while (g_ack_received == 0 && timeout_counter < 1000000)
	{
		pause();
		timeout_counter++;
	}
	if (g_ack_received == 0)
	{
		ft_printf("Cliente: No se recibió ACK del servidor. Timeout.\n");
		exit(EXIT_FAILURE);
	}
}

void	send_char(pid_t server_pid, char c)
{
	int				bit_index;
	unsigned char	bit_to_send;

	bit_index = 7;
	while (bit_index >= 0)
	{
		bit_to_send = (c >> bit_index) & 1;
		if (bit_to_send == 0)
		{
			ft_send_bit_and_wait_ack(server_pid, SIGUSR1);
		}
		else
		{
			ft_send_bit_and_wait_ack(server_pid, SIGUSR2);
		}
		bit_index--;
	}
}

static void	validate_arguments(int argc, char **argv, pid_t *server_pid)
{
	if (argc != 3)
	{
		ft_printf("Uso: %s <PID_Servidor> <Mensaje>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	*server_pid = ft_atoi(argv[1]);
	if (*server_pid <= 0)
	{
		ft_printf("Error: PID del servidor no valido.\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	char				*message_to_send;
	int					char_idx;
	struct sigaction	sa_client_ack;

	sa_client_ack.sa_handler = ack_handler;
	sa_client_ack.sa_flags = SA_RESTART;
	sigemptyset(&sa_client_ack.sa_mask);
	if (sigaction(SIGUSR1, &sa_client_ack, NULL) == -1)
	{
		perror("Cliente: Error al registrar el manejador de ACK (SIGUSR1)");
		exit(EXIT_FAILURE);
	}
	validate_arguments(argc, argv, &server_pid);
	message_to_send = argv[2];
	char_idx = 0;
	while (message_to_send[char_idx] != '\0')
	{
		send_char(server_pid, message_to_send[char_idx]);
		char_idx++;
	}
	send_char(server_pid, '\0');
	return (0);
}

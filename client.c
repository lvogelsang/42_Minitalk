/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:20:48 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/19 11:01:27 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		ft_printf("Error! Did you mean: ./client [pid] ['message']?\n");
	else
	{
		pid = ft_atoi(argv[1]);
		if (pid == 0)
			ft_printf("Error! Bad PID!\n");
		else
			send_bit(pid, argv[2], ft_strlen(argv[2]));
	}
	return (0);
}

void	send_bit(int pid, char *message, int len)
{
	int	i;
	int	shift;
	
	i = 0;
	while (i <= len)
	{
		shift = 7;
		while (shift >= 0)
		{
			if ((message[i] >> shift) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			shift--;
		}
		i++;
	}
}

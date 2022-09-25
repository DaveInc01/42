/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmkhitar <dmkhitar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 22:26:59 by dmkhitar          #+#    #+#             */
/*   Updated: 2022/09/22 23:23:14 by dmkhitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handler(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static int	i;

	(void)context;
	if (sig == SIGUSR1)
		c = c | 1;
	if (++i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
		kill(info->si_pid, SIGUSR1);
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	sig_flags;

	sig_flags.sa_sigaction = handler;
	sig_flags.sa_flags = SA_SIGINFO;
	sig_flags.sa_flags = SA_RESTART;
	ft_printf("%d\n", getpid());
	sigaction(SIGUSR1, &sig_flags, 0);
	sigaction(SIGUSR2, &sig_flags, 0);
	while (1)
		;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmkhitar <dmkhitar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:04:28 by dmkhitar          #+#    #+#             */
/*   Updated: 2022/09/22 23:11:30 by dmkhitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	g_strlength;

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	sigsending(char *str, int pid)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 7;
		while (j >= 0)
		{
			if ((str[i] >> j & 1))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			j--;
		}
		i++;
	}
}

static void	handler(int sig, siginfo_t *info, void *context)
{
	static int	i;

	(void)context;
	(void)*info;
	(void)sig;
	if (++i == g_strlength)
	{
		write(1, "The signal is received\n", 24);
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sig_flags;
	char				*str;
	int					pid;

	pid = atoi(argv[1]);
	sig_flags.sa_sigaction = handler;
	sig_flags.sa_flags = SA_SIGINFO;
	sig_flags.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sig_flags, 0);
	if (argc == 3)
	{
		str = argv[2];
		g_strlength = ft_strlen(str);
		sigsending(str, pid);
	}
	else
		write(1, "Error: check the arguments count", 33);
	while (1)
		;
}

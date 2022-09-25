/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdecimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmkhitar <dmkhitar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:33:37 by dmkhitar          #+#    #+#             */
/*   Updated: 2022/09/21 21:54:15 by dmkhitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_printnum(int num, int *count)
{
	long int	n;

	n = num;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		(*count)++;
		n = n * (-1);
	}
	if (n < 10)
	{
		ft_putchar_fd(n + '0', 1);
		(*count)++;
	}
	else
	{
		ft_printnum(n / 10, count);
		ft_putchar_fd(n % 10 + '0', 1);
		(*count)++;
	}
}

int	ft_printdecimal(int num)
{
	int	count;

	count = 0;
	ft_printnum(num, &count);
	return (count);
}

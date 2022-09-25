/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmkhitar <dmkhitar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:33:18 by dmkhitar          #+#    #+#             */
/*   Updated: 2022/09/21 21:50:39 by dmkhitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_type_exists(char char_arg)
{
	const char	*types;
	int			i;

	types = "cspdiuxX";
	i = 0;
	while (types[i])
	{
		if (types[i] == char_arg)
			return (1);
		i++;
	}
	return (0);
}

int	print_data(char char_arg, va_list ap, int *i, int *count)
{
	if (char_arg == 'd' || char_arg == 'i')
		(*count) += ft_printdecimal(va_arg(ap, int));
	if (char_arg == '%')
		(*i)++;
	if (is_type_exists(char_arg))
	{
		(*i)++;
		return (1);
	}
	else
		(*i)--;
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	ap;

	count = 0;
	i = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (print_data(s[++i], ap, &i, &count))
				continue ;
		}
		if (s[i] == '\0')
			return (count);
		if (s[i])
		{
			write(1, &s[i], 1);
			count++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}

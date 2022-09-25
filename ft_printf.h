/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmkhitar <dmkhitar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:34:06 by dmkhitar          #+#    #+#             */
/*   Updated: 2022/09/21 19:01:50 by dmkhitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdio.h>
# include <signal.h>

int		count_len(unsigned int num);
char	*ft_itoa(int n);
int		ft_printadress(void *ptr);
int		ft_printchar(char c);
int		ft_printdecimal(int num);
int		is_type_exists(char char_arg);
int		print_data(char char_arg, va_list ap, int *i, int *count);
int		ft_printf(const char *s, ...);
int		ft_printlowhex(unsigned int num);
int		ft_printstr(char *s);
void	ft_putnbr_fd(int n, int fd);
int		ft_printunsigned(unsigned int num);
int		ft_printuphex(unsigned int num);
void	ft_putchar_fd(char c, int fd);

#endif

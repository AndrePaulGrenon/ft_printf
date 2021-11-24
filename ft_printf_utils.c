/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:46:51 by agrenon           #+#    #+#             */
/*   Updated: 2021/11/24 16:47:06 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(char c)
{
	write(1, &c, 1);
	return ;
}

int	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (5);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i - 1);
}

void	ft_putnbr(int n, int *more)
{
	if (n == INT_MIN)
	{
		*more = *more + ft_putstr("-2147483648") + 1;
		return ;
	}
	if (n < 0)
	{
		ft_print_char('-');
		n = n * -1;
		*more = *more + 1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, more);
		n = n % 10;
	}
	if (n < 10)
	{
		ft_print_char(n + 48);
		*more = *more + 1;
	}
	return ;
}

int	ft_put_unsigned(unsigned int n, int *more)
{
	if (n >= 10)
	{
		(void) ft_put_unsigned(n / 10, more);
		n = n % 10;
	}
	if (n < 10)
	{
		ft_print_char(n + 48);
		*more = *more + 1;
	}
	return (0);
}

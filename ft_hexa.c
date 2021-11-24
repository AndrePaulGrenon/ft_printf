/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:42:11 by agrenon           #+#    #+#             */
/*   Updated: 2021/11/24 16:42:14 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_make_hexa(unsigned int n, int *more)
{
	if (n == 0)
		return ;
	if (n >= 1)
	{
		ft_make_hexa(n / 16, more);
		n = n % 16;
	}
	if (n < 16)
	{
		if (n < 10)
			ft_print_char(n + 48);
		else if (n >= 10)
			ft_print_char(n + 87);
		*more = *more + 1;
	}
	return ;
}

static void	ft_make_hexa_upper(unsigned int n, int *more)
{
	if (n == 0)
		return ;
	if (n >= 1)
	{
		ft_make_hexa_upper(n / 16, more);
		n = n % 16;
	}
	if (n < 16)
	{
		if (n < 10)
			ft_print_char(n + 48);
		else if (n >= 10)
			ft_print_char(n + 55);
		*more = *more + 1;
	}
	return ;
}

void	ft_make_adress(unsigned long n, int *more)
{
	if (n == 0)
		return ;
	if (n >= 1)
	{
		ft_make_adress(n / 16, more);
		n = n % 16;
	}
	if (n < 16)
	{
		if (n < 10)
			ft_print_char(n + 48);
		else if (n >= 10)
			ft_print_char(n + 87);
		*more = *more + 1;
	}
	return ;
}

void	ft_hexa(unsigned int n, int *more, bool upper)
{
	if (n == 0)
		ft_print_char(n + 48);
	else if (upper == false)
	{
		ft_make_hexa(n, more);
		*more = *more - 1;
	}
	else if (upper == true)
	{
		ft_make_hexa_upper(n, more);
		*more = *more - 1;
	}
	return ;
}

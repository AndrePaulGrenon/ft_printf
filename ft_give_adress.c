/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_adress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:36:59 by agrenon           #+#    #+#             */
/*   Updated: 2021/11/24 16:39:29 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_give_adress(unsigned long n, int *more)
{
	ft_print_char('0');
	ft_print_char('x');
	*more = *more + 2;
	if (n == 0)
		ft_print_char(n + 48);
	else
	{
		ft_make_adress(n, more);
		*more = *more - 1;
	}
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:45:02 by agrenon           #+#    #+#             */
/*   Updated: 2021/11/24 16:45:04 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_choose_flag(char c, va_list *new_arg, int *more)
{
	*more = *more - 1;
	if (c == 's')
		*more = *more + ft_putstr(va_arg(*new_arg, char *));
	else if (c == 'c')
		ft_print_char(va_arg(*new_arg, int));
	else if (c == 'i' || c == 'd')
	{
		ft_putnbr(va_arg(*new_arg, int), more);
		*more = *more -1;
	}
	else if (c == '%')
		ft_print_char('%');
	else if (c == 'u')
	{
		ft_put_unsigned(va_arg(*new_arg, unsigned int), more);
		*more = *more -1;
	}
	else if (c == 'x')
		ft_hexa(va_arg(*new_arg, unsigned long), more, false);
	else if (c == 'X')
		ft_hexa(va_arg(*new_arg, unsigned long), more, true);
	else if (c == 'p')
		ft_give_adress(va_arg(*new_arg, unsigned long), more);
	return (0);
}

int	ft_printf(const char *my_str, ...)
{
	bool	percent;
	int		i;
	int		more;
	va_list	args;

	percent = false;
	i = 0;
	more = 0;
	va_start(args, my_str);
	while (my_str[i])
	{
		if (my_str[i - 1] == '%' && percent == true)
		{
			ft_choose_flag(my_str[i], &args, &more);
			percent = false;
		}
		else if (my_str[i] != '%')
			ft_print_char(my_str[i]);
		else
			percent = true;
		i++;
	}
	va_end(args);
	return (i + more);
}

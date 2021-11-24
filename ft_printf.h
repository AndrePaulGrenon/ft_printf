/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:53:10 by agrenon           #+#    #+#             */
/*   Updated: 2021/11/24 17:00:49 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

void	ft_print_char(char c);
int		ft_putstr(const char *s);
void	ft_putnbr(int n, int *more);
int		ft_put_unsigned(unsigned int n, int *more);
void	ft_hexa(unsigned int n, int *more, bool upper);
void	ft_make_adress(unsigned long n, int *more);
void	ft_give_adress(unsigned long n, int *more);
int		ft_printf(const char *my_str, ...);

#endif 

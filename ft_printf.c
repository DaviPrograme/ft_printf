/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:20:48 by dmoreira          #+#    #+#             */
/*   Updated: 2020/04/25 20:00:54 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_param	*g_param;

int			ft_printf(const char *pnt, ...)
{
	int		num;
	int		chars;
	va_list	ap;

	num = cont_flags(pnt);
	if (num > 0)
	{
		if (!(ft_newparam(num)))
			return (-1);
	}
	if (num == 0)
	{
		ft_putstr_fd((char *)pnt, 1);
		return (ft_strlen(pnt));
	}
	fill_struct(pnt, num, ft_strlen(pnt));
	va_start(ap, pnt);
	value_asterisk(pnt, ap, num);
	va_end(ap);
	options_struct(pnt, 0, -1);
	final_reading(pnt);
	chars = count_chars(pnt, num);
	free_struct(num);
	return (chars);
}

void		free_struct(int num)
{
	char	let;
	int		cont;

	cont = 0;
	while (cont < num)
	{
		let = g_param[cont].type;
		if (let != 's' || (let == 's' && g_param[cont].perc == 'N'))
			free(g_param[cont].result);
		++cont;
	}
	free(g_param);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 15:24:05 by davi              #+#    #+#             */
/*   Updated: 2020/04/24 00:49:29 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

extern t_param *g_param;

char		*put_p(size_t num)
{
	char	*ptr;
	size_t	cont;
	size_t	aux;

	cont = 2;
	if (!(ptr = aloc_p(num)))
		return (ptr);
	while (num >= 16)
	{
		ptr[cont] = alphanum_low16((num % 16));
		++cont;
		num /= 16;
	}
	ptr[cont] = alphanum_low16(num);
	num = 2;
	while (cont > num)
	{
		aux = ptr[num];
		ptr[num] = ptr[cont];
		ptr[cont] = aux;
		--cont;
		++num;
	}
	return (ptr);
}

char		*aloc_p(size_t n)
{
	int		cont;
	char	*ptr;

	cont = 0;
	while (n >= 16)
	{
		n /= 16;
		++cont;
	}
	if (!(ptr = (char *)ft_calloc((cont + 4), sizeof(char))))
		return (NULL);
	ptr[0] = '0';
	ptr[1] = 'x';
	return (ptr);
}

void		case3_p(int wdh, int pos)
{
	char	chr;

	chr = g_param[pos].result[2];
	if (chr != '0')
	{
		if (g_param[pos].left > -1)
			ft_putstr_fd(g_param[pos].result, 1);
		wdh -= (ft_strlen(g_param[pos].result));
		while (--wdh >= 2)
			ft_putchar_fd(' ', 1);
		if (g_param[pos].left == -1)
			ft_putstr_fd(g_param[pos].result, 1);
	}
	else if (chr == '0')
	{
		g_param[pos].result[2] = 0;
		if (g_param[pos].left > -1)
			ft_putstr_fd(g_param[pos].result, 1);
		while (--wdh >= 2)
			ft_putchar_fd(' ', 1);
		if (g_param[pos].left == -1)
			ft_putstr_fd(g_param[pos].result, 1);
	}
}

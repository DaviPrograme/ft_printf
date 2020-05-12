/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_reading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 14:06:29 by davi              #+#    #+#             */
/*   Updated: 2020/04/17 14:48:56 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

extern t_param *g_param;

void	final_reading(const char *ptr)
{
	int	con;
	int	pos;

	con = -1;
	pos = 0;
	while (ptr[++con])
	{
		if (ptr[con] == '%')
		{
			(g_param[pos].type == '%') ? put_percent(pos) : 0;
			(g_param[pos].type == 'd') ? put_di(pos) : 0;
			(g_param[pos].type == 'i') ? put_di(pos) : 0;
			(g_param[pos].type == 'c') ? put_char(pos) : 0;
			(g_param[pos].type == 's') ? put_string(pos) : 0;
			(g_param[pos].type == 'u') ? put_uint(pos) : 0;
			(g_param[pos].type == 'p') ? put_uint(pos) : 0;
			(g_param[pos].type == 'X') ? put_uint(pos) : 0;
			(g_param[pos].type == 'x') ? put_uint(pos) : 0;
			con += g_param[pos].qtd_char;
			++pos;
		}
		else
			ft_putchar_fd(ptr[con], 1);
	}
}

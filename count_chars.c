/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 16:03:34 by davi              #+#    #+#             */
/*   Updated: 2020/04/25 19:52:36 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

extern		t_param *g_param;

int		count_chars(const char *pnt, int max_pos)
{
	int	qtd;
	int	pos;

	pos = 0;
	qtd = ft_strlen(pnt);
	while (pos < max_pos)
	{
		if ((ver_char(g_param[pos].type)))
		{
			(g_param[pos].type == 'd') ? qtd += count_di(pos) : 0;
			(g_param[pos].type == 'i') ? qtd += count_di(pos) : 0;
			(g_param[pos].type == '%') ? qtd += count_percent(pos) : 0;
			(g_param[pos].type == 'c') ? qtd += count_pchar(pos) : 0;
			(g_param[pos].type == 's') ? qtd += count_string(pos) : 0;
			(g_param[pos].type == 'u') ? qtd += count_uint(pos) : 0;
			(g_param[pos].type == 'x') ? qtd += count_uint(pos) : 0;
			(g_param[pos].type == 'X') ? qtd += count_uint(pos) : 0;
			(g_param[pos].type == 'p') ? qtd += count_uint(pos) : 0;
		}
		else
			qtd -= (g_param[pos].qtd_char + 1);
		++pos;
	}
	return (qtd);
}

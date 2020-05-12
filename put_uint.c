/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_uint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 15:51:27 by davi              #+#    #+#             */
/*   Updated: 2020/04/24 01:03:35 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

extern t_param *g_param;

void		put_uint(int pos)
{
	int		prec;
	int		wdh;
	int		str;
	char	chr;

	prec = -1;
	wdh = -1;
	chr = g_param[pos].result[0];
	str = (int)ft_strlen((const char *)g_param[pos].result);
	(g_param[pos].wdh_op == 1) ? wdh = g_param[pos].width : 0;
	(g_param[pos].wdh_op == 2) ? wdh = g_param[pos].wdha : 0;
	(g_param[pos].pcn_op == 1) ? prec = g_param[pos].prec : 0;
	(g_param[pos].pcn_op == 2) ? prec = g_param[pos].pcna : 0;
	if (g_param[pos].pcn_op >= 3)
		case3_di(chr, wdh, pos);
	else if (prec <= 0 && wdh <= 0)
		ft_putstr_fd(g_param[pos].result, 1);
	else if (wdh > 0 && prec < 0)
		case1_uint(wdh, str, pos);
	else
		case2_uint(wdh, prec, str, pos);
}

void		case1_uint(int wdh, int str, int pos)
{
	char	let;
	int		add;

	let = (g_param[pos].zero == -1) ? ' ' : '0';
	add = (let == '0' && g_param[pos].type == 'p') ? 2 : 0;
	if (g_param[pos].left > -1)
	{
		ft_putstr_fd(g_param[pos].result, 1);
		while (--wdh >= str)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		if (add == 2 && let == '0')
			ft_putstr_fd("0x", 1);
		while (--wdh >= str)
			ft_putchar_fd(let, 1);
		ft_putstr_fd(&g_param[pos].result[add], 1);
	}
}

void		case2_uint(int wdh, int prec, int str, int pos)
{
	int		prec1;
	int		add;

	prec1 = (prec > str) ? prec : str;
	if (wdh > prec1 && g_param[pos].left == -1)
	{
		while (--wdh >= prec1)
			ft_putchar_fd(' ', 1);
	}
	if (prec1 > str && g_param[pos].type == 'p')
	{
		ft_putstr_fd("0x", 1);
		prec1 += 2;
		g_param[pos].perc = '2';
	}
	add = (prec1 > str && g_param[pos].type == 'p') ? 2 : 0;
	while (--prec1 >= str)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(&g_param[pos].result[add], 1);
	prec1 = (prec > str) ? prec : str;
	if (wdh > prec1 && g_param[pos].left > -1)
	{
		while (--wdh >= prec1)
			ft_putchar_fd(' ', 1);
	}
}

int			count_uint(int pos)
{
	int		cnt;
	int		size;
	int		pcn;
	int		wdh;

	cnt = 0;
	if (g_param[pos].pcn_op <= 1 || g_param[pos].pcn_op == 3)
		pcn = g_param[pos].prec;
	else
		pcn = g_param[pos].pcna;
	wdh = (g_param[pos].wdh_op > 1) ? g_param[pos].wdha : g_param[pos].width;
	cnt = cnt - (g_param[pos].qtd_char + 1);
	size = ft_strlen(g_param[pos].result);
	size = (pcn > size) ? pcn : size;
	size = (wdh > size) ? wdh : size;
	if (g_param[pos].type == 'p' && g_param[pos].perc == '2')
		size += 2;
	return (cnt + size);
}

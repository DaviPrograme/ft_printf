/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 15:33:21 by davi              #+#    #+#             */
/*   Updated: 2020/04/24 00:53:39 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

extern t_param *g_param;

void		put_string(int pos)
{
	int		prc;
	int		wdh;
	int		str;

	prc = -1;
	wdh = -1;
	str = (int)ft_strlen((const char *)g_param[pos].result);
	(g_param[pos].wdh_op == 1) ? wdh = g_param[pos].width : 0;
	(g_param[pos].wdh_op == 2) ? wdh = g_param[pos].wdha : 0;
	(g_param[pos].pcn_op == 1) ? prc = g_param[pos].prec : 0;
	(g_param[pos].pcn_op == 2) ? prc = g_param[pos].pcna : 0;
	(prc < 0 && g_param[pos].prec == 0 && g_param[pos].pcna == 0) ? prc = 0 : 0;
	(prc < 0 && g_param[pos].prec == 0 && g_param[pos].pcna < 0) ? prc = 0 : 0;
	(prc < 0 && g_param[pos].prec < 0 && g_param[pos].pcna == 0) ? prc = 0 : 0;
	(prc < 0 && g_param[pos].prec > 0) ? prc = g_param[pos].prec : 0;
	if (g_param[pos].pcna < 0 && g_param[pos].prec < 0 && wdh <= 0)
		ft_putstr_fd(g_param[pos].result, 1);
	else
		case1_string(wdh, prc, str, pos);
}

void		case1_string(int wdh, int prec, int str, int pos)
{
	int		prec1;
	int		cont;
	char	let;

	cont = 0;
	let = (g_param[pos].zero == -1) ? ' ' : '0';
	(prec < 0 && g_param[pos].pcn_op == 0) ? prec = str : 0;
	prec1 = (prec > str || prec < 0) ? str : prec;
	if (wdh > prec1 && g_param[pos].left == -1)
	{
		while (--wdh >= prec1)
			ft_putchar_fd(let, 1);
	}
	if (prec1 && g_param[pos].result != NULL)
	{
		while (--prec1 >= 0 && g_param[pos].result[cont])
			ft_putchar_fd(g_param[pos].result[cont++], 1);
	}
	prec1 = (prec > str || prec < 0) ? str : prec;
	if (wdh > prec1 && g_param[pos].left > -1)
	{
		while (--wdh >= prec1)
			ft_putchar_fd(' ', 1);
	}
}

int			count_string(int pos)
{
	int		cnt;
	int		size;
	int		pcn;
	int		wdh;

	cnt = 0;
	pcn = (g_param[pos].pcn_op > 1) ? g_param[pos].pcna : g_param[pos].prec;
	wdh = (g_param[pos].wdh_op > 1) ? g_param[pos].wdha : g_param[pos].width;
	cnt = cnt - (g_param[pos].qtd_char + 1);
	size = ft_strlen(g_param[pos].result);
	(pcn < size && pcn >= 0) ? size = pcn : 0;
	size = (wdh > size) ? wdh : size;
	return (cnt + size);
}

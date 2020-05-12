/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_di.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 15:09:02 by davi              #+#    #+#             */
/*   Updated: 2020/04/24 00:45:05 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

extern t_param *g_param;

void		put_di(int pos)
{
	int		prec;
	int		wdh;
	int		str;
	char	chr;

	prec = -1;
	wdh = -1;
	chr = g_param[pos].result[0];
	(g_param[pos].wdh_op == 1) ? wdh = g_param[pos].width : 0;
	(g_param[pos].wdh_op == 2) ? wdh = g_param[pos].wdha : 0;
	(g_param[pos].pcn_op == 1) ? prec = g_param[pos].prec : 0;
	(g_param[pos].pcn_op == 2) ? prec = g_param[pos].pcna : 0;
	str = (int)ft_strlen((const char *)g_param[pos].result);
	if (g_param[pos].pcn_op >= 3)
		case3_di(chr, wdh, pos);
	else if (prec <= 0 && wdh <= 0)
		ft_putstr_fd(g_param[pos].result, 1);
	else if (wdh > 0 && prec < 0)
		case1_di(chr, wdh, str, pos);
	else
		case2_di(chr, wdh, prec, pos);
}

void		case3_di(char chr, int wdh, int pos)
{
	if (g_param[pos].type == 'p')
	{
		case3_p(wdh, pos);
		return ;
	}
	if (chr != '0' && g_param[pos].left > -1)
	{
		ft_putstr_fd(g_param[pos].result, 1);
		wdh -= (ft_strlen(g_param[pos].result));
		while (--wdh >= 0)
			ft_putchar_fd(' ', 1);
	}
	else if (chr == '0')
	{
		while (--wdh >= 0)
			ft_putchar_fd(' ', 1);
		g_param[pos].result[0] = 0;
	}
	else
	{
		wdh -= (ft_strlen(g_param[pos].result));
		while (--wdh >= 0)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd(g_param[pos].result, 1);
	}
}

void		case1_di(char chr, int wdh, int str, int pos)
{
	char	let;

	let = (g_param[pos].zero == -1) ? ' ' : '0';
	if (g_param[pos].left > -1)
	{
		ft_putstr_fd(g_param[pos].result, 1);
		while (--wdh >= str)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		(chr == '-' && g_param[pos].zero > -1) ? ft_putchar_fd(chr, 1) : 0;
		while (--wdh >= str)
			ft_putchar_fd(let, 1);
		if (g_param[pos].zero > -1 && chr == '-')
			ft_putstr_fd((g_param[pos].result + 1), 1);
		else
			ft_putstr_fd(g_param[pos].result, 1);
	}
}

void		case2_di(char chr, int wdh, int prec, int pos)
{
	int		prec1;
	int		str;

	str = (int)ft_strlen((const char *)g_param[pos].result);
	prec1 = (prec > str) ? prec : str;
	(chr == '-' && prec >= str) ? prec1 += 1 : 0;
	if (wdh > prec1 && g_param[pos].left == -1)
	{
		while (--wdh >= prec1)
			ft_putchar_fd(' ', 1);
	}
	(chr == '-') ? ft_putchar_fd(chr, 1) : 0;
	while (--prec1 >= str)
		ft_putchar_fd('0', 1);
	if (chr == '-')
		ft_putstr_fd((g_param[pos].result + 1), 1);
	else
		ft_putstr_fd(g_param[pos].result, 1);
	prec1 = (prec > str) ? prec : str;
	(chr == '-' && prec >= str) ? prec1 += 1 : 0;
	if (wdh > prec1 && g_param[pos].left > -1)
	{
		while (--wdh >= prec1)
			ft_putchar_fd(' ', 1);
	}
}

int			count_di(int pos)
{
	int		cnt;
	int		size;
	int		pcn;
	int		wdh;

	if (g_param[pos].pcn_op <= 1 || g_param[pos].pcn_op == 3)
		pcn = g_param[pos].prec;
	else
		pcn = g_param[pos].pcna;
	wdh = (g_param[pos].wdh_op > 1) ? g_param[pos].wdha : g_param[pos].width;
	cnt = 0;
	cnt = cnt - (g_param[pos].qtd_char + 1);
	size = ft_strlen(g_param[pos].result);
	if ((ft_isdigit(g_param[pos].result[0])) && pcn > 0)
		size = (pcn > size) ? pcn : size;
	else if (!(ft_isdigit(g_param[pos].result[0])) && pcn > 0)
		size = (pcn > (size - 1)) ? pcn + 1 : size;
	size = (wdh > size) ? wdh : size;
	return (cnt + size);
}

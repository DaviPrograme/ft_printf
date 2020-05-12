/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_percent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 15:28:02 by davi              #+#    #+#             */
/*   Updated: 2020/04/17 15:29:49 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

extern t_param *g_param;

void		put_percent(int pos)
{
	int		wdh;

	wdh = -1;
	(g_param[pos].wdh_op == 1) ? wdh = g_param[pos].width : 0;
	(g_param[pos].wdh_op == 2) ? wdh = g_param[pos].wdha : 0;
	if (wdh <= 1)
		ft_putchar_fd('%', 1);
	else
		case1_percent(wdh, pos);
}

void		case1_percent(int wdh, int pos)
{
	char	let;

	let = (g_param[pos].zero == -1) ? ' ' : '0';
	if (g_param[pos].left > -1)
	{
		ft_putchar_fd('%', 1);
		while (--wdh >= 1)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (--wdh >= 1)
			ft_putchar_fd(let, 1);
		ft_putchar_fd('%', 1);
	}
}

int			count_percent(int pos)
{
	int		cnt;
	int		wdh;

	cnt = 0;
	wdh = (g_param[pos].wdh_op > 1) ? g_param[pos].wdha : g_param[pos].width;
	wdh = (wdh > 1) ? wdh : 1;
	cnt = cnt - (g_param[pos].qtd_char + 1);
	return (cnt + wdh);
}

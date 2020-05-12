/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 15:05:28 by davi              #+#    #+#             */
/*   Updated: 2020/04/23 11:58:23 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

extern t_param *g_param;

void		put_char(int pos)
{
	int		wdh;

	wdh = -1;
	(g_param[pos].wdh_op == 1) ? wdh = g_param[pos].width : 0;
	(g_param[pos].wdh_op == 2) ? wdh = g_param[pos].wdha : 0;
	if (wdh <= 1 && g_param[pos].result != NULL)
		ft_putchar_fd(g_param[pos].result[0], 1);
	else
		case1_char(wdh, pos);
}

void		case1_char(int wdh, int pos)
{
	if (g_param[pos].left > -1)
	{
		if (g_param[pos].result != NULL)
			ft_putchar_fd(g_param[pos].result[0], 1);
		else
			ft_putchar_fd('\0', 1);
		while (--wdh >= 1)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (--wdh >= 1)
			ft_putchar_fd(' ', 1);
		if (g_param[pos].result != NULL)
			ft_putchar_fd(g_param[pos].result[0], 1);
		else
			ft_putchar_fd('\0', 1);
	}
}

int			count_pchar(int pos)
{
	int		cnt;
	int		wdh;

	cnt = 0;
	wdh = (g_param[pos].wdh_op > 1) ? g_param[pos].wdha : g_param[pos].width;
	wdh = (wdh > 1) ? wdh : 1;
	cnt = cnt - (g_param[pos].qtd_char + 1);
	return (cnt + wdh);
}

char		*ft_chrdup(const char s1)
{
	char	*ptr1;

	if (s1 == '\0')
		return (NULL);
	if (!(ptr1 = (char *)malloc((sizeof(char) + 1))))
		return (NULL);
	ptr1[0] = ((char)s1);
	ptr1[1] = '\0';
	return (ptr1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verificadores2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 20:20:16 by davi              #+#    #+#             */
/*   Updated: 2020/04/25 01:45:47 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

extern t_param *g_param;

int		if_ast(int rec, char chr, int pos)
{
	(rec < 0 && chr != '.') ? ++g_param[pos].left : 0;
	(chr == '.') ? g_param[pos].pcna = rec : 0;
	(rec < 0) ? rec *= -1 : 0;
	(chr != '.') ? g_param[pos].wdha = rec : 0;
	return (rec);
}

int		ver_ast(char chr, int rec, const char *p)
{
	int	ver;

	ver = 0;
	(chr == 'd' || chr == 'i' || chr == 'u') ? ver += 1 : 0;
	(chr == 'X' || chr == 'x' || chr == 'p') ? ver += 1 : 0;
	(rec == 0) ? ver += 1 : 0;
	(p[0] == '.') ? ver += 1 : 0;
	(zero_ast(&p[2])) ? ver += 1 : 0;
	if (ver == 4)
		return (1);
	return (0);
}

int		ver_option_struct(char chr, const char *p, int pos)
{
	int	ver;

	ver = 0;
	(p[0] == '.') ? ver += 1 : 0;
	(((!(ft_isdigit(p[1]))) || p[1] == '0') && p[1] != '*') ? ver += 1 : 0;
	(chr == 'd' || chr == 'i' || chr == 'u') ? ver += 1 : 0;
	(chr == 'X' || chr == 'x' || chr == 'p') ? ver += 1 : 0;
	(g_param[pos].pcn_op != 4) ? ver += 1 : 0;
	if (ver == 4)
		return (1);
	return (0);
}

int		zero_ast(const char *ptr)
{
	int	cont;

	cont = 1;
	while ((ver_flag((ptr + cont))))
	{
		if (ptr[cont] == '.')
			return (0);
		++cont;
	}
	return (1);
}

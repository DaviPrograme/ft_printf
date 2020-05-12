/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 16:02:40 by davi              #+#    #+#             */
/*   Updated: 2020/04/25 19:51:12 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

extern	t_param *g_param;

int		ver_char(char let)
{
	int	n;

	n = 0;
	n = (let == 'c') ? 1 : n;
	n = (let == 's') ? 1 : n;
	n = (let == 'p') ? 1 : n;
	n = (let == 'd') ? 1 : n;
	n = (let == 'i') ? 1 : n;
	n = (let == 'u') ? 1 : n;
	n = (let == 'x') ? 1 : n;
	n = (let == 'X') ? 1 : n;
	n = (let == '%') ? 1 : n;
	return (n);
}

int		ver_flag_set(const char *ptr, int pos)
{
	if (*ptr == '-')
		return (1);
	else if (*ptr == '.')
	{
		if (ft_isdigit(*(ptr + 1)) || *(ptr + 1) != '*')
			g_param[pos].prec = 0;
		return (1);
	}
	else if (*ptr == '*')
	{
		g_param[pos].ast += 1;
		return (1);
	}
	else if ((ft_isdigit(*ptr)))
		return (1);
	else if (!(ft_isalpha(*ptr)) && *ptr != '\0' && *ptr != '%')
		return (1);
	else
		return (0);
}

int		ver_flag_ast(const char *ptr, int pos)
{
	if (*ptr == '-')
		return (1);
	else if (*ptr == '.')
	{
		if (!(ft_isdigit(*(ptr + 1))) || *(ptr + 1) == '*')
			g_param[pos].pcna = 0;
		return (1);
	}
	else if (*ptr == '*')
		return (1);
	else if ((ft_isdigit(*ptr)))
		return (1);
	else if (!(ft_isalpha(*ptr)) && *ptr != '\0' && *ptr != '%')
		return (1);
	else
		return (0);
}

int		ver_flag(const char *ptr)
{
	if (*ptr == '-')
		return (1);
	else if (*ptr == '.')
		return (1);
	else if (*ptr == '*')
		return (1);
	else if ((ft_isdigit(*ptr)))
		return (1);
	else if (!(ft_isalpha(*ptr)) && *ptr != '\0' && *ptr != '%')
		return (1);
	else
		return (0);
}

int		while_ast(const char *ptr, int pos, char let)
{
	int	ver;

	ver = 0;
	ver += ver_flag_ast((const char *)ptr, pos);
	ver += ver_char(let);
	if (ver == 2)
		return (1);
	return (0);
}

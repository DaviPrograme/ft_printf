/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory_structs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:45:54 by dmoreira          #+#    #+#             */
/*   Updated: 2020/04/25 20:19:42 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

extern t_param	*g_param;

int				ft_newparam(int size)
{
	if (!(g_param = (t_param *)ft_calloc(size, sizeof(t_param))))
		return (0);
	while (--size >= 0)
	{
		g_param[size].perc = 0;
		g_param[size].left = -1;
		g_param[size].width = -1;
		g_param[size].wdha = -1;
		g_param[size].wdh_op = 0;
		g_param[size].zero = -1;
		g_param[size].qtd_char = 0;
		g_param[size].prec = -1;
		g_param[size].pcna = -1;
		g_param[size].pcn_op = 0;
		g_param[size].ast = 0;
		g_param[size].type = 0;
	}
	return (1);
}

void			fill_struct(const char *ptr, int size, int chars)
{
	int			cont;
	int			percent;

	cont = 0;
	percent = 0;
	while (ptr[cont] && percent < size)
	{
		if (ptr[cont] == '%' && ptr[cont + 1] != '%')
		{
			cont += setting_struct((ptr + cont), percent);
			(ptr[cont] == '%') ? ++cont : 0;
			++percent;
		}
		else if (ptr[cont] == '%' && ptr[cont + 1] == '%')
		{
			cont + 2 <= chars ? cont += 2 : ++cont;
			g_param[percent].perc = '%';
			g_param[percent].type = '%';
			g_param[percent].qtd_char = 1;
			++percent;
		}
		else
			++cont;
	}
}

void			value_asterisk(const char *ptr, va_list ap, int num)
{
	int			pos;
	int			cont;
	int			rec;

	pos = 0;
	cont = -1;
	while (ptr[++cont] && pos < num)
	{
		if (ptr[cont] == '%')
		{
			while (while_ast(&ptr[++cont], pos, g_param[pos].type))
			{
				if (ptr[cont] == '*')
				{
					rec = va_arg(ap, int);
					rec = if_ast(rec, ptr[cont - 1], pos);
					if ((ver_ast(g_param[pos].type, rec, &ptr[cont - 1])))
						g_param[pos].pcn_op = 4;
				}
			}
			if ((ver_char(g_param[pos].type)))
				g_param[pos].result = filter_valist(ap, g_param[pos].type, pos);
			++pos;
		}
	}
}

int				setting_struct(const char *ptr, int pos)
{
	int			mv;

	mv = 1;
	while ((ver_flag_set((ptr + mv), pos)))
	{
		if (ptr[mv] == '-' || (ptr[mv] == '0' && ptr[mv - 1] != '.'))
		{
			*(ptr + mv) == '-' ? g_param[pos].left += 1 : 0;
			*(ptr + mv) == '0' ? g_param[pos].zero += 1 : 0;
			++mv;
		}
		else if (*(ptr + mv) >= '0' && *(ptr + mv) <= '9')
		{
			*(ptr + mv - 1) == '.' ? g_param[pos].prec = ft_atoi(ptr + mv) : 0;
			*(ptr + mv - 1) != '.' ? g_param[pos].width = ft_atoi(ptr + mv) : 0;
			while (ft_isdigit(*(ptr + mv)))
				++mv;
		}
		else
			++mv;
	}
	if (ft_isalpha(*(ptr + mv)) || *(ptr + mv) == '%')
		g_param[pos].type = *(ptr + mv);
	g_param[pos].qtd_char = (*(ptr + mv) == '\0') ? mv - 1 : mv;
	return (mv);
}

void			options_struct(const char *ptr, int pos, int mv)
{
	while (ptr[++mv])
	{
		if (ptr[mv] == '%')
		{
			while ((ver_flag(&ptr[++mv])))
			{
				if (ptr[mv] == '*' || (ptr[mv] == '0' && ptr[mv - 1] != '.'))
				{
					if (ptr[mv - 1] == '.' && g_param[pos].pcn_op != 4)
						g_param[pos].pcn_op = 2;
					(ptr[mv - 1] != '.') ? g_param[pos].wdh_op = 2 : 0;
				}
				else if (*(ptr + mv) >= '1' && *(ptr + mv) <= '9')
				{
					*(ptr + mv - 1) == '.' ? g_param[pos].pcn_op = 1 : 0;
					*(ptr + mv - 1) != '.' ? g_param[pos].wdh_op = 1 : 0;
					while (ft_isdigit(*(ptr + mv + 1)))
						++mv;
				}
				else if ((ver_option_struct(g_param[pos].type, &ptr[mv], pos)))
					g_param[pos].pcn_op = 3;
			}
			++pos;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walking_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:50:21 by dmoreira          #+#    #+#             */
/*   Updated: 2020/04/26 13:09:21 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		cont_flags(const char *pnt)
{
	int	cont;
	int percent;
	int	n_chars;

	cont = 0;
	percent = 0;
	n_chars = ft_strlen(pnt);
	while (pnt[cont])
	{
		if (pnt[cont] == '%')
		{
			++percent;
			if ((pnt[cont + 1] == '%') && (cont + 2 <= n_chars))
				cont += 2;
			else if (++cont)
			{
				while ((ver_flag((pnt + cont))))
					++cont;
				cont += (*(pnt + cont) != '\0') ? 1 : 0;
			}
		}
		else
			++cont;
	}
	return (percent);
}

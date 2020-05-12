/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filtro_valist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 22:12:25 by davi              #+#    #+#             */
/*   Updated: 2020/04/24 14:51:01 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

extern t_param	*g_param;

char				*filter_valist(va_list ap, char cha, int pos)
{
	char			*ptr;

	ptr = NULL;
	if (cha == 'd' || cha == 'i')
		ptr = ft_itoa((va_arg(ap, int)));
	else if (cha == 'c')
		ptr = ft_chrdup((va_arg(ap, int)));
	else if (cha == 's')
	{
		ptr = va_arg(ap, char *);
		(ptr == NULL) ? g_param[pos].perc = 'N' : 0;
		(ptr == NULL) ? ptr = ft_strdup("(null)") : 0;
	}
	else if (cha == 'u')
		ptr = ft_uitoa((va_arg(ap, unsigned int)));
	else if (cha == 'x')
		ptr = change_low16((va_arg(ap, unsigned int)));
	else if (cha == 'X')
		ptr = change_upper16((va_arg(ap, unsigned int)));
	else if (cha == 'p')
		ptr = put_p((va_arg(ap, size_t)));
	return (ptr);
}

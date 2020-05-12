/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_base16.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 16:05:09 by davi              #+#    #+#             */
/*   Updated: 2020/04/25 19:38:47 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char				*change_low16(unsigned int num)
{
	char			*ptr;
	unsigned int	cont;
	unsigned int	aux;

	cont = 0;
	if (!(ptr = (char *)ft_calloc(8, sizeof(char))))
		return (ptr);
	while (num >= 16)
	{
		ptr[cont] = alphanum_low16((num % 16));
		++cont;
		num /= 16;
	}
	ptr[cont] = alphanum_low16(num);
	num = 0;
	while (cont > num)
	{
		aux = ptr[num];
		ptr[num] = ptr[cont];
		ptr[cont] = aux;
		--cont;
		++num;
	}
	return (ptr);
}

char				alphanum_low16(unsigned int n)
{
	char			chr;

	if (n >= 0 && n <= 9)
		chr = '0' + n;
	else
	{
		(n == 10) ? chr = 'a' : 0;
		(n == 11) ? chr = 'b' : 0;
		(n == 12) ? chr = 'c' : 0;
		(n == 13) ? chr = 'd' : 0;
		(n == 14) ? chr = 'e' : 0;
		(n == 15) ? chr = 'f' : 0;
	}
	return (chr);
}

char				*change_upper16(unsigned int num)
{
	char			*ptr;
	unsigned int	cont;
	unsigned int	aux;

	cont = 0;
	if (!(ptr = (char *)ft_calloc(8, sizeof(char))))
		return (ptr);
	while (num >= 16)
	{
		ptr[cont] = ft_toupper(alphanum_low16((num % 16)));
		++cont;
		num /= 16;
	}
	ptr[cont] = ft_toupper(alphanum_low16(num));
	num = 0;
	while (cont > num)
	{
		aux = ptr[num];
		ptr[num] = ptr[cont];
		ptr[cont] = aux;
		--cont;
		++num;
	}
	return (ptr);
}

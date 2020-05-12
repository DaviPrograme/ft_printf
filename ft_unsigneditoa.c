/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigneditoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:10:59 by dmoreira          #+#    #+#             */
/*   Updated: 2020/04/17 15:01:29 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char			*alocador(unsigned int n, int cont)
{
	unsigned int	vetor[2];
	char			*ptr;

	vetor[0] = n;
	vetor[1] = n;
	if (!(ptr = (char *)ft_calloc(cont + 1, sizeof(char))))
		return (NULL);
	if (n < 0)
	{
		ptr[0] = '-';
		while (--cont)
		{
			vetor[0] = vetor[1] / 10;
			ptr[cont] = 48 + (-vetor[1] + (vetor[0] * 10));
			vetor[1] = vetor[1] / 10;
		}
		return (ptr);
	}
	while (--cont >= 0)
	{
		vetor[0] = vetor[1] / 10;
		ptr[cont] = 48 + (vetor[1] - (vetor[0] * 10));
		vetor[1] = vetor[1] / 10;
	}
	return (ptr);
}

char				*ft_uitoa(unsigned int n)
{
	int				cont;
	unsigned int	numb;
	char			*ptr;

	numb = n;
	cont = 0;
	if (n == 0)
	{
		ptr = (char *)ft_calloc(2, sizeof(char));
		ptr[0] = 48;
		return (ptr);
	}
	while (numb != 0 && ++cont)
		numb = numb / (unsigned int)10;
	if (n < 0)
		++cont;
	ptr = alocador(n, cont);
	return (ptr);
}

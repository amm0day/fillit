/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungurea <sungurea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:51:15 by andmiron          #+#    #+#             */
/*   Updated: 2018/09/08 20:04:11 by sungurea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		ft_swap(int *a, int *b)
{
	int	aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

void		ft_dcmp(int i, int *y, int j, int *x)
{
	if (*y < i)
		*y = i;
	if (*x < j)
		*x = j;
}

int			sqmerge(int vld)
{
	int power;

	power = 1;
	vld *= 4;
	while (power * power < vld)
		power++;
	return (power);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstruct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungurea <sungurea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 20:04:04 by sungurea          #+#    #+#             */
/*   Updated: 2018/09/08 20:03:00 by sungurea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_alloc(int m, int **cnv, int choose)
{
	int	i;

	i = -1;
	if (choose == 0)
		while (++i < m)
			cnv[i] = (int *)malloc(m * sizeof(int *));
	if (choose == 1)
	{
		while (++i < m)
			free(cnv[i]);
		free(cnv);
	}
}

void	ft_fillzero(int m, int **cnv)
{
	int	x;
	int	y;

	y = -1;
	while (++y < m)
	{
		x = -1;
		while (++x < m)
			cnv[y][x] = 0;
	}
}

void	ft_remove(variables gl, int tet, int cord[2], int **cnv)
{
	int	y;
	int	x;

	y = cord[0];
	x = cord[1];
	while (y < gl.m)
	{
		while (x < gl.m)
		{
			if (cnv[y][x] == gl.ttr[tet].tt[0][0]
					|| cnv[y][x] == gl.ttr[tet].tt[1][1])
				cnv[y][x] = 0;
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_afis(int m, int **cnv)
{
	int x;
	int y;

	y = -1;
	while (++y < m)
	{
		x = -1;
		while (++x < m)
		{
			if (cnv[y][x] == 0)
				write(1, ".", 1);
			else
				write(1, &cnv[y][x], 1);
		}
		write(1, "\n", 1);
	}
}

void    printstruct(t_tetris *ttr, int vld)
{
    int i;
    int j;
    int k;

    k = -1;
    while (++k < vld && (i = -1))
        while (++i < 5 && (j = -1))
            if (i == 4)
                printf("x = %d, y = %d \n", ttr[k].x, ttr[k].y);
            else
                while (++j < 5)
                    if (j == 4)
                        write(1, "\n", 1);
                    else
                        if (ttr[k].tt[i][j] == 0)
                            write(1, ".", 1);
                        else
                            write(1, &(ttr[k].tt[i][j]), 1);
}

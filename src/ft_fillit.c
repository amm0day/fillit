/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungurea <sungurea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:51:15 by andmiron          #+#    #+#             */
/*   Updated: 2018/09/05 18:24:12 by mnegrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_fillone(variables gl, int tet, int cord[2], int **cnv)
{
	int	yt;
	int	xt;

	yt = -1;
	while (++yt < gl.ttr[tet].y)
	{
		xt = -1;
		while (++xt < gl.ttr[tet].x)
			if (gl.ttr[tet].tt[yt][xt] > 0)
				cnv[cord[0] + yt][cord[1] + xt] = gl.ttr[tet].tt[yt][xt];
	}
}

int		ft_chekones(variables gl, int tet, int cord[2], int **cnv)
{
	int	xt;
	int	yt;
	int	cord1[2];

	cord1[0] = cord[0];
	cord1[1] = cord[1];
	xt = -1;
	yt = 0;
	if (cord1[0] + gl.ttr[tet].y > gl.m)
		return (0);
	while (gl.ttr[tet].tt[0][++xt] == 0 && cord1[1] > 0)
		cord1[1]--;
	if (cord1[1] + gl.ttr[tet].x > gl.m)
		return (0);
	while (yt < gl.ttr[tet].y)
	{
		xt = -1;
		while (++xt < gl.ttr[tet].x)
			if (cnv[cord1[0] + yt][cord1[1] + xt] != 0
					&& gl.ttr[tet].tt[yt][xt] != 0)
				return (0);
		yt++;
	}
	ft_fillone(gl, tet, cord1, cnv);
	return (1);
}

int		ft_pass(variables gl, int tet, int **cnv)
{
	int	cord[2];

	if (tet == gl.vld)
	{
		ft_afis(gl.m, cnv);
		exit(1);
	}
	cord[0] = 0;
	while (cord[0] < gl.m)
	{
		cord[1] = 0;
		while (cord[1] < gl.m)
		{
			if (ft_chekones(gl, tet, cord, cnv))
			{
				ft_pass(gl, tet + 1, cnv);
				ft_remove(gl, tet, cord, cnv);
			}
			cord[1]++;
		}
		cord[0]++;
	}
	return (0);
}

void	ft_fill(int m, int vld, t_tetris *ttr)
{
	variables	gl;
	int			**cnv;

	gl.ttr = ttr;
	gl.m = m;
	gl.vld = vld;
	cnv = (int**)malloc(m * sizeof(int*));
	ft_alloc(m, cnv, 0);
	ft_fillzero(gl.m, cnv);
	while (!ft_pass(gl, 0, cnv))
	{
		ft_alloc(m, cnv, 1);
		ft_fill(m + 1, gl.vld, gl.ttr);
	}
}

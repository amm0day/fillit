/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungurea <sungurea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 08:21:33 by sungurea          #+#    #+#             */
/*   Updated: 2018/09/08 23:13:19 by sungurea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			pre_validate(int fd)
{
	int		j;
	int		i;
	int		k;
	int		f;
	char	c;

	j = 0;
	k = 0;
	i = 0;
	f = 0;
	while (read(fd, &c, 1))
		if (c == '.' && j < 4 && i < 4)
			j++;
		else if (c == '#' && j++ < 4 && i < 4)
			k++;
		else if (c == '\n' && j == 4 && i++ < 4)
			j = 0;
		else if (c == '\n' && j == 0 && i == 4 && k == 4 && ++f && !(k = 0))
			i = 0;
		else
			return (0);
	if (!(c == '\n' && j == 0 && i == 4 && k == 4 && ++f))
		return (0);
	close(fd);
	return (f);
}

t_tetris	*convert(int fd, t_tetris *ttr)
{
	int			i;
	int			j;
	int			k;
	char		c;

	i = 0;
	j = 0;
	k = 0;
	while (read(fd, &c, 1))
	{
		if (j == 4 && ++i)
			j = 0;
		if (i == 4 && ++k)
			i = 0;
		if (c != '\n')
		{
			if (c == '.')
				ttr[k].tt[i][j] = 0;
			else if (c == '#')
				ttr[k].tt[i][j] = 65 + k;
			j++;
		}
	}
	return (ttr);
}

int			post_validate(t_tetris *ttr, int sz)
{
	int	i;
	int j;
	int k;
	int	n;

	k = -1;
	while (++k < sz && (i = -1))
	{
		FT_Z(ttr[k].x, ttr[k].y, n, -1);
		while (++i < 4 && (j = -1))
			while (++j < 4)
				if (ttr[k].tt[i][j] > 0)
				{
					((i + 1 < 4 && ttr[k].tt[i + 1][j]) ? n++ : 0);
					((j + 1 < 4 && ttr[k].tt[i][j + 1]) ? n++ : 0);
					((i - 1 >= 0 && ttr[k].tt[i - 1][j]) ? n++ : 0);
					((j - 1 >= 0 && ttr[k].tt[i][j - 1]) ? n++ : 0);
				}
		if (!(n == 5 || n == 7))
		{
			free(ttr);
			return (0);
		}
	}
	return (1);
}

t_tetris	*arrange(t_tetris *ttr, int sz)
{
	int i;
	int j;
	int di;
	int dj;

	while (--sz > -1 && FT_Z(i, di, dj, -1))
		while (++i < 4 && (j = -1))
			while (++j < 4)
			{
				if (di < 0 && ttr[sz].tt[i][j] > 0 && dj < 0)
				{
					di = i;
					dj = j;
					while (j-- && ((ttr[sz].tt[i + 1][j] && i < 3) ||
						(ttr[sz].tt[i + 2][j] && i < 2)))
						dj--;
				}
				if (ttr[sz].tt[i][j] > 0)
					ft_dcmp(i - di + 1, &(ttr[sz].y), j - dj + 1, &(ttr[sz].x));
				if (ttr[sz].tt[i][j] > 0 && di > -1 && dj > -1)
					ft_swap(&(ttr[sz].tt[i - di][j - dj]), &(ttr[sz].tt[i][j]));
			}
	return (ttr);
}

t_tetris	*parsing(char *file, int fd)
{
	int			vld;
	int			sqm;
	t_tetris	*ttr;

	vld = pre_validate(fd);
	sqm = sqmerge(vld);
	ttr = (t_tetris*)malloc(sizeof(t_tetris) * vld);
	if (vld)
	{
		fd = open(file, O_RDONLY);
		ttr = convert(fd, ttr);
		close(fd);
	}
	else
		return (NULL);
	if (post_validate(ttr, vld))
	{
		ttr = arrange(ttr, vld);
		ft_fill(sqm, vld, ttr);
	}
	else
		return (NULL);
	return (ttr);
}

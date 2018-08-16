/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungurea <sungurea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 08:21:33 by sungurea          #+#    #+#             */
/*   Updated: 2018/08/16 20:29:33 by sungurea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int     	pre_validate(int fd)
{
	int 	j;
	int		i;
	int		k;
	char	c;

	j = 0;
	k = 0;
	i = 0;
	while (read(fd, &c, 1))
		if (c == '.' && j < 4 && i < 4)
			j++;
		else if (c == '#' && j++ < 4 && i < 4)
			k++;
		else if (c == '\n' && j == 4 && i++ < 4)
			j = 0;
		else if (c == '\n' && j == 0 && i == 4 && !(k % 4))
			i = 0;
		else
			return (0);
	if (!(c == '\n' && j == 0 && i == 4 && !(k % 4)))
		return (0);
	close (fd);
	return (k / 4);
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

	k = -1;
	while (++k < sz && (i = -1))
		while (++i < 4 && (j = -1))
			while (++j < 4)
				if (ttr[k].tt[i][j] > 0 && !((i + 1 < 4 &&
					ttr[k].tt[i + 1][j] > 0) || (j + 1 < 4 &&
					ttr[k].tt[i][j + 1] > 0) || (i - 1 >= 0 &&
					ttr[k].tt[i - 1][j] > 0) || (j - 1 >= 0 &&
					ttr[k].tt[i][j - 1] > 0)))
				{
					free(ttr);
					return (0);
				}
	return (1);
}

t_tetris	*arrange(t_tetris *ttr, int sz)
{
	int i;
	int j;
	int di;
	int dj;

	while (--sz > -1 && (i = -1) && (di = -1) && (dj = -1))
		while (++i < 4 && (j = -1))
			while (++j < 4)
			{
				if (ttr[sz].tt[i][j] > 0 && di < 0 && dj < 0)
				{
					di = i;
					dj = j;
					ttr[sz].x = 0;
					ttr[sz].y = 0;
				}
				if (ttr[sz].tt[i][j] > 0 && (di || dj))
					ft_swap(&(ttr[sz].tt[i - di][j - dj]), &(ttr[sz].tt[i][j]));
				if (ttr[sz].tt[i][j] > 0)
					ft_doublecmp(i - di, &(ttr[sz].y), j - dj, &(ttr[sz].x));
			}
	return (ttr);
}

t_tetris	*parsing(char *file, int fd)
{
	int			vld;
	t_tetris	*ttr;

	vld = pre_validate(fd);
	ttr = (t_tetris*)malloc(sizeof(t_tetris) * vld);
	if (vld)
	{
		fd = open(file, O_RDONLY);
		ttr = convert(fd, ttr);
		close (fd);
	}
	else
		return NULL;
	if (post_validate(ttr, vld))
	{
		ttr = arrange(ttr, vld);
		printstruct(ttr, vld);
	}
	else
		return NULL;
	return (ttr);
}

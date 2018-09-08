/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungurea <sungurea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 17:06:06 by sungurea          #+#    #+#             */
/*   Updated: 2018/09/08 14:37:08 by sungurea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_H
# define __FT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define FT_Z(a, b, c) ((a = -1) && (b = -1) && (c = -1))

typedef struct	s_tetris
{
	int			x;
	int			y;
	int			tt[4][4];
}				t_tetris;

typedef struct	pass
{
	t_tetris	*ttr;
	int			vld;
	int			m;
}				variables;

void			ft_swap(int *a, int *b);
void			ft_doublecmp(int i, int *y, int j, int *x);
int				pre_validate(int fd);
t_tetris		*convert(int fd, t_tetris *ttr);
int				post_validate(t_tetris *ttr, int sz);
t_tetris		*arrange(t_tetris *ttr, int sz);
t_tetris		*parsing(char *file, int fd);
void			printstruct(t_tetris *ttr, int vld);
int				sqmerge(int vld);
int				ft_chekones(variables gl, int tet, int cord[2], int **cnv);
void			ft_fillzero(int n, int **cnv);
void			ft_afis(int m, int **cnv);
int				ft_pass(variables gl, int tet, int **cnv);
void			ft_fill(int m, int tet, t_tetris *ttr);
void			ft_alloc(int m, int **cnv, int choose);
void			ft_remove(variables gl, int tet, int cord[2], int **cnv);
void			ft_fillone(variables gl, int tet, int cord[2], int **cnv);
void  			printstruct(t_tetris *ttr, int vld);
#endif

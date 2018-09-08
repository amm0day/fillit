/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungurea <sungurea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 17:06:06 by sungurea          #+#    #+#             */
/*   Updated: 2018/09/08 23:54:45 by sungurea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# define FT_Z(a, b, c, d) ((a = d) && (b = d) && (c = d))

typedef struct	s_tetris
{
	int			x;
	int			y;
	int			tt[4][4];
}				t_tetris;

typedef struct	s_variables
{
	t_tetris	*ttr;
	int			vld;
	int			m;
}				t_variables;

void			ft_swap(int *a, int *b);
void			ft_dcmp(int i, int *y, int j, int *x);
int				pre_validate(int fd);
t_tetris		*convert(int fd, t_tetris *ttr);
int				post_validate(t_tetris *ttr, int sz);
t_tetris		*arrange(t_tetris *ttr, int sz);
t_tetris		*parsing(char *file, int fd);
int				sqmerge(int vld);
int				ft_chekones(t_variables gl, int tet, int cord[2], int **cnv);
void			ft_fillzero(int n, int **cnv);
void			ft_afis(int m, int **cnv);
int				ft_pass(t_variables gl, int tet, int **cnv);
void			ft_fill(int m, int tet, t_tetris *ttr);
void			ft_alloc(int m, int **cnv, int choose);
void			ft_remove(t_variables gl, int tet, int cord[2], int **cnv);
void			ft_fillone(t_variables gl, int tet, int cord[2], int **cnv);
#endif

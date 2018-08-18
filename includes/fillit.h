/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungurea <sungurea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 17:06:06 by sungurea          #+#    #+#             */
/*   Updated: 2018/08/17 22:10:03 by sungurea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_H
# define __FT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>	//<<< delete befor upload

typedef struct  s_tetris
{
	int			x;
	int			y;
	int     	tt[4][4];
}				t_tetris;

typedef struct pass
{
    t_tetris *ttr;
    int vld;
    int m;
    int tet;
}               variables;

void			ft_swap(int *a, int *b);
void			ft_doublecmp(int i, int *y, int j, int *x);
int     		pre_validate(int fd);
t_tetris		*convert(int fd, t_tetris *ttr);
int				post_validate(t_tetris *ttr, int sz);
t_tetris		*arrange(t_tetris *ttr, int sz);
t_tetris		*parsing(char *file, int fd);
void    		printstruct(t_tetris *ttr, int vld);
int				sqmerge(int vld);
void            ft_copy(int n,int a[n][n],int copy[n][n]);
int             ft_chek(int n,int a[n][n],int xa,int ya,int tet,t_tetris *ttr);
void            ft_fillzero(int n,int a[n][n]);
void            ft_afis(int m,int cnv[m][m]);
int             ft_pass(variables gl,int cnv[gl.m][gl.m],int ya,int xa);
void            ft_fill(int n,int tet,t_tetris *ttr);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungurea <sungurea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 17:06:06 by sungurea          #+#    #+#             */
/*   Updated: 2018/08/16 20:18:41 by sungurea         ###   ########.fr       */
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

void			ft_swap(int *a, int *b);
void			ft_doublecmp(int i, int *y, int j, int *x);
int     		pre_validate(int fd);
t_tetris		*convert(int fd, t_tetris *ttr);
int				post_validate(t_tetris *ttr, int sz);
t_tetris		*arrange(t_tetris *ttr, int sz);
t_tetris		*parsing(char *file, int fd);
void    		printstruct(t_tetris *ttr, int vld);

#endif
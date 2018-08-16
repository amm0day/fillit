/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstruct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungurea <sungurea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 20:04:04 by sungurea          #+#    #+#             */
/*   Updated: 2018/08/16 20:09:08 by sungurea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void    printstruct(t_tetris *ttr, int vld)
{
    int i;
    int j;
    int k;

    k = -1;
    while (++k < vld && (i = -1))
        while (++i < 5 && (j = -1))
            if (i == 4)
                write(1, "\n", 1);
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

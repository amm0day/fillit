/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungurea <sungurea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 21:50:00 by sungurea          #+#    #+#             */
/*   Updated: 2018/08/12 22:07:10 by sungurea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int     main(int argc, char argv)
{
    int i;
	char *buf;
	
	i = 0;
	while (++i < argc)
	{
		if (open(argv[i], O_RDONLY) > 0)
			map_parsing(ft_read(argv[i]));
		else
			map_parsing(argv[i]);
	}
	return (0);
}
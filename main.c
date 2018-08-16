/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungurea <sungurea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 21:50:00 by sungurea          #+#    #+#             */
/*   Updated: 2018/08/16 20:30:21 by sungurea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int     main(int argc, char **argv)
{
    int i;
	int fd;
	
	i = 0;
	while (++i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd)
			if ((parsing(argv[i], fd) == NULL))
				write(1, "map error\n", 10);
	}
	return (0);
}
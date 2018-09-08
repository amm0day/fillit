/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungurea <sungurea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 21:50:00 by sungurea          #+#    #+#             */
/*   Updated: 2018/09/08 19:49:15 by sungurea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int		main(int argc, char **argv)
{
	int	i;
	int	fd;

	i = 0;
	while (++i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd)
			if ((parsing(argv[i], fd) == NULL))
				write(1, "error\n", 6);
	}
	return (0);
}

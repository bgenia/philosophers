/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_open_unique.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:54:34 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/16 18:29:08 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>

#include <philosophers/lib/lib.h>
#include <philosophers/bonus/semutils.h>

sem_t
	*sem_open_unique(int value)
{
	static int	seed = 0;
	char		name_buffer[256];
	int			temp_seed;
	size_t		i;

	seed++;
	i = ft_strlcpy(name_buffer, "/philosophers.sem_unique:", 256);
	temp_seed = seed;
	while (temp_seed > 0)
	{
		name_buffer[i] = (seed % 10) + '0';
		temp_seed /= 10;
		i++;
	}
	name_buffer[i] = '\0';
	return (sem_open_new(name_buffer, value));
}

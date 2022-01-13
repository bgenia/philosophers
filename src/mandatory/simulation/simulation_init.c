/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:03:05 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/13 16:30:36 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include <pthread.h>

#include <philosophers/lib/lib.h>
#include <philosophers/mandatory/philo.h>

static int
	_malloc_arrays(t_simulation *simulation)
{
	simulation->philos = malloc(
			sizeof(*simulation->philos) * simulation->config->philo_count
			);
	simulation->fork_mutexes = malloc(
			sizeof(*simulation->fork_mutexes) * simulation->config->philo_count
			);
	return (!simulation->philos || !simulation->fork_mutexes);
}

static int
	_create_mutexes(t_simulation *simulation)
{
	if (pthread_mutex_init(&simulation->print_mutex, NULL))
		return (-1);
	if (pthread_mutex_init(&simulation->end_mutex, NULL))
		return (-1);
	pthread_mutex_lock(&simulation->end_mutex);
	return (0);
}

int	simulation_init(t_simulation *simulation, t_config *config)
{
	int	i;

	simulation->config = config;
	while (true)
	{
		if (_malloc_arrays(simulation))
			break ;
		i = 0;
		while (i < simulation->config->philo_count)
		{
			simulation->philos[i] = (t_philo){0};
			if (philo_init(&simulation->philos[i], simulation, i))
			{
				i = -1;
				break ;
			}
			i++;
		}
		if (i == -1 || _create_mutexes(simulation))
			break ;
		return (0);
	}
	simulation_destroy(simulation);
	return (-1);
}

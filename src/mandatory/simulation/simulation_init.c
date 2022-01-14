/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:03:05 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/14 14:26:23 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include <pthread.h>

#include <philosophers/lib/lib.h>
#include <philosophers/mandatory/simulation.h>

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
	return (0);
}

static int
	_init_philos_and_forks(t_simulation *simulation)
{
	int	i;

	i = 0;
	while (i < simulation->config->philo_count)
	{
		simulation->philos[i] = (t_philo){0};
		if (philo_init(&simulation->philos[i], simulation, i)
			|| pthread_mutex_init(&simulation->fork_mutexes[i], NULL))
			return (-1);
		i++;
	}
	return (0);
}

int
	simulation_init(t_simulation *simulation, t_config *config)
{
	*simulation = (t_simulation){0};
	simulation->config = config;
	while (true)
	{
		if (_malloc_arrays(simulation))
			break ;
		if (_init_philos_and_forks(simulation))
			break ;
		if (_create_mutexes(simulation))
			break ;
		return (0);
	}
	simulation_destroy(simulation);
	return (-1);
}

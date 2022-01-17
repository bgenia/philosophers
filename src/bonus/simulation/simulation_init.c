/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:03:05 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/17 16:07:24 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include <semaphore.h>

#include <philosophers/lib/lib.h>
#include <philosophers/bonus/simulation.h>
#include <philosophers/bonus/semutils.h>

static int
	_malloc_arrays(t_simulation *simulation)
{
	simulation->philos = malloc(
			sizeof(*simulation->philos) * simulation->config->philo_count
			);
	return (!simulation->philos);
}

static int
	_open_semaphores(t_simulation *simulation)
{
	simulation->print_mutex = sem_open_unique(1);
	if (simulation->print_mutex == SEM_FAILED)
		return (-1);
	simulation->fork_semaphore = sem_open_unique(
			simulation->config->philo_count
			);
	if (simulation->fork_semaphore == SEM_FAILED)
		return (-1);
	simulation->meal_goal_semaphore = sem_open_unique(0);
	if (simulation->meal_goal_semaphore == SEM_FAILED)
		return (-1);
	simulation->end_mutex = sem_open_unique(0);
	if (simulation->end_mutex == SEM_FAILED)
		return (-1);
	return (0);
}

static int
	_init_philos(t_simulation *simulation)
{
	int	i;

	i = 0;
	while (i < simulation->config->philo_count)
	{
		simulation->philos[i] = (t_philo){0};
		if (philo_init(&simulation->philos[i], simulation, i))
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
		if (_init_philos(simulation))
			break ;
		if (_open_semaphores(simulation))
			break ;
		return (0);
	}
	simulation_destroy(simulation);
	return (-1);
}

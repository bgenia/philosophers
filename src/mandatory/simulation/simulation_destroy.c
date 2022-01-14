/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:11:37 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/14 16:04:27 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <pthread.h>

#include <philosophers/mandatory/simulation.h>

void
	simulation_destroy(t_simulation *simulation)
{
	int	i;

	if (simulation->philos)
	{
		i = 0;
		while (i < simulation->config->philo_count)
			philo_destroy(&simulation->philos[i++]);
		free(simulation->philos);
	}
	if (simulation->fork_mutexes)
	{
		i = 0;
		while (i < simulation->config->philo_count)
			pthread_mutex_destroy(&simulation->fork_mutexes[i++]);
		free(simulation->fork_mutexes);
	}
	pthread_mutex_destroy(&simulation->print_mutex);
	pthread_mutex_destroy(&simulation->state_mutex);
}

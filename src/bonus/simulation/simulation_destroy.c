/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:11:37 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/17 16:07:33 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <semaphore.h>

#include <philosophers/bonus/simulation.h>

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
	if (simulation->fork_semaphore)
		sem_close(simulation->fork_semaphore);
	if (simulation->meal_goal_semaphore)
		sem_close(simulation->meal_goal_semaphore);
	if (simulation->print_mutex)
		sem_close(simulation->print_mutex);
	if (simulation->end_mutex)
		sem_close(simulation->end_mutex);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_start_global_monitor.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:21:17 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/18 01:02:12 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include <semaphore.h>

#include <philosophers/bonus/simulation.h>

void
	*simulation_start_global_monitor(t_simulation *simulation)
{
	int	i;

	i = 0;
	while (i < simulation->config->philo_count)
	{
		philo_log(&simulation->philos[i], "in progress");
		sem_wait(simulation->meal_goal_semaphore);
		philo_log(&simulation->philos[i], "finished");
		i++;
	}
	sem_post(simulation->end_mutex);
	return (NULL);
}

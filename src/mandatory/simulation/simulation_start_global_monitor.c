/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_start_global_monitor.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:21:17 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/13 17:33:13 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <pthread.h>

#include <philosophers/mandatory/philo.h>

void
	*simulation_start_global_monitor(t_simulation *simulation)
{
	int	i;

	i = 0;
	while (i < simulation->config->philo_count)
	{
		pthread_mutex_lock(&simulation->philos[i].meal_goal_mutex);
		i++;
	}
	pthread_mutex_unlock(&simulation->end_mutex);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:32:44 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/13 18:04:40 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

#include <philosophers/lib/lib.h>
#include <philosophers/mandatory/simulation.h>

int
	simulation_start(t_simulation *simulation)
{
	int			i;
	pthread_t	thread;
	t_philo		*philo;

	simulation->simulation_start_time = ft_get_time();
	if (simulation->config->meal_count_goal > 0)
	{
		if (pthread_create(&thread, NULL,
				(void *)simulation_start_global_monitor, simulation))
			return (-1);
		pthread_detach(thread);
	}
	i = 0;
	while (i < simulation->config->philo_count)
	{
		philo = &simulation->philos[i];
		philo->last_meal_time = simulation->simulation_start_time;
		if (pthread_create(&thread, NULL, (void *)philo_start_routine, philo))
			return (-1);
		pthread_detach(thread);
		ft_usleep(100);
		i++;
	}
	return (0);
}

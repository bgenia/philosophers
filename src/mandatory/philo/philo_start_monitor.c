/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start_monitor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:55:50 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/14 17:01:57 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include <pthread.h>

#include <philosophers/lib/lib.h>
#include <philosophers/lib/termdefs.h>
#include <philosophers/mandatory/simulation.h>

void
	*philo_start_monitor(t_philo *philo)
{
	while (philo->simulation->is_running)
	{
		pthread_mutex_lock(&philo->death_mutex);
		if (ft_get_time() > philo->last_meal_time
			+ philo->simulation->config->time_to_die * 1000)
		{
			philo_log(philo, TERM_F_RED "died" TERM_RESET);
			break ;
		}
		pthread_mutex_unlock(&philo->death_mutex);
		ft_usleep(1000);
	}
	pthread_mutex_unlock(&philo->death_mutex);
	simulation_stop(philo->simulation);
	philo_return_forks(philo);
	return (NULL);
}

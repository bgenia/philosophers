/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start_monitor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:55:50 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/17 16:08:42 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include <semaphore.h>

#include <philosophers/lib/lib.h>
#include <philosophers/lib/termdefs.h>
#include <philosophers/bonus/simulation.h>

void
	*philo_start_monitor(t_philo *philo)
{
	while (philo->is_alive)
	{
		sem_wait(philo->death_mutex);
		if (ft_get_time() > philo->last_meal_time
			+ philo->simulation->config->time_to_die * 1000)
		{
			philo_log(philo, TERM_F_RED "died" TERM_RESET);
			philo->is_alive = false;
			break ;
		}
		sem_post(philo->death_mutex);
		ft_usleep(1000);
	}
	sem_post(philo->death_mutex);
	philo_return_forks(philo);
	sem_post(philo->simulation->end_mutex);
	return (NULL);
}

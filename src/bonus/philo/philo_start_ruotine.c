/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start_ruotine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:47:09 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/17 16:09:15 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include <pthread.h>

#include <philosophers/lib/lib.h>
#include <philosophers/lib/termdefs.h>
#include <philosophers/bonus/simulation.h>

int
	philo_start_routine(t_philo *philo)
{
	pthread_t	monitor_thread;

	philo->last_meal_time = ft_get_time();
	if (pthread_create(
			&monitor_thread, NULL, (void *) &philo_start_monitor, philo))
		return (PHILO_ERROR);
	pthread_detach(monitor_thread);
	while (philo->is_alive)
	{
		philo_take_forks(philo);
		philo_eat(philo);
		philo_return_forks(philo);
		philo_sleep(philo);
		philo_log(philo, TERM_F_MAGENTA "is thinking" TERM_RESET);
	}
	return (PHILO_OK);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start_ruotine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:47:09 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/13 16:09:13 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include <pthread.h>

#include <philosophers/lib/lib.h>
#include <philosophers/mandatory/philo.h>

void
	*philo_start_routine(t_philo *philo)
{
	pthread_t	monitor_thread;

	philo->last_meal_time = ft_get_time();
	if (pthread_create(
			&monitor_thread, NULL, (void *) &philo_start_monitor, philo))
		return (PHILO_ERROR);
	pthread_detach(monitor_thread);
	while (true)
	{
		philo_take_forks(philo);
		philo_eat(philo);
		philo_return_forks(philo);
		philo_sleep(philo);
		philo_log(philo, "is thinking");
	}
	return (PHILO_OK);
}

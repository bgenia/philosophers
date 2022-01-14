/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_take_return_forks.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:35:03 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/13 18:56:27 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

#include <philosophers/mandatory/simulation.h>

static inline pthread_mutex_t
	*_get_left_fork(t_philo *philo)
{
	return (&philo->simulation->fork_mutexes[philo->index]);
}

static inline pthread_mutex_t
	*_get_right_fork(t_philo *philo)
{
	int	fork_index;

	fork_index = (philo->index + 1) % philo->simulation->config->philo_count;
	return (&philo->simulation->fork_mutexes[fork_index]);
}

void
	philo_take_forks(t_philo *philo)
{
	pthread_mutex_lock(_get_left_fork(philo));
	philo_log(philo, "has taken a fork");
	pthread_mutex_lock(_get_right_fork(philo));
	philo_log(philo, "has taken a fork");
}

void
	philo_return_forks(t_philo *philo)
{
	pthread_mutex_unlock(_get_left_fork(philo));
	pthread_mutex_unlock(_get_right_fork(philo));
}

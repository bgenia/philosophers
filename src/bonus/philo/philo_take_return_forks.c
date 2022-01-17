/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_take_return_forks.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:35:03 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/16 18:06:55 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>

#include <philosophers/lib/termdefs.h>
#include <philosophers/bonus/simulation.h>

void
	philo_take_forks(t_philo *philo)
{
	sem_wait(philo->simulation->fork_semaphore);
	philo_log(philo, TERM_F_YELLOW "has taken a fork" TERM_RESET);
	sem_wait(philo->simulation->fork_semaphore);
	philo_log(philo, TERM_F_YELLOW "has taken a fork" TERM_RESET);
}

void
	philo_return_forks(t_philo *philo)
{
	sem_post(philo->simulation->fork_semaphore);
	sem_post(philo->simulation->fork_semaphore);
}

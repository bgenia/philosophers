/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:42:16 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/16 18:14:49 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>

#include <philosophers/lib/lib.h>
#include <philosophers/lib/termdefs.h>
#include <philosophers/bonus/simulation.h>

void
	philo_eat(t_philo *philo)
{
	sem_wait(philo->death_mutex);
	philo->last_meal_time = ft_get_time();
	philo_log(philo, TERM_F_GREEN "is eating" TERM_RESET);
	ft_usleep(philo->simulation->config->time_to_eat * 1000);
	philo->meal_count++;
	if (philo->meal_count >= philo->simulation->config->meal_count_goal)
		sem_post(philo->simulation->meal_goal_semaphore);
	sem_post(philo->death_mutex);
}

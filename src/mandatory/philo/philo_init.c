/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:11:12 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/13 18:04:40 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

#include <philosophers/mandatory/simulation.h>

int
	philo_init(t_philo *philo, t_simulation *simulation, int index)
{
	philo->simulation = simulation;
	philo->index = index;
	philo->is_alive = true;
	if (pthread_mutex_init(&philo->death_mutex, NULL))
		return (-1);
	if (pthread_mutex_init(&philo->meal_goal_mutex, NULL))
		return (-1);
	pthread_mutex_lock(&philo->meal_goal_mutex);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:52:07 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/13 18:52:53 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

#include <philosophers/mandatory/simulation.h>

void
	philo_destroy(t_philo *philo)
{
	pthread_mutex_destroy(&philo->death_mutex);
	pthread_mutex_destroy(&philo->meal_goal_mutex);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:11:12 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/16 18:29:08 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>

#include <philosophers/bonus/simulation.h>
#include <philosophers/bonus/semutils.h>

int
	philo_init(t_philo *philo, t_simulation *simulation, int index)
{
	philo->simulation = simulation;
	philo->index = index;
	philo->is_alive = true;
	philo->death_mutex = sem_open_unique(1);
	if (philo->death_mutex == SEM_FAILED)
		return (-1);
	return (0);
}

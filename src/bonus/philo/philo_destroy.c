/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:52:07 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/16 18:24:24 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>

#include <philosophers/bonus/simulation.h>

void
	philo_destroy(t_philo *philo)
{
	if (philo->death_mutex)
		sem_close(philo->death_mutex);
}

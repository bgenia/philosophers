/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:29:34 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/13 16:12:56 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <pthread.h>

#include <philosophers/lib/lib.h>
#include <philosophers/mandatory/philo.h>

void
	philo_log(t_philo *philo, const char *message)
{
	uint64_t	timestamp;

	timestamp = ft_get_time() - philo->simulation->simulation_start_time;
	pthread_mutex_lock(&philo->simulation->print_mutex);
	printf("%lu p%d %s\n", timestamp / 1000, philo->index + 1, message);
	pthread_mutex_unlock(&philo->simulation->print_mutex);
}

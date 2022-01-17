/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:29:34 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/17 16:09:06 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <semaphore.h>

#include <philosophers/lib/lib.h>
#include <philosophers/lib/termdefs.h>
#include <philosophers/bonus/simulation.h>

void
	philo_log(t_philo *philo, const char *message)
{
	uint64_t	timestamp;

	timestamp = ft_get_time() - philo->simulation->simulation_start_time;
	sem_wait(philo->simulation->print_mutex);
	if (philo->is_alive)
		printf(
			TERM_F_LIGHT_BLUE "ms%-12lu"
			TERM_F_WHITE " p%-4d %s\n" TERM_RESET,
			timestamp / 1000,
			philo->index + 1,
			message
			);
	sem_post(philo->simulation->print_mutex);
}

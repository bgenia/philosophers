/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:51:55 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/16 18:06:02 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers/lib/lib.h>
#include <philosophers/lib/termdefs.h>
#include <philosophers/bonus/simulation.h>

void
	philo_sleep(t_philo *philo)
{
	philo_log(philo, TERM_F_CYAN "is sleeping" TERM_RESET);
	ft_usleep(philo->simulation->config->time_to_sleep * 1000);
}

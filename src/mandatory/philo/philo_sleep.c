/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:51:55 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/14 17:01:29 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers/lib/lib.h>
#include <philosophers/lib/termdefs.h>
#include <philosophers/mandatory/simulation.h>

void
	philo_sleep(t_philo *philo)
{
	philo_log(philo, TERM_F_GREY "is sleeping" TERM_RESET);
	ft_usleep(philo->simulation->config->time_to_sleep * 1000);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_stop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:01:45 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/17 16:09:25 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include <semaphore.h>

#include <philosophers/bonus/simulation.h>

void
	simulation_stop(t_simulation *simulation)
{
	int	i;

	i = 0;
	while (i < simulation->config->philo_count)
		kill(simulation->philos[i++].pid, SIGKILL);
}

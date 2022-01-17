/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_await.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:05:16 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/18 01:10:32 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <signal.h>

#include <philosophers/bonus/simulation.h>
#include <philosophers/bonus/process.h>

int
	simulation_await(t_simulation *simulation)
{
	int	status;
	int	i;

	sem_wait(simulation->end_mutex);
	simulation_stop(simulation);
	status = PHILO_OK;
	i = 0;
	while (i < simulation->config->philo_count && status != PHILO_ERROR)
		process_join(simulation->philos[i++].pid, &status, 0);
	if (status == PHILO_ERROR)
	{
		while (i < simulation->config->philo_count)
			kill(simulation->philos[i++].pid, SIGKILL);
		return (-1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_await.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:05:16 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/14 13:58:08 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

#include <philosophers/mandatory/simulation.h>

int
	simulation_await(t_simulation *simulation)
{
	t_philo_status	status;
	int				i;

	status = PHILO_OK;
	i = 0;
	while (i < simulation->config->philo_count && status != PHILO_ERROR)
		pthread_join(simulation->philos[i++].thread, &status);
	if (status == PHILO_ERROR)
	{
		while (i < simulation->config->philo_count)
			pthread_detach(simulation->philos[i++].thread);
		return (-1);
	}
	return (0);
}

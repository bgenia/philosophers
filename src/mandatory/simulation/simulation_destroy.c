/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:11:37 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/13 15:29:13 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <pthread.h>

#include <philosophers/mandatory/philo.h>

void	simulation_destroy(t_simulation *app)
{
	int	i;

	free(app->philos);
	if (app->fork_mutexes)
	{
		i = 0;
		while (i < app->config->philo_count)
			pthread_mutex_destroy(&app->fork_mutexes[i++]);
	}
	free(app->fork_mutexes);
	pthread_mutex_destroy(&app->print_mutex);
}

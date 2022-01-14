/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_stop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:01:45 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/14 16:04:57 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

#include <philosophers/mandatory/simulation.h>

void
	simulation_stop(t_simulation *simulation)
{
	pthread_mutex_lock(&simulation->state_mutex);
	simulation->is_running = false;
	pthread_mutex_unlock(&simulation->state_mutex);
}

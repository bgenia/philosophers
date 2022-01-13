/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_await.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:05:16 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/13 18:04:40 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

#include <philosophers/mandatory/simulation.h>

void
	simulation_await(t_simulation *simulation)
{
	pthread_mutex_lock(&simulation->end_mutex);
	pthread_mutex_unlock(&simulation->end_mutex);
}

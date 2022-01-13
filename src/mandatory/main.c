/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:25:05 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/13 16:26:31 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

#include <unistd.h>

#include <pthread.h>

#include <philosophers/lib/lib.h>
#include <philosophers/mandatory/philo.h>

int
	main(int argc, char **argv)
{
	t_config		config;
	t_simulation	simulation;

	if (config_parse(&config, argc, argv))
		return (1);
	if (simulation_init(&simulation, &config))
		return (2);
	if (simulation_start(&simulation))
		return (3);
	simulation_await(&simulation);
	simulation_destroy(&simulation);
	return (0);
}

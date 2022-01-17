/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 07:18:01 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/17 19:14:06 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include <philosophers/lib/lib.h>
#include <philosophers/common/config.h>
#include <philosophers/common/utils.h>
#include <philosophers/bonus/semutils.h>
#include <philosophers/bonus/simulation.h>

int	main(int argc, char **argv)
{
	t_config		config;
	t_simulation	simulation;
	int				status;

	if (config_parse(&config, argc, argv))
		return (exit_error(1, "Error: Invalid arguments"));
	if (simulation_init(&simulation, &config))
		return (exit_error(2, "Error: Unable to initialize simulation"));
	status = 0;
	while (true)
	{
		if (simulation_start(&simulation))
		{
			status = exit_error(3, "Error: Unable to start simulation");
			break ;
		}
		if (simulation_await(&simulation))
		{
			status = exit_error(4, "Error: Simulation failed due to an error");
			break ;
		}
		break ;
	}
	simulation_destroy(&simulation);
	return (status);
}

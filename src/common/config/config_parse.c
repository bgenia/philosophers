/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:13:10 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/18 15:32:15 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers/lib/lib.h>
#include <philosophers/mandatory/simulation.h>

static int
	_validate_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			if (!ft_isdigit(argv[i][j++]))
				return (-1);
		i++;
	}
	return (0);
}

int
	config_parse(t_config *config, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (-1);
	if (_validate_args(argc, argv))
		return (-1);
	config->philo_count = ft_atoi(argv[1]);
	config->time_to_die = ft_atoi(argv[2]);
	config->time_to_eat = ft_atoi(argv[3]);
	config->time_to_sleep = ft_atoi(argv[4]);
	config->meal_count_goal = -1;
	if (argc == 6)
		config->meal_count_goal = ft_atoi(argv[5]);
	return (0);
}

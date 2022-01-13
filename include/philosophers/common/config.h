/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:53:09 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/13 18:04:18 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

typedef struct s_config
{
	int				philo_count;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	uint64_t		time_to_die;
	int				meal_count_goal;
}	t_config;

int
config_parse(t_config *config, int argc, char **argv);

#endif

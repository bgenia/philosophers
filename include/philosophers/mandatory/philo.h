/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 07:40:35 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/13 17:35:52 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <inttypes.h>

# define PHILO_ERROR (void *) -1
# define PHILO_OK (void *) 0

typedef void				*t_philo_status;

typedef struct s_simulation	t_simulation;

typedef struct s_philo
{
	int				index;
	int				meal_count;
	uint64_t		last_meal_time;
	bool			is_alive;
	pthread_t		thread;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	meal_goal_mutex;
	t_simulation	*simulation;
}	t_philo;

int
philo_init(t_philo *philo, t_simulation *app, int index);
void
philo_destroy(t_philo *philo);

void
philo_log(t_philo *philo, const char *message);

void
*philo_start_monitor(t_philo *philo);
void
*philo_start_routine(t_philo *philo);

void
philo_take_forks(t_philo *philo);
void
philo_return_forks(t_philo *philo);
void
philo_eat(t_philo *philo);

void
philo_sleep(t_philo *philo);

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

struct s_simulation
{
	t_config		*config;
	uint64_t		simulation_start_time;
	int				meal_goal_reached;
	t_philo			*philos;
	pthread_mutex_t	*fork_mutexes;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	end_mutex;
};

int
simulation_init(t_simulation *simulation, t_config *config);
void
simulation_destroy(t_simulation *simulation);

void
*simulation_start_global_monitor(t_simulation *simulation);

int
simulation_start(t_simulation *simulation);

void
simulation_await(t_simulation *simulation);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:53:54 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/14 16:05:48 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include <stdbool.h>
# include <inttypes.h>

# include <pthread.h>

# include <philosophers/common/config.h>

typedef struct s_simulation	t_simulation;
typedef struct s_philo		t_philo;

struct s_simulation
{
	t_config		*config;
	uint64_t		simulation_start_time;
	int				meal_goal_reached;
	t_philo			*philos;
	pthread_mutex_t	*fork_mutexes;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	state_mutex;
	bool			is_running;
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
simulation_stop(t_simulation *simulation);

int
simulation_await(t_simulation *simulation);

struct s_philo
{
	int				index;
	int				meal_count;
	uint64_t		last_meal_time;
	bool			is_alive;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	meal_goal_mutex;
	t_simulation	*simulation;
	pthread_t		thread;
};

typedef void				*t_philo_status;

# define PHILO_OK (void *) 0
# define PHILO_ERROR (void *) -1

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

#endif

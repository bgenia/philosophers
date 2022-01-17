/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:02:44 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/18 00:54:44 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>
#include <philosophers/bonus/simulation.h>

int
	process_create(pid_t *pid, int (*routine) (void *), void *arg)
{
	*pid = fork();
	if (*pid == 0)
	{
		int s = routine(arg);
		printf(">> Philo %d exiting: %d\n", ((t_philo *)arg)->index + 1, s);
		exit(s);
	}
	if (*pid == -1)
		return (-1);
	return (0);
}

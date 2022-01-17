/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:02:44 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/18 01:11:06 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#include <philosophers/bonus/simulation.h>

int
	process_create(pid_t *pid, int (*routine) (void *), void *arg)
{
	*pid = fork();
	if (*pid == 0)
		exit(routine(arg));
	if (*pid == -1)
		return (-1);
	return (0);
}

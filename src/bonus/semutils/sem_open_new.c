/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_open_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:16:39 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/16 17:54:28 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <philosophers/lib/lib.h>

sem_t
	*sem_open_new(const char *name, int value)
{
	sem_unlink(name);
	return (sem_open(name, O_CREAT | O_EXCL, S_IRWXU, value));
}

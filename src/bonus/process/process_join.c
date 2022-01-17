/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:08:17 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/16 13:12:16 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

pid_t
	process_join(pid_t pid, int *result, int options)
{
	return (waitpid(pid, result, options));
}

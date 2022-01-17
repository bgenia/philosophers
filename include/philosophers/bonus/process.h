/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 12:56:52 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/16 13:12:09 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include <sys/types.h>

int
process_create(pid_t *pid, int *(*routine) (void *), void *arg);

pid_t
process_join(pid_t pid, int *result, int options);

#endif

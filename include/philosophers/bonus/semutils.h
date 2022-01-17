/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semutils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:20:35 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/16 18:29:32 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEMUTILS_H
# define SEMUTILS_H

# include <semaphore.h>

sem_t
*sem_open_new(const char *name, int value);

sem_t
*sem_open_unique(int value);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:25:17 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/14 14:16:43 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <inttypes.h>
#include <sys/time.h>

uint64_t
	ft_get_time(void)
{
	uint64_t			time;
	struct timeval		current_time;

	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000 * 1000) + (current_time.tv_usec);
	return (time);
}

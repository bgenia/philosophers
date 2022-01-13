/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:18:14 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/11 17:29:11 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/time.h>
#include <inttypes.h>

#include <philosophers/lib/lib.h>

void	ft_usleep(uint64_t us)
{
	uint64_t	start_time;

	start_time = ft_get_time();
	while ((ft_get_time() - start_time) < us)
		usleep(us / 10);
}

void	ft_uhalt(uint64_t us)
{
	uint64_t	start_time;

	start_time = ft_get_time();
	while ((ft_get_time() - start_time) < us)
		;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:01:21 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/14 14:17:29 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers/lib/lib.h>

void
	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*start;
	size_t			i;

	start = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (start[i] == (unsigned char)c)
			return (start + i);
		i++;
	}
	return (NULL);
}

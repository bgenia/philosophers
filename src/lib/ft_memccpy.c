/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:01:18 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/14 14:17:26 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers/lib/lib.h>

void
	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*dst_str;
	const unsigned char	*src_str;

	i = 0;
	dst_str = (unsigned char *)dst;
	src_str = (const unsigned char *)src;
	while (i < n)
	{
		dst_str[i] = src_str[i];
		if (src_str[i] == (unsigned char) c)
			break ;
		i++;
	}
	if (i == n)
		return (NULL);
	return (dst + i + 1);
}

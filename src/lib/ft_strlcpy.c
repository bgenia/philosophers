/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:02:14 by bgenia            #+#    #+#             */
/*   Updated: 2021/12/11 19:40:14 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers/lib/lib.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_length;
	size_t	n;

	if (src == NULL)
		return (0);
	src_length = ft_strlen(src);
	if (dstsize == 0)
		return (src_length);
	if (src_length < dstsize)
		n = src_length + 1;
	else
		n = dstsize;
	ft_memcpy(dst, src, n - 1);
	dst[n - 1] = '\0';
	return (src_length);
}

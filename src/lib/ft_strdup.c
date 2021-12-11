/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:02:09 by bgenia            #+#    #+#             */
/*   Updated: 2021/12/11 19:40:14 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <philosophers/lib/lib.h>

char	*ft_strdup(const char *str)
{
	char	*copy;
	size_t	length;

	length = ft_strlen(str);
	copy = malloc(sizeof(*copy) * length + 1);
	if (!copy)
		return (NULL);
	ft_memcpy(copy, str, length + 1);
	return (copy);
}

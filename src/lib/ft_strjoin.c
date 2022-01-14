/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:02:12 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/14 14:18:10 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers/lib/lib.h>

static size_t
	protected_strlen(char *str)
{
	if (str)
		return (ft_strlen(str));
	return (0);
}

char
	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_length;
	size_t	s2_length;
	char	*result;

	s1_length = protected_strlen((char *) s1);
	s2_length = protected_strlen((char *) s2);
	result = malloc(sizeof(*result) * (s1_length + s2_length + 1));
	if (!result)
		return (NULL);
	if (s1)
		ft_memcpy(result, s1, s1_length);
	if (s2)
		ft_memcpy(&result[s1_length], s2, s2_length + 1);
	if (!s1 && !s2)
		result[0] = '\0';
	return (result);
}

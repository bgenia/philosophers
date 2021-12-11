/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:02:25 by bgenia            #+#    #+#             */
/*   Updated: 2021/12/11 19:40:14 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers/lib/lib.h>

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	size_t	str_length;
	char	*result;
	size_t	i;

	if (!str)
		str_length = 0;
	else
		str_length = ft_strlen(str);
	result = malloc(sizeof(*result) * (str_length + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (str && str[i])
	{
		result[i] = f(i, str[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

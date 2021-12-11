/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_values.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:01:02 by bgenia            #+#    #+#             */
/*   Updated: 2021/12/11 19:40:14 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers/lib/lib.h>

void	ft_list_reverse_values(t_list *list)
{
	size_t	size;
	size_t	i;
	size_t	j;

	size = ft_list_size(list);
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			ft_list_swap_values(list, i, j);
			j++;
		}
		i++;
	}
}

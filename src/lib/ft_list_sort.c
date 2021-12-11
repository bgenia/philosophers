/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:01:08 by bgenia            #+#    #+#             */
/*   Updated: 2021/12/11 19:40:14 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers/lib/lib.h>

void	ft_list_sort(t_list **list, int (*comparator)())
{
	size_t	i;
	size_t	j;
	void	*a;
	void	*b;
	size_t	size;

	i = 0;
	size = ft_list_size(*list);
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			a = ft_list_at(*list, j)->value;
			b = ft_list_at(*list, j + 1)->value;
			if (comparator(a, b) > 0)
				ft_list_swap_elements(list, j, j + 1);
			j++;
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_from.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:00:48 by bgenia            #+#    #+#             */
/*   Updated: 2021/12/11 19:40:14 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers/lib/lib.h>

t_list	*ft_list_from(int count, void **values, void (*_free)(void *))
{
	int		i;
	t_list	*list;
	t_list	*current_element;

	i = 0;
	list = NULL;
	while (i < count)
	{
		current_element = ft_list_create(values[i]);
		if (!current_element)
		{
			ft_list_clear(&list, _free);
			return (list);
		}
		ft_list_add_back(&list, current_element);
		i++;
	}
	return (list);
}

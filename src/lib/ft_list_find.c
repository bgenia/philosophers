/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:00:42 by bgenia            #+#    #+#             */
/*   Updated: 2021/12/11 19:40:14 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers/lib/lib.h>

t_list	*ft_list_find(t_list *list, void *value, int (*comparator)())
{
	t_list	*current_element;

	current_element = list;
	while (current_element)
	{
		if (comparator(current_element->value, value) == 0)
			return (current_element);
		current_element = current_element->next;
	}
	return (NULL);
}

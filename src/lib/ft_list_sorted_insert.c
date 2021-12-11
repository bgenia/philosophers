/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sorted_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:01:11 by bgenia            #+#    #+#             */
/*   Updated: 2021/12/11 19:40:14 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers/lib/lib.h>

void	ft_list_sorted_insert(t_list **list, void *value, int (*comparator)())
{
	t_list	*element;
	t_list	*prev_element;
	t_list	*current_element;

	element = ft_list_create(value);
	if (!element)
		return ;
	prev_element = NULL;
	current_element = *list;
	if (!current_element
		|| comparator(current_element->value, element->value) > 0)
	{
		element->next = current_element;
		*list = element;
		return ;
	}
	while (current_element
		&& comparator(current_element->value, element->value) <= 0)
	{
		prev_element = current_element;
		current_element = current_element->next;
	}
	ft_list_insert_after(prev_element, element);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:01:00 by bgenia            #+#    #+#             */
/*   Updated: 2021/12/11 19:40:14 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers/lib/lib.h>

void	ft_list_remove_if(
	t_list **list,
	void *value,
	int (*comparator)(),
	void (*_free)(void *)
)
{
	t_list	*prev_element;
	t_list	*current_element;
	t_list	*temp_element;

	prev_element = NULL;
	current_element = *list;
	while (current_element)
	{
		if (comparator(current_element->value, value) == 0)
		{
			_free(current_element->value);
			temp_element = current_element->next;
			if (prev_element)
				prev_element->next = current_element->next;
			else
				*list = current_element->next;
			free(current_element);
			current_element = temp_element;
		}
		else
		{
			prev_element = current_element;
			current_element = current_element->next;
		}
	}
}

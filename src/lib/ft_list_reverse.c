/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:01:05 by bgenia            #+#    #+#             */
/*   Updated: 2021/12/11 19:40:14 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers/lib/lib.h>

void	ft_list_reverse(t_list **list)
{
	t_list	*prev_element;
	t_list	*current_element;
	t_list	*temp_element;

	prev_element = NULL;
	current_element = *list;
	while (current_element)
	{
		temp_element = current_element->next;
		if (prev_element)
			current_element->next = prev_element;
		else
			current_element->next = NULL;
		prev_element = current_element;
		current_element = temp_element;
	}
	*list = prev_element;
}

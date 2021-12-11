/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sorted_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:01:12 by bgenia            #+#    #+#             */
/*   Updated: 2021/12/11 19:40:14 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers/lib/lib.h>

void	ft_list_sorted_merge(
	t_list **list1,
	t_list *list2,
	int (*comparator)()
)
{
	t_list	*current_element;
	t_list	*temp_element;

	current_element = list2;
	while (current_element)
	{
		temp_element = current_element->next;
		ft_list_sorted_insert(list1, current_element, comparator);
		current_element = temp_element;
	}
}

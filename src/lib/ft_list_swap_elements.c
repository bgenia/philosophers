/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_swap_elements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:01:14 by bgenia            #+#    #+#             */
/*   Updated: 2021/12/11 19:40:14 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers/lib/lib.h>

void	ft_list_swap_elements(
	t_list **list,
	unsigned int index1,
	unsigned int index2
)
{
	t_list	*first_element;
	t_list	*second_element;
	t_list	*temp_element;

	first_element = ft_list_at(*list, index1);
	second_element = ft_list_at(*list, index2);
	if (index1 > 0)
	{
		temp_element = ft_list_at(*list, index1 - 1);
		temp_element->next = second_element;
	}
	else
	{
		*list = second_element;
	}
	temp_element = second_element->next;
	second_element->next = first_element->next;
	first_element->next = temp_element;
	temp_element = ft_list_at(*list, index2 - 1);
	temp_element->next = first_element;
}

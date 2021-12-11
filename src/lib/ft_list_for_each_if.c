/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_for_each_if.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:00:44 by bgenia            #+#    #+#             */
/*   Updated: 2021/12/11 19:40:14 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers/lib/lib.h>

void	ft_list_for_each_if(
	t_list *list,
	void (*f)(void *),
	void *value,
	int (*comparator)()
)
{
	t_list	*current_element;

	current_element = list;
	while (current_element)
	{
		if (comparator(current_element->value, value) == 0)
			f(current_element->value);
		current_element = current_element->next;
	}
}

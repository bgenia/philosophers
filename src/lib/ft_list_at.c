/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:00:35 by bgenia            #+#    #+#             */
/*   Updated: 2021/12/11 19:40:14 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers/lib/lib.h>

t_list	*ft_list_at(t_list *list, unsigned int index)
{
	unsigned int	i;
	t_list			*current_element;

	i = 0;
	current_element = list;
	while (current_element && i < index)
	{
		i++;
		current_element = current_element->next;
	}
	if (i != index)
		return (NULL);
	return (current_element);
}

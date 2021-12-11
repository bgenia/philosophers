/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_swap_values.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:01:17 by bgenia            #+#    #+#             */
/*   Updated: 2021/12/11 19:40:14 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers/lib/lib.h>

void	ft_list_swap_values(
	t_list *list,
	unsigned int index1,
	unsigned int index2
)
{
	t_list	*element1;
	t_list	*element2;
	void	*temp_value;

	element1 = ft_list_at(list, index1);
	element2 = ft_list_at(list, index2);
	temp_value = element1->value;
	element1->value = element2->value;
	element2->value = temp_value;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:00:56 by bgenia            #+#    #+#             */
/*   Updated: 2021/12/11 19:40:14 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers/lib/lib.h>

t_list	*ft_list_map(t_list *list, void *(*f)(void *), void (*_free)(void *))
{
	t_list	*result;
	t_list	*result_current;
	t_list	*lst_current;

	result = NULL;
	lst_current = list;
	while (lst_current)
	{
		result_current = ft_list_create(f(lst_current->value));
		if (!result_current)
		{
			ft_list_clear(&result, _free);
			break ;
		}
		ft_list_add_back(&result, result_current);
		lst_current = lst_current->next;
	}
	return (result);
}

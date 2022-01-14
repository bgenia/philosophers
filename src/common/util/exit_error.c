/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:05:50 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/14 14:13:03 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <philosophers/lib/lib.h>

int
	exit_error(int code, char *message)
{
	ft_putendl_fd(message, STDERR_FILENO);
	return (code);
}

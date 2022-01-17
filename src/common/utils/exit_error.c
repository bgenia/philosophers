/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:05:50 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/14 17:04:33 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <philosophers/lib/lib.h>
#include <philosophers/lib/termdefs.h>

int
	exit_error(int code, char *message)
{
	ft_putendl_fd(TERM_F_RED, STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
	ft_putendl_fd(TERM_RESET, STDERR_FILENO);
	return (code);
}

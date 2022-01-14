/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:01:36 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/14 14:16:43 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers/lib/lib.h>

static void	print_digit(int n, int fd)
{
	ft_putchar_fd(n + '0', fd);
}

static void	print_positive_number(long n, int fd)
{
	if (n >= 10)
	{
		print_positive_number(n / 10, fd);
		print_positive_number(n % 10, fd);
	}
	else
	{
		print_digit(n, fd);
	}
}

void
	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		print_positive_number(-(long)n, fd);
	}
	else
	{
		print_positive_number(n, fd);
	}
}

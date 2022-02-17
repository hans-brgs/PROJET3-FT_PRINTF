/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:05:48 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/02/17 10:03:54 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf_p (va_list arg) 
{
	int	size;
	int add;

	size = 0;
	add = va_arg(arg, int);
	size += ft_putnbr_base_fd (add, "0123456789abcdef", 1);
	return(size);
}
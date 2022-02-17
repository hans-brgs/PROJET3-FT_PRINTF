/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:05:48 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/02/17 19:23:44 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf_p (va_list arg) 
{
	int	size;
	unsigned long long int add;

	size = 0;
	add = va_arg(arg, unsigned long long int);
	size += ft_putstr_fd("0x", 2);
	size = ft_putnbr_base_fd (add, "0123456789abcdef", 1);
	return(size);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:05:48 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/02/17 20:56:47 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf_p (va_list arg) 
{
	int	size;
	unsigned long long int add;

	size = 0;
	add = (unsigned long long int)va_arg(arg, void *);
	if (add == 0)
	{
		size += ft_putstr_fd("0x0", 1);
		return(size);
	}
	size += ft_putstr_fd("0x", 1);
	size += ft_putnbr_base_fd (add, "0123456789abcdef", 1);
	return(size);
}
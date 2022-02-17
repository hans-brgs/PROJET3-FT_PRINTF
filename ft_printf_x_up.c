/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:03:07 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/02/17 14:25:20 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf_x_up (va_list arg) 
{
	int	size;
	int hex_up;
	
	size = 0;
	hex_up = va_arg(arg, int);
	size += ft_putstr_fd("0x", 2);
	ft_putnbr_base_fd (hex_up, "0123456789ABCDEF", 1);
	return (size);
}
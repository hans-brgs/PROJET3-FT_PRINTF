/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_low.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:02:49 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/02/17 16:56:17 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf_x_low (va_list arg) 
{
	int	size;
	size_t	hex_low;
	
	size = 0;
	hex_low = (size_t)va_arg(arg, int);
	size = ft_putnbr_base_fd (hex_low, "0123456789abcdef", 1);
	return(size);
}
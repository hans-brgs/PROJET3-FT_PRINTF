/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 08:42:18 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/02/17 19:55:14 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"
#include <stdlib.h>

int	ft_printf_c(va_list arg);
int ft_printf_d (va_list arg);
int ft_printf_i (va_list arg);
int ft_printf_p (va_list arg);
int ft_printf_per ();
int ft_printf_s (va_list arg);
int ft_printf_u (va_list arg);
int ft_printf_x_low (va_list arg);
int ft_printf_x_up (va_list arg);
int ft_printf(const char *str, ...);

#endif
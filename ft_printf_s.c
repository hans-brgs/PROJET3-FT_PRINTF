/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:05:56 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/02/17 19:46:28 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf_s (va_list arg)
{
	int	size;
	char	*str;

	size = 0;
	str = va_arg(arg, char *);
	if (str == 0)
		str = ft_strdup("(null)");
	while (*str)
	{
		size += write(1,str,1);
		str++;
	}
	free(str);
	return (size);
}
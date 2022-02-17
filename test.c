/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 08:23:29 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/02/17 10:20:50 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_putchar_fd(char c, int fd)
{
	int size;
	
	size = 0;
	if (fd < 0)
		return (size) ;
	size = write(fd, &c, sizeof(char));
	return (size) ;
}

int	ft_putnbr_fd(int n, int fd)
{
	int 			size;
	unsigned int	n_bis;

	size = 0;
	n_bis = 0;
	if (n < 0)
	{
		n_bis = -n;
		size += ft_putchar_fd('-', fd);
	}
	else
		n_bis = n;
	if (n_bis > 9)
	{
		ft_putnbr_fd(n_bis / 10, fd);
		ft_putnbr_fd(n_bis % 10, fd);
	}
	else
		size += ft_putchar_fd(n_bis + '0', fd);
	return (size);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size])
	{
		size++;
	}
	return (size);
}

static size_t check_base(char *base)
{
	size_t i;
	size_t j;
	
	i = 0;
	j = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] < 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return(0);
			j++;
		}
		i++;
	}
	return (i);
}

int ft_putnbr_base_fd (int nbr, char *base, int fd)
{
	unsigned int	nbr_bis;
	size_t			size_base;
	int			size;
	
	size = 0;
	nbr_bis = 0;
	size_base = check_base(base);
	if (!size_base)
		return (size);
	if (nbr < 0)
	{
		nbr_bis = -nbr;
		size += ft_putchar_fd('-', fd);
	}
	else
		nbr_bis = nbr;
	if (nbr_bis > size_base - 1)
	{
		ft_putnbr_base_fd(nbr_bis / size_base, base, fd);
		ft_putnbr_base_fd(nbr_bis % size_base, base, fd);
	}
	else
		size += ft_putchar_fd(base[nbr_bis], fd);
	return (size);
}

int ft_printf_c(va_list arg)
{
	int	size;
	char	c;

	size = 0;
	c = va_arg(arg, int);
	size = write(1, &c, 1);
	return (size);
}

int ft_printf_s (va_list arg)
{
	int	size;
	char	*str;

	size = 0;
	str = va_arg(arg, char *);
	if (str == NULL)
		return(size);
	while (*str)
	{
		size += write(1,str,1);
		str++;
	}
	return (size);
}

int ft_printf_p (va_list arg) 
{
	int	size;
	int add;

	size = 0;
	add = va_arg(arg, int);
	size += ft_putnbr_base_fd (add, "0123456789abcdef", 1);
	return(size);
}

int ft_printf_d (va_list arg) 
{
	int	size;
	int add;

	size = 0;
	add = va_arg(arg, int);
	size += ft_putnbr_fd (add, 1);
	return(size);
}

// int ft_printf_i (va_list arg) 
// {
// 	int	size;

// 	size = 0;
// 	return(size);
// }

// int ft_printf_u (va_list arg) 
// {
// 	int	size;

// 	size = 0;
// 	return(size);
// }

int ft_printf_x (va_list arg) 
{
	int	size;
	int	hex_low;
	
	size = 0;
	hex_low = va_arg(arg, int);
	ft_putnbr_base_fd (hex_low, "0123456789abcdef", 1);
	return(size);
}

int ft_printf_X (va_list arg) 
{
	int	size;
	int hex_up;
	
	size = 0;
	hex_up = va_arg(arg, int);
	ft_putnbr_base_fd (hex_up, "0123456789ABCDEF", 1);
	return (size);
}

int ft_printf_per () 
{
	int	size;
	char	c;
	
	size = 0;
	c = '%';
	size = write(1, &c, 1);
	return (size);
}

int write_args(char c, va_list arg)
{
	int	size;

	size = 0;
	if (c == 'c')
		size +=  ft_printf_c(arg);
	else if (c == 's')
		size +=  ft_printf_s(arg);
	else if (c == 'p')
		size +=  ft_printf_p(arg);
	else if (c == 'd')
		size +=  ft_printf_d(arg);
	// else if (c == 'i')
	// 	size +=  ft_printf_i(arg);
	// else if (c == 'u')
	// 	size +=  ft_printf_u(arg);
	else if (c == 'x')
		size +=  ft_printf_x(arg);
	else if (c == 'X')
		size +=  ft_printf_X(arg);
	else if (c == '%')
		size +=  ft_printf_per();
	else 
		return 0 ;
	return (size) ;
}

int ft_printf(const char *str, ...)
{
	int		size;
	va_list	arg;
	
	size = 0;
	va_start(arg, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			size += write_args(str[0], arg);
		}
		else
			size += write(1,str,1);
		str++;
	}
	va_end(arg);
	return(size);
}

int main()
{
	int size1; 
	int size2; 
	
	size1 = printf(" NULL %s NULL ", NULL);
	size2 = ft_printf(" NULL %s NULL ", NULL);

	printf("size1 = %d, size2 = %d", size1, size2);
}
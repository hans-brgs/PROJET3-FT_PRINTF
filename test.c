/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 08:23:29 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/02/18 08:44:20 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"
#include <limits.h> 
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_convert_hex(size_t nb)
{
	char		tmp;
	static int	i;

	i = 0;
	if (nb != 0)
	{
		ft_convert_hex(nb / 16);
		if (nb % 16 < 10)
			tmp = nb % 16 + 48;
		else
			tmp = (nb % 16) - 10 + 'a';
		write(1, &tmp, 1);
		i++;
	}
	return (i);
}

int	ft_putchar_fd(char c, int fd)
{
	int size;
	
	size = 0;
	if (fd < 0)
		return (size) ;
	size += write(fd, &c, sizeof(char));
	return (size) ;
}

int	ft_putnbr_fd(int n, int fd)
{
	static int		size;
	unsigned int	n_bis;

	size = 0;
	n_bis = 0;
	if (n < 0)
	{
		n_bis = -n;
		ft_putchar_fd('-', fd);
	}
	else
		n_bis = n;
	if (n_bis > 9)
	{
		ft_putnbr_fd(n_bis / 10, fd);
		n_bis %= 10;
	}
	if (n_bis < 10)
		size += ft_putchar_fd(n_bis + '0', fd);
	if (n < 0)
		size ++;
	return (size);
}

int	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	static int		size;
	unsigned long long int	n_bis;

	size = 0;
	n_bis = n;
	if (n_bis > 9)
	{
		ft_putnbr_unsigned_fd(n_bis / 10, fd);
		n_bis %= 10;
	}
	if (n_bis < 10)
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

int	ft_putstr_fd(char *s, int fd)
{
	int size; 

	size = 0;
	if (!s || fd < 0)
		return (size);
	size = write(fd, s, sizeof(char) * ft_strlen(s));
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

int ft_putnbr_base_fd (unsigned long long int nbr, char *base, int fd)
{
	unsigned long long int	nbr_bis;
	size_t			size_base;
	static int 		size;

	size = 0;
	nbr_bis = 0;
	size_base = check_base(base);
	if (!size_base)
		return (size);
	nbr_bis = nbr;
	if (nbr_bis > size_base - 1)
	{
		ft_putnbr_base_fd(nbr_bis / size_base, base, fd);
		nbr_bis %= size_base;
	}
	if (nbr_bis < size_base)
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
		size += ft_putstr_fd("(null)",1);
	else
	{
		while (*str)
		{
			size += write(1,str,1);
			str++;
		}
	}
	return (size);
}

int ft_printf_p (va_list arg) 
{
	int		size;
	void	*add;

	size = 0;
	add = va_arg(arg, void *);
	size += ft_putstr_fd("0x", 1);
	// size = ft_convert_hex(add);
	size += ft_putnbr_base_fd ((unsigned long long int)add, "0123456789abcdef", 1);
	return(size);
}

int ft_printf_d (va_list arg) 
{
	int	size;
	int add;

	size = 0;
	add = va_arg(arg, int);
	size = ft_putnbr_fd (add, 1);
	return(size);
}

int ft_printf_i (va_list arg) 
{
	int	size;
	int add;

	size = 0;
	add = va_arg(arg, int);
	size = ft_putnbr_fd (add, 1);
	return(size);
}

int ft_printf_u (va_list arg) 
{
	int	size;
	unsigned int add;

	size = 0;
	add = va_arg(arg, unsigned int);
	size = ft_putnbr_unsigned_fd (add, 1);
	return(size);
}

int ft_printf_x (va_list arg) 
{
	int	size;
	unsigned int	hex_low;
	
	size = 0;
	hex_low = (unsigned int)va_arg(arg, int);
	// size = ft_convert_hex(hex_low);
	size = ft_putnbr_base_fd (hex_low, "0123456789abcdef", 1);
	return(size);
}

int ft_printf_X (va_list arg) 
{
	int	size;
	unsigned int	hex_up;
	
	size = 0;
	hex_up = (unsigned int)va_arg(arg, int);
	size = ft_putnbr_base_fd (hex_up, "0123456789ABCDEF", 1);
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
	else if (c == 'i')
		size +=  ft_printf_i(arg);
	else if (c == 'u')
		size +=  ft_printf_u(arg);
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
	void *test;

	int p = 2;
	test = &p;
	
	size1 = printf(" %p %p \n", LONG_MIN, LONG_MAX);
	size2 = ft_printf(" %p %p \n", LONG_MIN, LONG_MAX);

	printf("size1 = %d size2 = %d", size1, size2);
}
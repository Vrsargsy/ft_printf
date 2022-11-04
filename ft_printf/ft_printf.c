/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:14:02 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/04/28 18:17:50 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_print(char c, va_list *args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(*args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(*args, char *));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(*args, int));
	else if (c == 'p')
		len += ft_putptr(va_arg(*args, void *));
	else if (c == '%')
		len += ft_putchar('%');
	else if (c == 'x')
		len += ft_put_hex(va_arg(*args, unsigned int), 0);
	else if (c == 'X')
		len += ft_put_hex(va_arg(*args, unsigned int), 1);
	else if (c == 'u')
		len += ft_putnbr_unsigned(va_arg(*args, unsigned int));
	return (len);
}

int	ft_printf(const char *print, ...)
{
	int		len;
	va_list	args;

	if (!print)
		return (0);
	len = 0;
	va_start(args, print);
	while (*print)
	{
		if (*print == '%')
		{
			print++;
			if (*print == 'c' || *print == 's' || *print == 'd'
				|| *print == 'p' || *print == 'i' || *print == 'u'
				|| *print == 'x' || *print == 'X' || *print == '%')
				len += ft_check_print(*print, &args);
		}
		else
			len += ft_putchar(*print);
		print++;
	}
	va_end(args);
	return (len);
}

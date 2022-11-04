/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:14:36 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/04/28 18:14:48 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex(unsigned long n, int type)
{
	int	len;

	len = 0;
	if (n > 15)
		len += ft_put_hex(n / 16, type);
	n = n % 16;
	if (n < 10)
		len += ft_putchar(n + 48);
	else if (n >= 10 && type == 0)
		len += ft_putchar(n + 87);
	else if (n >= 10 && type == 1)
		len += ft_putchar(n + 55);
	return (len);
}

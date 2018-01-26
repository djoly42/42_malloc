/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_cc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 14:04:00 by djoly             #+#    #+#             */
/*   Updated: 2016/03/09 16:20:40 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_mask1(wchar_t c)
{
	int i;

	i = 0;
	i += write_wc((c >> 6) + 0xC0);
	i += write_wc((c & 0x3F) + 0x80);
	return (i);
}

int		ft_mask2(wchar_t c)
{
	int i;

	i = 0;
	i += write_wc((c >> 12) + 0xE0);
	i += write_wc(((c >> 6) & 0x3F) + 0x80);
	i += write_wc((c & 0x3F) + 0x80);
	return (i);
}

int		ft_mask3(wchar_t c)
{
	int i;

	i = 0;
	i += write_wc((c >> 18) + 0xF0);
	i += write_wc(((c >> 12) & 0x3F) + 0x80);
	i += write_wc(((c >> 6) & 0x3F) + 0x80);
	i += write_wc((c & 0x3F) + 0x80);
	return (i);
}

int		ft_put_w_char(wchar_t c)
{
	if (c < 256)
		return (ft_putchar(c));
	if (c < 0x7FF)
		return (ft_mask1(c));
	if (c < 0xFFFF)
		return (ft_mask2(c));
	return (ft_mask3(c));
}

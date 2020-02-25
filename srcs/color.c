/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oderkaou <oderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:02:02 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/25 15:25:53 by oderkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int	get_percent(int color, float p)
{
	unsigned char *tab;

	tab = (unsigned char *)&color;
	tab[0] = tab[0] * p;
	tab[1] = tab[1] * p;
	tab[2] = tab[2] * p;
	return (color);
}

int	color_mix(int color, float d, float s)
{
	unsigned char	*tab;

	tab = (unsigned char *)&color;
	tab[0] = (tab[0] + (255 - tab[0]) * s) * d;
	tab[1] = (tab[1] + (255 - tab[1]) * s) * d;
	tab[2] = (tab[2] + (255 - tab[2]) * s) * d;
	return (color);
}

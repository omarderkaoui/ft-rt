/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 20:54:36 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/25 17:11:02 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector		char_to_vec(char *str)
{
	char		**values;
	t_vector	vector;

	ft_strtrim(str);
	values = ft_strsplit(str, ' ');
	vector = (t_vector){0.0, 0.0, 0.0};
	vector.x = ft_atof(values[0]);
	vector.y = ft_atof(values[1]);
	vector.z = ft_atof(values[2]);
	ft_memdel((void **)values);
	return (vector);
}

t_rot			char_to_rot(char *str)
{
	char	**values;
	t_rot	rot;

	ft_strtrim(str);
	values = ft_strsplit(str, ' ');
	init_rot(&rot);
	rot.on = !ft_strcmp(values[0], "on") ? 1 : 0;
	if (rot.on)
	{
		rot.alpha_x = ft_atof(values[1]);
		rot.alpha_y = ft_atof(values[2]);
		rot.alpha_z = ft_atof(values[3]);
	}
	ft_memdel((void **)values);
	return (rot);
}

char			*shift_str(char *str)
{
	while (!ft_is_whitespace(*str))
		str++;
	return (str);
}

t_trans			char_to_trans(char *str)
{
	char	**values;
	t_trans	trans;

	init_trans(&trans);
	if (!(*str))
		return (trans);
	ft_strtrim(str);
	values = ft_strsplit(str, ' ');
	trans.on = !ft_strcmp(values[0], "on") ? 1 : 0;
	if (trans.on)
		trans.vec = char_to_vec(shift_str(str));
	ft_memdel((void **)values);
	return (trans);
}

t_light_coeffs	char_to_coeffs(char *str)
{
	char			**values;
	t_light_coeffs	coeffs;

	coeffs = (t_light_coeffs){0.0, 0.0, 0.0};
	ft_strtrim(str);
	values = ft_strsplit(str, ' ');
	coeffs.ks = ft_atof(values[0]);
	coeffs.kd = ft_atof(values[1]);
	coeffs.n = ft_atof(values[2]);
	ft_memdel((void **)values);
	return (coeffs);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 20:54:36 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/26 17:02:59 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector		char_to_vec(char *str)
{
	char		**values;
	char		*tmp;
	t_vector	vector;

	tmp = ft_strtrim(str);
	values = ft_strsplit(tmp, ' ');
	vector = (t_vector){0.0, 0.0, 0.0};
	vector.x = ft_atof(values[0]);
	vector.y = ft_atof(values[1]);
	vector.z = ft_atof(values[2]);
	ft_memdel_2d(values);
	ft_memdel((void **)&tmp);
	return (vector);
}

t_rot			char_to_rot(char *str)
{
	char	**values;
	char	*tmp;
	t_rot	rot;

	tmp = ft_strtrim(str);
	values = ft_strsplit(tmp, ' ');
	init_rot(&rot);
	rot.on = !ft_strcmp(values[0], "on") ? 1 : 0;
	if (rot.on)
	{
		rot.alpha_x = ft_atof(values[1]);
		rot.alpha_y = ft_atof(values[2]);
		rot.alpha_z = ft_atof(values[3]);
	}
	ft_memdel_2d(values);
	ft_memdel((void **)&tmp);
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
	char	*tmp;
	t_trans	trans;

	init_trans(&trans);
	if (!(*str))
		return (trans);
	tmp = ft_strtrim(str);
	values = ft_strsplit(tmp, ' ');
	trans.on = !ft_strcmp(values[0], "on") ? 1 : 0;
	if (trans.on)
		trans.vec = char_to_vec(shift_str(tmp));
	ft_memdel_2d(values);
	ft_memdel((void **)&tmp);
	return (trans);
}

t_light_coeffs	char_to_coeffs(char *str)
{
	char			**values;
	char			*tmp;
	t_light_coeffs	coeffs;

	coeffs = (t_light_coeffs){0.0, 0.0, 0.0};
	tmp = ft_strtrim(str);
	values = ft_strsplit(tmp, ' ');
	coeffs.ks = ft_atof(values[0]);
	coeffs.kd = ft_atof(values[1]);
	coeffs.n = ft_atof(values[2]);
	ft_memdel_2d(values);
	ft_memdel((void **)&tmp);
	return (coeffs);
}

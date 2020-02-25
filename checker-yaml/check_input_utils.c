/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 22:18:05 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/25 23:18:31 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	ft_memdel_2d(void **ap)
{
	char	**ap_2;
	int		i;

	ap_2 = (char **)ap;
	i = 0;
	while (ap_2[i])
	{
		ft_memdel((void **)ap_2);
		i++;
	}
	ft_memdel(ap);
}

int		check_light_input(char *vec)
{
	char	**values;
	int		result;

	result = 0;
	ft_strtrim(vec);
	values = ft_strsplit(vec, ' ');
	if (ft_atof(values[0]) < 0 || ft_atof(values[0]) > 1)
		return (0);
	result = array_len(values);
	ft_memdel_2d((void **)values);
	return (result == 3);
}

int		check_vec_input(char *vec)
{
	char	**values;
	int		result;

	result = 0;
	ft_strtrim(vec);
	values = ft_strsplit(vec, ' ');
	result = array_len(values);
	ft_memdel_2d((void **)values);
	return (result == 3);
}

int		check_transform_input(char *vec)
{
	char	**values;
	int		result;

	result = 0;
	ft_strtrim(vec);
	values = ft_strsplit(vec, ' ');
	result = array_len(values);
	ft_memdel_2d((void **)values);
	return (result == 4);
}

int		check_univalue(char *vec, int color)
{
	char	**values;
	int		result;

	result = 0;
	ft_strtrim(vec);
	values = ft_strsplit(vec, ' ');
	if (color)
	{
		if (ft_atof(values[0]) < 0 || ft_atof(values[0]) > WHITE)
			return (0);
	}
	result = array_len(values);
	ft_memdel_2d((void **)values);
	return (result == 1);
}

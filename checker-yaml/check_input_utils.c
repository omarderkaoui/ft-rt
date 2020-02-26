/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 22:18:05 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/26 17:11:16 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	ft_memdel_2d(char **ap)
{
	int	i;

	i = 0;
	while (ap[i])
	{
		free(ap[i]);
		i++;
	}
	free(ap);
}

int		check_light_input(char *vec)
{
	char	**values;
	char	*tmp;
	int		result;

	result = 0;
	tmp = ft_strtrim(vec);
	values = ft_strsplit(tmp, ' ');
	if (ft_atof(values[0]) < 0 || ft_atof(values[0]) > 1)
		return (0);
	if (ft_atof(values[1]) < 0 || ft_atof(values[1]) > 1)
		return (0);
	result = array_len(values);
	ft_memdel_2d(values);
	free(tmp);
	return (result == 3);
}

int		check_vec_input(char *vec)
{
	char	**values;
	char	*tmp;
	int		result;

	result = 0;
	tmp = ft_strtrim(vec);
	values = ft_strsplit(tmp, ' ');
	result = array_len(values);
	ft_memdel_2d(values);
	free(tmp);
	return (result == 3);
}

int		check_transform_input(char *vec)
{
	char	**values;
	char	*tmp;
	int		result;

	result = 0;
	tmp = ft_strtrim(vec);
	values = ft_strsplit(tmp, ' ');
	result = array_len(values);
	ft_memdel_2d(values);
	free(tmp);
	return (result == 4);
}

int		check_univalue(char *vec, int color)
{
	char	**values;
	char	*tmp;
	int		result;

	result = 0;
	tmp = ft_strtrim(vec);
	values = ft_strsplit(tmp, ' ');
	if (color)
	{
		if (ft_atof(values[0]) < 0 || ft_atof(values[0]) > WHITE)
			return (0);
	}
	result = array_len(values);
	ft_memdel_2d(values);
	free(tmp);
	return (result == 1);
}

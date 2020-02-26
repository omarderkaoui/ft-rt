/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 19:07:50 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/26 18:26:55 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		check_cam_keys(t_block_list *cam)
{
	int		key;
	int		i;

	key = -1;
	i = 0;
	while (cam && i < 3)
	{
		key = find_camera_key(cam->key);
		if ((i == 0 && key != EYE) || (key == EYE &&
			!check_vec_input(cam->value)))
			return (0);
		if ((i == 1 && key != LOOK_AT) || (key == LOOK_AT &&
			!check_vec_input(cam->value)))
			return (0);
		if ((i == 2 && key != FOV) || ((key == FOV) &&
			!check_univalue(cam->value, 0)))
			return (0);
		i++;
		cam = cam->next;
	}
	return (i == 3);
}

int		check_light_keys(t_block_list *light)
{
	int		key;
	int		i;

	key = -1;
	i = 0;
	while (light && i < 2)
	{
		key = find_light_key(light->key);
		if ((i == 0 && key != ORIGIN) || (key == ORIGIN &&
			!check_vec_input(light->value)))
			return (0);
		if ((i == 1 && key != INTENSITY) || (key == INTENSITY &&
			!check_univalue(light->value, 0)))
			return (0);
		i++;
		light = light->next;
	}
	return (i == 2);
}

int		check_shape_keys(t_block_list *list, int size)
{
	int		object;

	object = 0;
	if (!ft_strcmp(list->key, "name"))
		object = find_object_name(list->value);
	if (object == SPHERE)
		return (sphere_keys(list, size) && sphere_input(list, size));
	if (object == CYLINDER)
		return (cylinder_keys(list, size) && cylinder_input(list, size));
	if (object == CONE)
		return (cone_keys(list, size) && cone_input(list, size));
	if (object == PLANE)
		return (plane_keys(list, size) && cone_input(list, size));
	return (0);
}

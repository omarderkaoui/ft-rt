/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oderkaou <oderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 20:28:39 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/27 13:21:27 by oderkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void		fill_inter(t_list *tmp, t_ray *ray)
{
	t_object	*object;
	int			name;

	object = tmp->content;
	name = find_object_name(object->name);
	if (name == SPHERE)
		((t_object*)tmp->content)->t = sphere(ray, (t_object*)tmp->content);
	else if (name == PLANE)
		((t_object*)tmp->content)->t = plane(ray, (t_object*)tmp->content);
	else if (name == CYLINDER)
		((t_object*)tmp->content)->t = cylinder(ray, (t_object*)tmp->content);
	else if (name == CONE)
		((t_object*)tmp->content)->t = cone(ray, (t_object*)tmp->content);
	else
		((t_object *)tmp->content)->t = FAR;
}

t_object	*find_closest_t(t_camera c, t_list *objs, t_index in, t_ray *ray)
{
	t_object		*obj;
	t_list			*tmp;

	c = ft_create_cam(c.eye, c.look_at, c.fov);
	*ray = generate_ray(&c, in.i, in.j);
	tmp = objs;
	((t_object *)tmp->content)->t = FAR;
	obj = (t_object *)tmp->content;
	while (tmp)
	{
		fill_inter(tmp, ray);
		if (((t_object*)tmp->content)->t < obj->t)
			obj = (t_object *)tmp->content;
		tmp = tmp->next;
	}
	if (obj->t == FAR)
		return (NULL);
	return (obj);
}

void		draw(t_mlx *mlx, t_camera c, t_list *objs, t_list *l)
{
	t_index		index;
	t_object	*obj;
	t_ray		ray;
	int			k;

	k = 0;
	index.i = -1;
	while (++index.i < WIDTH)
	{
		index.j = -1;
		while (++index.j < HEIGHT)
		{
			obj = find_closest_t(c, objs, index, &ray);
			if (obj == NULL)
			{
				ft_mlx_pixel_put(mlx, index.i, index.j, BLACK);
				continue ;
			}
			k = shadows(&ray, objs, l, obj);
			ft_mlx_pixel_put(mlx, index.i, index.j,
			phong_model(obj, &ray, l, k));
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}

void		create_actual_objs(t_mlx *mlx, t_camera c, t_list *l, t_list *objs)
{
	draw(mlx, c, objs, l);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oderkaou <oderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 20:28:39 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/25 14:32:11 by oderkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void		init1(t_list *tmp, t_ray *ray)
{
	if (!(ft_strcmp(((t_object*)tmp->content)->name, "sphere")))
		((t_object*)tmp->content)->t = sphere(ray, (t_object*)tmp->content);
	else if (!(ft_strcmp(((t_object*)tmp->content)->name, "plane")))
		((t_object*)tmp->content)->t = plane(ray, (t_object*)tmp->content);
	else if (!(ft_strcmp(((t_object*)tmp->content)->name, "cylinder")))
		((t_object*)tmp->content)->t = cylinder(ray, (t_object*)tmp->content);
	else if (!(ft_strcmp(((t_object*)tmp->content)->name, "cone")))
		((t_object*)tmp->content)->t = cone(ray, (t_object*)tmp->content);
	else
		((t_object *)tmp->content)->t = FAR;
}

t_object	*ramplir(t_camera c, t_list *objects, t_binom b, t_ray *ray)
{
	t_object		*obj1;
	t_list			*tmp;

	c = ft_create_cam(c.eye, c.look_at, c.fov);
	*ray = generate_ray(&c, b.i, b.j);
	tmp = objects;
	((t_object *)tmp->content)->t = FAR;
	obj1 = (t_object *)tmp->content;
	while (tmp)
	{
		init1(tmp, ray);
		if (((t_object*)tmp->content)->t < obj1->t)
			obj1 = (t_object *)tmp->content;
		tmp = tmp->next;
	}
	if (obj1->t == FAR)
		return (NULL);
	return (obj1);
}

void		draw(t_mlx *mlx, t_camera c, t_list *objs, t_list *l)
{
	t_binom		b;
	t_object	*obj;
	t_ray		ray;

	b.i = -1;
	while (++b.i < WIDTH)
	{
		b.j = -1;
		while (++b.j < HEIGHT)
		{
			obj = ramplir(c, objs, b, &ray);
			if (obj == NULL)
			{
				ft_mlx_pixel_put(mlx, b.i, b.j, GREY);
				continue ;
			}
			obj->k = shadows(&ray, objs, l, obj);
			ft_mlx_pixel_put(mlx, b.i, b.j, phong_model(obj, &ray, l, obj->k));
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}

void		create_actual_objs(t_mlx *mlx, t_camera c, t_list *l, t_list *objs)
{
	draw(mlx, c, objs, l);
}

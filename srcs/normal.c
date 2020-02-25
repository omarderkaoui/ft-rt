/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:17:13 by oderkaou          #+#    #+#             */
/*   Updated: 2020/02/25 19:26:55 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector		sphere_normal(t_object *obj, t_ray *ray)
{
	t_vector	n;
	t_point		i;

	i = vec_sum(ray->origin, vec_kscale(obj->t, ray->dir));
	n = vec_norm(vec_sub(i, obj->center));
	return (n);
}

t_vector		cone_normal(t_object *obj, t_ray *ray)
{
	t_vector	n;
	t_point		q;
	float		dx;
	float		dy;
	float		dz;

	q = vec_sum(ray->origin, vec_kscale(obj->t, ray->dir));
	dx = cos(obj->alpha) * cos(obj->alpha) * (1 - obj->vec_dir.x
	* obj->vec_dir.x) * (q.x - obj->center.x - obj->vec_dir.x
	* obj->vec_dir.x * (q.x - obj->center.x)) - sin(obj->alpha)
	* sin(obj->alpha) * obj->vec_dir.x * (q.x - obj->center.x);
	dy = cos(obj->alpha) * cos(obj->alpha) * (1 - obj->vec_dir.y
	* obj->vec_dir.y) * (q.y - obj->center.y - obj->vec_dir.y
	* obj->vec_dir.y * (q.y - obj->center.y)) - sin(obj->alpha)
	* sin(obj->alpha) * obj->vec_dir.y * (q.y - obj->center.y);
	dz = cos(obj->alpha) * cos(obj->alpha) * (1 - obj->vec_dir.z
	* obj->vec_dir.z) * (q.z - obj->center.z - obj->vec_dir.z
	* obj->vec_dir.z * (q.z - obj->center.z)) - sin(obj->alpha)
	* sin(obj->alpha) * obj->vec_dir.z * (q.z - obj->center.z);
	n.x = dx / sqrt(dx * dx + dy * dy + dz * dz);
	n.y = dy / sqrt(dx * dx + dy * dy + dz * dz);
	n.z = dz / sqrt(dx * dx + dy * dy + dz * dz);
	return (n);
}

t_vector		cylinder_normal(t_object *obj, t_ray *ray)
{
	t_vector	n;
	t_point		i;

	i = vec_sum(ray->origin, vec_kscale(obj->t, ray->dir));
	n = vec_norm(vec_sub(vec_sub(i, obj->center),
	vec_kscale(vec_dot(obj->vec_dir, vec_sub(i, obj->center)), obj->vec_dir)));
	return (n);
}

t_vector		get_normal(t_object *obj, t_ray *ray)
{
	t_vector	n;
	int			name;

	name = find_object_name(obj->name);
	if (name == SPHERE)
		n = sphere_normal(obj, ray);
	if (name == PLANE)
		n = obj->vec_dir;
	if (name == CONE)
		n = cone_normal(obj, ray);
	if (name == CYLINDER)
		n = cylinder_normal(obj, ray);
	return (n);
}

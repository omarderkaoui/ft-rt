/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_model.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oderkaou <oderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 20:59:11 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/27 04:10:45 by oderkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector		reflection_vector(t_vector nor, t_vector light)
{
	t_vector r;

	r = vec_norm(vec_sub(vec_kscale(2 * vec_dot(nor, light), nor), light));
	return (r);
}

float			f_max(float a)
{
	if (a < 0.0)
		return (0.0);
	if (a > 1.0)
		return (1.0);
	return (a);
}

float			specular(t_object *obj, t_light *light, t_ray *ray)
{
	t_vector	r;
	t_vector	l;
	t_point		i;
	int			name;

	i = vec_sum(ray->origin, vec_kscale(obj->t, ray->dir));
	l = vec_norm(vec_sub(light->origin, i));
	name = find_object_name(obj->name);
	if (name == SPHERE)
		r = reflection_vector(sphere_normal(obj, ray), l);
	if (name == PLANE)
		r = reflection_vector(obj->vec_dir, l);
	if (name == CONE)
		r = reflection_vector(cone_normal(obj, ray), l);
	if (name == CYLINDER)
		r = reflection_vector(cylinder_normal(obj, ray), l);
	return (obj->coeffs.ks
	* pow(f_max(vec_dot(r, vec_kscale(-1, ray->dir))), obj->coeffs.n));
}

float			diffuse(t_object *obj, t_light *light, t_ray *ray)
{
	t_vector	normal;
	t_point		p;
	t_vector	light_dir;
	int			name;

	p = vec_sum(ray->origin, vec_kscale(obj->t, ray->dir));
	light_dir = vec_norm(vec_sub(light->origin, p));
	name = find_object_name(obj->name);
	if (name == SPHERE)
		normal = sphere_normal(obj, ray);
	if (name == PLANE)
		normal = obj->vec_dir;
	if (name == CONE)
		normal = cone_normal(obj, ray);
	if (name == CYLINDER)
		normal = cylinder_normal(obj, ray);
	return (vec_dot(normal, light_dir));
}

int				phong_model(t_object *obj, t_ray *ray, t_list *lights, float k)
{
	float	diff;
	float	spec;

	if (k == 0)
		return (get_percent(obj->color, PERCENTAGE));
	diff = 0;
	spec = 0;
	while (lights != NULL)
	{
		diff = diff
		+ fmax(0, fmin(diffuse(obj, (t_light *)lights->content, ray), 1.0));
		spec = spec
		+ fmax(0, fmin(specular(obj, (t_light *)lights->content, ray), 1.0));
		lights = lights->next;
	}
	return (color_mix(obj->color,
	fmax(0, fmin(0.2 + diff, 1.0)), fmax(0, fmin(spec, 1.0))));
}

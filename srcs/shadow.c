/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:15:01 by oderkaou          #+#    #+#             */
/*   Updated: 2020/02/25 19:48:10 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void		fill_inter_shadow(t_list *tmp, t_ray sh)
{
	t_object	*object;
	int			name;

	object = tmp->content;
	name = find_object_name(object->name);
	if (name == SPHERE)
		((t_object*)tmp->content)->tsh = sphere(&sh, (t_object*)tmp->content);
	else if (name == PLANE)
		((t_object*)tmp->content)->tsh = plane(&sh, (t_object*)tmp->content);
	else if (name == CONE)
		((t_object*)tmp->content)->tsh = cone(&sh, (t_object*)tmp->content);
	else if (name == CYLINDER)
		((t_object*)tmp->content)->tsh = cylinder(&sh, (t_object*)tmp->content);
}

void		init_shadow_values(t_shadow_ray *shadow, t_ray *ray, double t)
{
	shadow->k = 0;
	shadow->nb_light = 0;
	shadow->p = vec_sum(ray->origin, vec_kscale(t, ray->dir));
}

int			shadows(t_ray *ray, t_list *objects, t_list *lights, t_object *obj)
{
	t_shadow_ray v;

	init_shadow_values(&v, ray, obj->t);
	while (lights)
	{
		v.sh.dir = vec_norm(vec_sub(((t_light *)lights->content)->origin, v.p));
		v.n = get_normal(obj, ray);
		v.sh.origin = vec_sum(v.p, vec_kscale(MIN_D, v.n));
		v.tmp = objects;
		while (v.tmp)
		{
			fill_inter_shadow(v.tmp, v.sh);
			if (((t_object*)v.tmp->content)->tsh != FAR)
			{
				v.k++;
				break ;
			}
			v.tmp = v.tmp->next;
		}
		v.nb_light++;
		lights = lights->next;
	}
	return (v.k != v.nb_light);
}

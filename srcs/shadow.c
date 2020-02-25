/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oderkaou <oderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:15:01 by oderkaou          #+#    #+#             */
/*   Updated: 2020/02/25 14:17:31 by oderkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	init2(t_list *tmp, t_ray sh)
{
	if (!(ft_strcmp(((t_object*)tmp->content)->name, "sphere")))
		((t_object*)tmp->content)->tsh = sphere(&sh, (t_object*)tmp->content);
	else if (!(ft_strcmp(((t_object*)tmp->content)->name, "plane")))
		((t_object*)tmp->content)->tsh = plane(&sh, (t_object*)tmp->content);
	else if (!(ft_strcmp(((t_object*)tmp->content)->name, "cone")))
		((t_object*)tmp->content)->tsh = cone(&sh, (t_object*)tmp->content);
	else if (!(ft_strcmp(((t_object*)tmp->content)->name, "cylinder")))
		((t_object*)tmp->content)->tsh = cylinder(&sh, (t_object*)tmp->content);
}

float	shadows(t_ray *ray, t_list *objects, t_list *lights, t_object *obj)
{
	t_var2 v;

	v.k = 0;
	v.nb_light = 0;
	v.p = vec_sum(ray->origin, vec_kscale(obj->t, ray->dir));
	while (lights)
	{
		v.sh.dir = vec_normalize(vec_sub(((t_light *)lights->content)->origin, v.p));
		v.n = get_normal(obj, ray);
		v.sh.origin = vec_sum(v.p, vec_kscale(MIN_D, v.n));
		v.tmp = objects;
		while (v.tmp)
		{
			init2(v.tmp, v.sh);
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

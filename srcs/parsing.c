/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oderkaou <oderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 19:40:41 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/26 21:04:27 by oderkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		fill(t_parser *p, t_mlx *mlx)
{
	t_scene		scene;

	scene = fill_scene(p->blocks);
	g_env.scene = scene;
	scene.objects = translate(scene.objects);
	scene.objects = rotate(scene.objects);
	create_actual_objs(mlx, scene.camera, scene.lights, scene.objects);
	return (1);
}

int		get_data(char *filename, t_mlx *mlx)
{
	t_parser	*p;

	if (!(p = parse(filename)))
		return (0);
	if (!check(p))
		return (0);
	fill(p, mlx);
	free_parser(p);
	return (1);
}

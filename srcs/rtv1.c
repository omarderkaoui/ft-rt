/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:20:30 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/25 23:21:35 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void		free_objects(void)
{
	t_list	*tmp;

	while (g_env.scene.objects)
	{
		tmp = g_env.scene.objects->next;
		ft_memdel((void **)(&g_env.scene.objects));
		g_env.scene.objects = tmp;
	}
}

void		free_lights(void)
{
	t_list	*tmp;

	while (g_env.scene.lights)
	{
		tmp = g_env.scene.lights->next;
		ft_memdel((void **)(&g_env.scene.lights));
		g_env.scene.lights = tmp;
	}
}

void		free_data(void)
{
	free_objects();
	free_lights();
}

int			main(int ac, char *av[])
{
	t_mlx mlx;

	if (ac == 2)
	{
		ft_mlx_setup(&mlx);
		g_env.mlx = mlx;
		if (!(get_data(av[1], &mlx)))
		{
			write(1, "\033[1;31mError\n\033[0m", 17);
			return (1);
		}
		else
		{
			mlx_hook(mlx.win_ptr, 2, 0, key_press, &mlx);
			mlx_hook(mlx.win_ptr, 17, 0, close_win, &mlx);
			mlx_loop(mlx.mlx_ptr);
		}
	}
	else
	{
		write(1, "\033[0;31mEnter a valid filename\n", 30);
		return (1);
	}
	free_data();
	return (0);
}

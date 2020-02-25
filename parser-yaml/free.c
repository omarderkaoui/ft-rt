/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 23:19:19 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/25 23:20:32 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		free_blocks(t_block *block)
{
	t_block_list	*list;

	while (block->list)
	{
		list = block->list->next;
		ft_memdel((void **)block->list);
		block->list = list;
	}
}

void		free_parser(t_parser *p)
{
	t_block		*block;

	while (p->blocks)
	{
		block = p->blocks->next;
		free_blocks(p->blocks);
		p->blocks = block;
	}
}

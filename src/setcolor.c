/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setcolor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:50:44 by polenyc           #+#    #+#             */
/*   Updated: 2024/04/17 13:51:43 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/fdf.h"

void	setcolor(t_mlxdata *app)
{
	app->color->zcolor = app->map->crd[(int)app->crd->y]
		[(int)app->crd->x].color;
	app->color->l_grad = 0;
	if (app->color->zcolor)
		return ;
	app->color->zcolor = app->color->s_color + app->color->g_grad * (app->crd->z_ - app->map->zmin);
	app->color->curcolor = app->color->s_color + app->color->g_grad * (app->crd->z - app->map->zmin);
}

void	setgradient(t_mlxdata *app, float steps)
{
	if (app->crd->z == app->crd->z_)
		return ;
	app->color->l_grad = (float)(app->color->zcolor - app->color->curcolor)
		/ steps;
}

t_color		*new_color(t_map *map)
{
	t_color	*color;

	if (!map)
		return (NULL);
	color = malloc(sizeof(t_color));
	if (!color)
		return (NULL);
	color->curcolor = 0;
	color->zcolor = 0;
	color->l_grad = 0;
	color->f_color = rgbcolor(0, 0, 255);
	color->d_color = 0;
	color->s_color = rgbcolor(255, 0, 0);
	color->g_grad = (float)(color->f_color - color->s_color) / (map->zmax - map->zmin);
	return (color);
}

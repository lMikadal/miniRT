/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:30:43 by pmikada           #+#    #+#             */
/*   Updated: 2023/06/04 15:30:44 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_write_map(char *name)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr; // for point color
	int		bits;
	int		line;
	int		endian;

    // create window of put image
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, HORIZON, VERTICAL, name);
    // create image
	img = mlx_new_image(mlx, HORIZON, VERTICAL);
	addr = mlx_get_data_addr(img, &bits, &line, &endian);
    // push image to window
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
    // loop image show
	mlx_loop(mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:30:20 by pmikada           #+#    #+#             */
/*   Updated: 2023/06/04 15:30:22 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "minilibx_macos/mlx.h"
# include "get_next_line/get_next_line.h"

# define HORIZON 1280
# define VERTICAL 720

void	ft_write_map(char *name);

#endif

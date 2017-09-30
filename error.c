/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:40:05 by kboucaud          #+#    #+#             */
/*   Updated: 2017/09/30 21:40:06 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_bad_arg(void)
{
	ft_putstr("Bad Parameters\nUse one of the following:\nMandelbrot\nJulia\n");
	exit(1);
}

void		ft_error(void)
{
	write(1, "error\n", 6);
	exit(1);
}

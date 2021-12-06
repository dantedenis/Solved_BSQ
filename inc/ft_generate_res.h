/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_res.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstrong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:24:33 by bstrong           #+#    #+#             */
/*   Updated: 2021/09/06 14:24:36 by bstrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GENERATE_RES_H
# define FT_GENERATE_RES_H

# include "ft_list.h"
# include "ft_string.h"

int		min3(int a, int b, int c);
int		**creat_arr_int(int len);
int		**dynamic_prog(t_list **map);
void	fill_arr(int **arr, int i, int j);

#endif

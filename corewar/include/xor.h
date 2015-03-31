/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 07:38:20 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/07 16:48:07 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XOR_H
# define XOR_H

# include "game.h"

void	ft_reg_xor(t_list *chmp, unsigned char *mem, int pos);
void	ft_indir_xor(t_list *chmp, unsigned char *mem, int pos, int param);
void	ft_dir_xor(t_list *chmp, unsigned char *mem, int pos, int param);
void	ft_ind_dir_xor(t_list *chmp, unsigned char *mem, int pos, int param);

#endif

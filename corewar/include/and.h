/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 17:35:09 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/07 15:41:58 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AND_H
# define AND_H

# include "game.h"

void	ft_reg(t_list *chmp, unsigned char *mem, int pos);
void	ft_indirect(t_list *chmp, unsigned char *mem, int pos, int param);
void	ft_direct(t_list *chmp, unsigned char *mem, int pos, int param);
void	ft_ind_dir(t_list *chmp, unsigned char *mem, int pos, int param);

#endif

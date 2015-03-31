/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 17:03:38 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/07 15:53:14 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OR_H
# define OR_H

# include "game.h"

void	ft_reg_or(t_list *chmp, unsigned char *mem, int pos);
void	ft_indirect_or(t_list *chmp, unsigned char *mem, int pos, int param);
void	ft_direct_or(t_list *chmp, unsigned char *mem, int pos, int param);
void	ft_ind_dir_or(t_list *chmp, unsigned char *mem, int pos, int param);

#endif

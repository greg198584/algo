/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 17:48:11 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/04 09:31:51 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LDI_H
# define LDI_H

# include "game.h"

void	ft_reg_ldi(t_list *chmp, unsigned char *mem, int pos);
void	ft_reg_ind_dir(t_list *chmp, unsigned char *mem, int pos, int param);
void	ft_id_ldi(t_list *chmp, unsigned char *mem, int pos, int param);
void	ft_reg_lldi(t_list *chmp, unsigned char *mem, int pos);
void	ft_reg_id_lldi(t_list *chmp, unsigned char *mem, int pos, int param);
void	ft_id_lldi(t_list *chmp, unsigned char *mem, int pos, int param);

#endif

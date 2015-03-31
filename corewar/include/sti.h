/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 15:01:11 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/20 08:57:35 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STI_H
# define STI_H

# include "game.h"

void	ft_fill_sti_n(t_list *chmp, unsigned char *mem, int addr, int value);
void	ft_fill_sti(t_list *chmp, unsigned char *mem, int addr, int value);
void	ft_id_reg_sti(t_list *chmp, unsigned char *mem, int pos, int param);
void	ft_reg_sti(t_list *chmp, unsigned char *mem, int pos);
void	ft_id_sti(t_list *chmp, unsigned char *mem, int pos);

#endif

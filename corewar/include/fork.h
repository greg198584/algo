/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 19:54:56 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/21 16:41:03 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_H
# define FORK_H

# include "game.h"

t_list	*ft_copy_int_tab(int reg[REG_NUMBER], t_list *new);
void	ft_append_to_champ(t_list **chmp, int pos);

#endif

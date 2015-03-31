/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2015/03/07 16:27:04 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

t_op	g_opt_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 4},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 4},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 4},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 4},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 4},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 2},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 2},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 2},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 2},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 4},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 2},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 2},
	{"aff", 1, {T_REG}, 16, 2, "aff", 0},
	{0, 0, {0}, 0, 0, 0, 0}
};

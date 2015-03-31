/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 13:54:59 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/31 15:22:40 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "corewar.h"

# define LIVE_SIZE	4
# define ZJMP_SIZE	2
# define FORK_SIZE	2
# define LFORK_SIZE	2
# define OVERFLOW	65536
# define FIRST(x)	(((x) >> 6) & 0x03)
# define TWO(x)		(((x) >> 4) & 0x03)
# define LAST(x)	(((x) >> 2) & 0x03)
# define DIR_2		2
# define DIR_4		4
# define IND		2
# define REG		1
# define OCT_1(x)	((x >> 24) & 0xff)
# define OCT_2(x)	((x >> 16) & 0xff)
# define OCT_3(x)	((x >> 8) & 0xff)
# define OCT_4(x)	((x) & 0xff)

t_list				*g_head_sv;

typedef struct		s_instr
{
	int				(*func_ptr)(t_list *champ, unsigned char *mem, int pos);
	char			instr;
}					t_instr;

typedef struct		s_vm
{
	int				last_live_chmp;
	int				debug;
	int				debugx;
	int				cycle_d;
	int				nb_tour;
	int				cycle;
	int				cycle_total;
	int				live;
	int				cycle_to_die;
	int				nb_chmp;
	int				tab[4];
	int				size[4];
	int				cor;
	int				j;
	int				end;
	char			*color;
}					t_vm;

typedef struct		s_dump
{
	int				cor;
	int				j;
	int				end;
	char			*color;
	int				i;
}					t_dump;

int					ft_print_dump_debug(t_list *chmp, unsigned char *mem,
										int pos, t_vm *vm);
int					ft_verif_cycle(t_vm *vm);
int					ft_instr(t_list *champ, unsigned char *mem, t_vm *vm);
int					ft_cycle(t_list *champ);
int					ft_manage(t_vm *vm);
int					ft_print_det(t_list *chmp, unsigned char *mem, int pos);
int					ft_print_debug(t_list *champ, unsigned char *mem, int pos,
									t_vm *vm);
int					ft_carry(int reg_val);
void				ft_print_bit(int i, unsigned char *mem, int pos, char *c);
void				ft_print_cor(unsigned char *mem, int pos, t_vm *vm,
									t_dump *p);
void				ft_init_param(t_dump *param);
int					ft_check_instr(t_list *chmp, int pos, unsigned char *mem,
									int debug);
void				ft_display_hexa(int nbr, const char *base, const int size,
									int zero);
void				ft_d(t_list *chmp, unsigned char *mem, int pos, t_vm *vm);
void				ft_init_vm(t_vm *vm, int nb, t_list *chmp);
int					ft_check_byte(unsigned char *mem, int pos, int param);
int					ft_check_arg(int byte, int t);
int					ft_add(t_list *chmp, unsigned char *mem, int pos);
int					ft_aff(t_list *chmp, unsigned char *mem, int pos);
int					ft_and(t_list *chmp, unsigned char *mem, int pos);
int					ft_fork(t_list *chmp, unsigned char *mem, int pos);
int					ft_ld(t_list *chmp, unsigned char *mem, int pos);
int					ft_ldi(t_list *chmp, unsigned char *mem, int pos);
int					ft_lfork(t_list *chmp, unsigned char *mem, int pos);
int					ft_live(t_list *chmp, unsigned char *mem, int pos);
int					ft_lld(t_list *chmp, unsigned char *mem, int pos);
int					ft_lldi(t_list *chmp, unsigned char *mem, int pos);
int					ft_or(t_list *chmp, unsigned char *mem, int pos);
int					ft_st(t_list *chmp, unsigned char *mem, int pos);
int					ft_sti(t_list *chmp, unsigned char *mem, int pos);
int					ft_sub(t_list *chmp, unsigned char *mem, int pos);
int					ft_xor(t_list *chmp, unsigned char *mem, int pos);
int					ft_zjmp(t_list *chmp, unsigned char *mem, int pos);
int					ft_check_game(t_vm *vm);
int					ft_winner(t_vm *vm);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 15:47:24 by glafitte          #+#    #+#             */
/*   Updated: 2015/03/31 09:45:54 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "op.h"
# include <ncurses.h>
# include <curses.h>
# include <sys/stat.h>

# define USE_LIBFT
# define USAGE(str)		ft_usage(__FILE__, __LINE__, str)
# define ERR_LOC(str)	ft_err_loc(__FILE__, __LINE__, str)
# define C_NONE			"\033[0m"
# define C_BOLD			"\033[1m"
# define C_ITALIC		"\033[3m"
# define C_UNDERLINE	"\033[4m"
# define C_BLINK		"\033[5m"
# define C_HL_WHITE		"\033[7m"
# define C_NO_BOLD		"\033[22m"
# define C_NO_UNDERLINE	"\033[24m"
# define C_BLACK		"\033[30m"
# define C_RED			"\033[31m"
# define C_GREEN		"\033[32m"
# define C_BROWN		"\033[33m"
# define C_BLUE			"\033[34m"
# define C_MAGENTA		"\033[35m"
# define C_CYAN			"\033[36m"
# define C_HL_RED		"\033[41m"
# define C_HL_GREEN		"\033[42m"
# define C_HL_YELLOW	"\033[43m"
# define C_HL_BLUE		"\033[44m"
# define C_HL_PINK		"\033[45m"
# define C_HL_CYAN		"\033[46m"
# define C_HL_GRAY		"\033[47m"
# define C_GRAY			"\033[90m"

# ifdef USE_LIBFT

#  include "libft.h"

# endif

typedef struct		s_option
{
	int				dump;
	int				number_for_n;
	int				n_number;
	int				*ft_n_number;
	int				num_cor;
	int				option;
	int				addr_a_id;
	int				number_a_id;
	int				debug;
	int				debugx;
	int				cycle_d;
	char			**ft_cor;
}					t_option;

typedef struct		s_list
{
	int				val_tmp;
	int				ret;
	int				root;
	int				init_pos;
	int				pc;
	int				nb_tour;
	int				debug;
	int				debugx;
	int				cycle_d;
	char			carry;
	int				cycle;
	int				live;
	int				fork;
	int				fork_nb;
	int				last_live;
	int				live_for_dump;
	int				winner;
	int				cor;
	int				reg[REG_NUMBER];
	t_header		*chpm;
	struct s_list	*prev;
	struct s_list	*next;
	char			**cor_name;
}					t_list;

int					ft_check_flag(t_list *chmp, int flag);
int					ft_check_debug(char **argv, t_option *opt);
int					ft_check_debugx(char **argv, t_option *opt);
int					ft_result(t_list *chmp);
int					ft_fprintf(int fd, char const *format, ...);
void				ft_puterror(char *error);
void				ft_lseek(const int fd, off_t offset, int whence);
int					ft_game(unsigned char *mem, t_list *root, int nb);
int					ft_read(int fd, void *buf, size_t count);
int					ft_good_path(char *name);
int					ft_cor(char *str);
int					ft_read(int fd, void *buffer, size_t count);
void				ft_usage(char *file, int line, char *err);
void				ft_err_loc(char *file, int line, char *msg);
int					ft_getnbr_p(const char *str);
int					ft_get_rgb(int r, int g, int b);
int					ft_console(void);
int					ft_interface(void);
unsigned char		*ft_init_mem(void);
t_list				*ft_parser(int ar, char **av, unsigned char *mem, int *nb);
void				ft_check_nbr(char **argv, t_option *opt);
void				ft_after_check(char **argv);
void				ft_chang_nbr(t_option *opt, int c);
void				ft_loop_nbr(int a, int c, char *num);
t_list				*ft_make_lst(void);
void				ft_add_before(int fd, t_list **lst, int i);
int					ft_strlen_arg(char	**tab);
int					ft_open(const char *pathname, int flags, mode_t mode);
void				ft_swap_initchar(const int max, const int min,
										t_option *opt);
void				ft_place_champ(t_option *opt, t_list *root,
									unsigned char *mem);
char				*ft_int_array(int nbr);
char				ft_strcmp_cr(char const *s1, char const *s2);
t_list				*ft_parse_vm(t_option *opt, unsigned char *mem, int *nb);
void				ft_init(t_option *opt);
void				ft_code_in_mem(unsigned char *mem, char *cor, int pos);
int					ft_print_mem(unsigned char *mem, int i, t_list *root);
void				ft_swap_initchar(int max, int min, t_option *opt);
int					ft_check_cor(char **av, t_option *opt);
int					ft_check_dump(char **argv, t_option *opt);
void				ft_freeparser(t_option *opt);

#endif

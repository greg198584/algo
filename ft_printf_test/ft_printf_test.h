/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 08:45:20 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/20 16:43:29 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TEST_H
# define FT_PRINTF_TEST_H

# include <ft_printf.h>
# include "libft/libft.h"

# define C_NONE		"\033[0m"
# define C_BOLD		"\033[1m"
# define C_BLACK	"\033[30m"
# define C_RED		"\033[31m"
# define C_GREEN	"\033[32m"
# define C_BROWN	"\033[33m"
# define C_BLUE		"\033[34m"
# define C_MAGENTA	"\033[35m"
# define C_CYAN		"\033[36m"
# define C_GRAY		"\033[37m"

int		ft_option_d(int nbr, int b);
int		ft_option_bigd(unsigned int nbr, unsigned int count);
int		ft_option_ptr(void);
int		ft_option_str(char *s, char *filename);
int		ft_option_char(void);
int		ft_flag_options(void);
int		ft_precision(void);
int		ft_hexa_min(void);
int		ft_hexa_max(void);
int		ft_octal_int(void);
int		ft_octal_unint(void);
int		ft_long_int(void);
int		ft_option_charunint(void);
int		ft_option_champlarge(void);
int		ft_option_big_s(void);
int		ft_option_big_c(void);
int		ft_option_len(void);

#endif

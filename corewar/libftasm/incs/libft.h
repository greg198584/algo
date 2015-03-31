/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 10:06:24 by igomez            #+#    #+#             */
/*   Updated: 2015/03/07 16:27:59 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

/*
**	Assembler function!
*/
extern int		ft_abs(int n);
extern int		ft_min(int a, int b);
extern int		ft_max(int a, int b);
extern int		ft_isupper(int c);
extern int		ft_islower(int c);
extern int		ft_isalpha(int c);
extern int		ft_isdigit(int c);
extern int		ft_isalnum(int c);
extern int		ft_isascii(int c);
extern int		ft_isprint(int c);
extern int		ft_tolower(int c);
extern int		ft_toupper(int c);

extern size_t	ft_strlen(char const *s);
extern char		*ft_strdup(char const *s);
extern void		ft_bzero(void *s, size_t n);
extern char		*ft_strcat(char *s1, char const *s2);
extern void		*ft_memset(void *b, int c, size_t len);
extern void		*ft_memcpy(void *dst, void const *src, size_t n);
extern int		ft_strcmp(char const *s1, char const *s2);
extern int		ft_strncmp(char const *s1, char const *s2, size_t n);

extern void		ft_putchar(int c);
extern void		ft_putchar_fd(int c, int fd);
extern void		ft_puts(char const *s);
extern void		ft_putstr(char const *s);
extern void		ft_putstr_fd(char const *s, int fd);

/*
**	C function!
*/
int				ft_fuck(int n);
void			ft_swap(int *a, int *b);
int				ft_atoi(char const *s);
size_t			ft_nbrlen(int n);
char			*ft_itoa(int n);

void			ft_memdel(void **ap);
void			*ft_memalloc(size_t size);
void			*ft_memchr(void const *s, int c, size_t n);
void			*ft_memmove(void *dst, void const *src, size_t len);

int				ft_fprintf(int fd, char const *format, ...);
char			*ft_strrev(char *s);
char			*ft_strchr(char const *s, int c);
char			*ft_strrchr(char const *s, int c);
char			*ft_strcpy(char *s1, char const *s2);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strstr(char const *s1, char const *s2);
char			*ft_strnstr(char const *s1, char const *s2, size_t len);
char			*ft_strncat(char *s1, char const *s2, size_t n);
char			*ft_strncpy(char *s1, char const *s2, size_t n);
char			*ft_strrep(char *str, char const *sub, char const *rep, int r);

#endif

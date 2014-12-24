/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 09:49:10 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/23 16:28:34 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_test.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	ft_option_d(int nbr, int b)
{
	printf("option_d = %d et %d\n", nbr, b);
	while (nbr < b)
	{
		ft_printf("===================================================\n");
		ft_printf("==================== Option d  ====================\n");
		printf(C_GREEN"[ PRINTF ]\t:  %d"C_NONE"\n", nbr);
		ft_printf("[ ft_printf ]\t:  %d\n", nbr);
		ft_printf("===================================================\n");
		ft_printf("==================== Option i =====================\n");
		printf(C_GREEN"[ PRINTF ]\t:  %i"C_NONE"\n", nbr);
		ft_printf("[ ft_printf ]\t:  %i\n", nbr);
		ft_printf("===================================================\n");
		ft_printf("===================================================\n");
		nbr++;
	}
	return (0);
}

int	ft_option_bigd(unsigned int nbr, unsigned int count)
{
	while (nbr < count)
	{
		ft_printf("===================================================\n");
		ft_printf("==================== Option D =====================\n");
		printf(C_GREEN"[ PRINTF ]\t:  %D"C_NONE"\n", nbr);
		ft_printf("[ ft_printf ]\t:  %D\n", nbr);
		ft_printf("===================================================\n");
		ft_printf("==================== Option u =====================\n");
		printf(C_GREEN"[ PRINTF ]\t:  %u"C_NONE"\n", nbr);
		ft_printf("[ ft_printf ]\t:  %u\n", nbr);
		ft_printf("===================================================\n");
		ft_printf("===================================================\n");
		nbr++;
	}
	return (0);
}

int	ft_option_ptr(void)
{
	int				value = 83;
	unsigned int	count = 78;
	int				i = -42;
	char			*str = "coucou tous le monde, ß∂åß¬¬øœ∑´…¬ƒ∆˚˚åß";
	char			c = 'c';


	ft_putendl("\n");
	ft_printf("====================================================\n");
	ft_printf("====================== option p ====================\n");
	ft_putendl("CHAR chaine :");
	printf(C_GREEN"[ PRINTF ]\t: adresse de str -> %p\n"C_NONE"\n", &str);
	ft_printf("[ ft_printf ]\t: adresse de str -> %p\n", &str);
	ft_printf("====================================================\n");
	ft_printf("====================================================\n");
	ft_putchar('\n');
	ft_printf("====================================================\n");
	ft_printf("====================== option p ====================\n");
	ft_putendl("INT");
	printf(C_GREEN"[ PRINTF ]\t: adresse de value -> %p\n"C_NONE"\n", &value);
	ft_printf("[ ft_printf ]\t: adresse de value -> %p\n", &value);
	ft_printf("====================================================\n");
	ft_printf("====================================================\n");
	ft_putchar('\n');	
	ft_printf("====================================================\n");
	ft_printf("====================== option p ====================\n");
	ft_putendl("INT :");
	printf(C_GREEN"[ PRINTF ]\t: adresse de i -> %p\n"C_NONE"\n", &i);
	ft_printf("[ ft_printf ]\t: adresse de i -> %p\n", &i);
	ft_printf("====================================================\n");
	ft_printf("====================================================\n");
	ft_putchar('\n');
	ft_printf("====================================================\n");
	ft_printf("====================== option p ====================\n");
	ft_putendl("CHAR caracteres :");
	printf(C_GREEN"[ PRINTF ]\t: adresse de c -> %p\n"C_NONE"\n", &c);
	ft_printf("[ ft_printf ]\t: adresse de c -> %p\n", &c);
	ft_printf("====================================================\n");
	ft_printf("====================================================\n");
	ft_putchar('\n');
	ft_printf("====================================================\n");
	ft_printf("====================== option p ====================\n");
	ft_putendl("UNSIGNED INT :");
	printf(C_GREEN"[ PRINTF ]\t: adresse de count -> %p\n"C_NONE"\n", &count);
	ft_printf("[ ft_printf ]\t: adresse de count -> %p\n", &count);
	ft_printf("====================================================\n");
	ft_printf("====================================================\n");
	return (0);
}

int	ft_option_str(char *s, char *filename)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(filename, O_RDONLY);
	ft_printf("====================================================\n");
	ft_printf("====================== option s ====================\n");
	ft_putendl("ouverture fichier - affichage avec PRINTF :\n");
	while ((i = get_next_line(fd, &line) > 0))
			printf("%s\n", line);
	ft_printf("====================================================\n");
	ft_putchar('\n');
	close(fd);
	fd = open(filename, O_RDONLY);
	ft_printf("====================================================\n");
	ft_printf("====================== option s ====================\n");
	ft_putendl("ouverture fichier - affichage avec FT_PRINTF :\n");
	while ((i = get_next_line(fd, &line) > 0))
		ft_printf("%s\n", line);
	ft_printf("====================================================\n\n");
	close(fd);
	ft_printf("====================================================\n");
	ft_printf("====================== option s ====================\n\n");
	printf(C_GREEN"[ PRINTF ]\t: chaine str -> %s\n"C_NONE"\n", s);
	ft_printf("[ ft_printf ]\t: chaine str -> %s\n", s);
	ft_printf("\n====================================================\n");
	ft_printf("====================================================\n");
	ft_putchar('\n');
	ft_printf("=========== option s - caractere etranger ==========\n\n");
	printf(C_GREEN"[ PRINTF ]\t : caracteres etranger --> %s"C_NONE"\n", "大家好");
	ft_printf("[ FT_PRINTF ]\t : caracteres etranger --> %s\n", "大家好");
	ft_printf("\n====================================================\n");
	return (0);
}

int	ft_option_char(void)
{
	int		i;
	char	*str = "coucou 42, åß∂˚∆œø";

	i = 0;
	while (str[i] != '\0')
	{
		printf(C_GREEN"[ PRINTF ]\t: caractere [%c]"C_NONE"\n", str[i]);
		ft_printf("[ ft_printf ]\t: caractere [%c]\n\n", str[i]);
		i++;
	}
	return (0);
}

int	ft_flag_options(void)
{
	char	*str = "coucou";
	int		i = 42;

	ft_printf("============================================================\n");
	ft_putendl("Test modulo :");
	printf(C_GREEN"[ PRINTF ] : [%%]\n"C_NONE"\n");
	ft_printf("[ FT_PRINTF ] : [%%]\n\n");
	printf(C_GREEN"[ PRINTF ] : [%%i]\n"C_NONE"\n");
	ft_printf("[ FT_PRINTF ] : [%%i]\n\n", i);
	ft_printf("============================================================\n");
	ft_putendl(C_GREEN"\n[ PRINTF _Test # - 0 - ( - ) - + - ' ' ]"C_NONE);
	printf("#\t->\t[%#d]\n", i);
	printf("0\t->\t[%0d]\n", i);
	printf("(-)\t->\t[%-d]\n", i);
	printf("+\t->\t[%+d]\n", i);
	printf("' '\t->\t[% d]\n\n", i);
	ft_putendl("[ FT_PRINTF _ Test # - 0 - ( - ) - + - ' ' ]");
	ft_printf("#\t->\t[%#d]\n", i);
	ft_printf("0\t->\t[%0d]\n", i);
	ft_printf("(-)\t->\t[%-d]\n", i);
	ft_printf("+\t->\t[%+d]\n", i);
	ft_printf("' '\t->\t[% d]\n\n", i);
	ft_printf("============================================================\n");
	ft_putendl("Meme test avec valeur plus grande\n");
	ft_putendl(C_GREEN"\n[ PRINTF _Test # - 0 - ( - ) - + - ' ' ]"C_NONE);
	printf("#\t->\t[%########d]\n", i);
	printf("0\t->\t[%00000000d]\n", i);
	printf("(-)\t->\t[%------d]\n", i);
	printf("+\t->\t[%++++++++d]\n", i);
	printf("' '\t->\t[%      d]\n\n", i);
	ft_putendl("[ FT_PRINTF _ Test # - 0 - ( - ) - + - ' ' ]");
	ft_printf("#\t->\t[%########d]\n", i);
	ft_printf("0\t->\t[%00000000d]\n", i);
	ft_printf("(-)\t->\t[%------d]\n", i);
	ft_printf("+\t->\t[%++++++++d]\n", i);
	ft_printf("' '\t->\t[%      d]\n\n", i);
	ft_printf("============================================================\n");
	ft_putendl("{{ Meme test avec nombre }}\n");
	ft_putendl(C_GREEN"[ PRINTF _Test # - 0 - ( - ) - + - ' ' ]"C_NONE);
	printf("#12\t->\t[%#12d]\n", i);
	printf("(-4)\t->\t[%-4d]\n", i);
	printf("+4\t->\t[%+4d]\n\n", i);
	ft_putendl("[ FT_PRINTF _ Test # - 0 - ( - ) - + - ' ' ]");
	ft_printf("#12\t->\t[%#12d]\n", i);
	ft_printf("(-4)\t->\t[%-4d]\n", i);
	ft_printf("+4\t->\t[%+4d]\n\n", i);
	ft_printf("============================================================\n");
	return (0);
}

int	ft_precision(void)
{
	int 			i = -42;
	unsigned int 	b = 42;
	float			c = 42.42;
	char			d = 'A';
	char			*str = "coucou";

	ft_printf("============================================================\n");
	ft_printf("======================= Precision  =========================\n");
	printf(C_GREEN"[ PRINTF ]\t : int   et 08 --> %08d"C_NONE"\n", i);
	printf(C_GREEN"[ PRINTF ]\t : int   et 10 --> %10d"C_NONE"\n", i);
	printf(C_GREEN"[ PRINTF ]\t : int   et 15 --> %15d"C_NONE"\n", i);
	printf(C_GREEN"[ PRINTF ]\t : uint  et 08 --> %08D"C_NONE"\n", b);
	printf(C_GREEN"[ PRINTF ]\t : uint  et 15 --> %15D"C_NONE"\n", b);
	printf(C_GREEN"[ PRINTF ]\t : char  et 08 --> %08c"C_NONE"\n", d);
	printf(C_GREEN"[ PRINTF ]\t : char  et 15 --> %15c"C_NONE"\n", d);
	printf(C_GREEN"[ PRINTF ]\t : chaine  et 08 --> %08s"C_NONE"\n", str);
	printf(C_GREEN"[ PRINTF ]\t : chaine  et 15 --> %15s"C_NONE"\n", str);
	printf(C_GREEN"[ PRINTF ]\t : adress  et 08 --> %08p"C_NONE"\n", &i);
	printf(C_GREEN"[ PRINTF ]\t : adress  et 15 --> %20p"C_NONE"\n", &i);
	printf(C_GREEN"[ PRINTF ]\t : hexa  et 08 --> %08x"C_NONE"\n", b);
	printf(C_GREEN"[ PRINTF ]\t : hexa  et 15 --> %15x"C_NONE"\n", b);
	printf(C_GREEN"[ PRINTF ]\t : octal  et 08 --> %08o"C_NONE"\n", b);
	printf(C_GREEN"[ PRINTF ]\t : octal  et 15 --> %15o"C_NONE"\n", b);
	ft_printf("============================================================\n");
	ft_printf("============================================================\n");
	ft_putstr("\n");
	ft_printf("============================================================\n");
	ft_printf("======================= Precision  =========================\n");
	ft_printf("[ FT_PRINTF ]\t : int   et 08 --> %08d\n", i);
	ft_printf("[ FT_PRINTF ]\t : int   et 10 --> %10d\n", i);
	ft_printf("[ FT_PRINTF ]\t : int   et 15 --> %15d\n", i);
	ft_printf("[ FT_PRINTF ]\t : uint  et 08 --> %08D\n", b);
	ft_printf("[ FT_PRINTF ]\t : uint  et 15 --> %15D\n", b);
	ft_printf("[ FT_PRINTF ]\t : char  et 08 --> %08c\n", d);
	ft_printf("[ FT_PRINTF ]\t : char  et 15 --> %15c\n", d);
	ft_printf("[ FT_PRINTF ]\t : chaine  et 08 --> %08s\n", str);
	ft_printf("[ FT_PRINTF ]\t : chaine  et 15 --> %15s\n", str);
	ft_printf("[ FT_PRINTF ]\t : adress  et 08 --> %08p\n", &i);
	ft_printf("[ FT_PRINTF ]\t : adress  et 15 --> %20p\n", &i);
	ft_printf("[ FT_PRINTF ]\t : hexa  et 08 --> %08x\n", b);
	ft_printf("[ FT_PRINTF ]\t : hexa  et 15 --> %15x\n", b);
	ft_printf("[ FT_PRINTF ]\t : octal  et 08 --> %08o\n", b);
	ft_printf("[ FT_PRINTF ]\t : octal  et 15 --> %15o\n", b);
	ft_printf("============================================================\n");
	ft_printf("============================================================\n");
	return (0);
}

int	ft_hexa_min(void)
{
	int				a = 10;
	int				b = 11;
	unsigned int	c = -20;
	unsigned int	d = -19;
	char			g = 'A';
	char			h = 'B';
	char			*nbr = "12";

/******************************************************************************/

	ft_printf("====================================================\n");
	ft_printf("====================================================\n");
	printf(C_GREEN"[ PRINTF ]\t: valeur de %d en hexa -> %x\n"C_NONE"\n", a, a);
	printf(C_GREEN"[ PRINTF ]\t: valeur de %D en hexa -> %x\n"C_NONE"\n", c, c);
	printf(C_GREEN"[ PRINTF ]\t: valeur de %c en hexa -> %x\n"C_NONE"\n", g, g);
	ft_printf("====================================================\n");
	ft_printf("====================================================\n");
	ft_printf("[ FT_PRINTF ]\t: valeur de %d en hexa -> %x\n", a, a);
	ft_printf("[ FT_PRINTF ]\t: valeur de %D en hexa -> %x\n", c, c);
	ft_printf("[ FT_PRINTF ]\t: valeur de %c en hexa -> %x\n", g, g);

/******************************************************************************/

	ft_printf("====================================================\n\n");
	ft_printf("[ FT_PRINTF ] unsigned int ==> %x\n", a);
	ft_printf("[ FT_PRINTF ] char ==> %x\n\n", g);
	ft_printf("====================================================\n");

	while (a < b)
	{
		ft_printf("\n====================================================\n\n");
		ft_printf("================= hexa min -- int ==================\n\n");
		printf(C_GREEN"[ PRINTF ]\t: valeur de %d en hexa -> %x\n"C_NONE"\n", a, a);
		ft_printf("ft_printf\t: valeur de %d en hexa -> %x\n\n", a, a);
		a++;
	}
	while (c < d)
	{
		ft_printf("====================================================\n");
		ft_printf("============ hexa min -- unsigned int ==============\n\n");
		printf(C_GREEN"[ PRINTF ]\t: valeur de %D en hexa %x\n"C_NONE"\n", c, c);
		ft_printf("ft_printf\t: valeur de %D en hexa %x\n\n", c, c);
		c++;
	}
	while (g < h)
	{
		ft_printf("====================================================\n");
		ft_printf("================ hexa min -- char ==================\n\n");
		printf(C_GREEN"[ PRINTF ]\t: valeur de %c en h:wexa %x\n"C_NONE"\n", g, g);
		ft_printf("ft_printf\t: valeur de %c en hexa %x\n\n", g, g);
		g++;
	}
	ft_printf("====================================================\n");
	return (0);
}

int	ft_hexa_max(void)
{
	int				a = 10;
	int				b = 11;
	unsigned int	c = -20;
	unsigned int	d = -19;
	char			g = 'A';
	char			h = 'B';
	char			*nbr = "12";

	while (a < b)
	{
		ft_printf("====================================================\n");
		ft_printf("================= hexa min -- int ==================\n");
		printf(C_GREEN"[ PRINTF ]\t: valeur de %d en hexa -> %X\n"C_NONE"\n", a, a);
		ft_printf("ft_printf\t: valeur de %d en hexa -> %X\n", a, a);
		a++;
	}
	while (c < d)
	{
		ft_printf("====================================================\n");
		ft_printf("============ hexa min -- unsigned int ==============\n");
		printf(C_GREEN"[ PRINTF ]\t: valeur de %D en hexa %X\n"C_NONE"\n", c, c);
		ft_printf("ft_printf\t: valeur de %D en hexa %X\n", c, c);
		c++;
	}
	while (g < h)
	{
		ft_printf("====================================================\n");
		ft_printf("============ hexa min -- char ======================\n");
		printf(C_GREEN"[ PRINTF ]\t: valeur de %c en hexa %X\n"C_NONE"\n", g, g);
		ft_printf("ft_printf\t: valeur de %c en hexa  %X\n", g, g);
		g++;
	}
	ft_printf("====================================================\n");
	return (0);
}

int	ft_octal_int(void)
{
	int				a = 10;
	int				b = 20;
	unsigned int	c = -20;
	unsigned int	d = -10;
	float			e = 10.5;
	float			f = 15.7;
	char			g = 'A';
	char			h = 'Z';
	char			*nbr = "12";

	while (a < b)
	{
		ft_printf("====================================================\n");
		ft_printf("================= octal min -- int ==================\n");
		printf(C_GREEN"[ PRINTF ]\t: valeur de %d  --> %o\n"C_NONE"\n", a, a);
		ft_printf("ft_printf\t: valeur de %d en octal -> %o\n", a, a);
		a++;
	}
	while (c < d)
	{
		ft_printf("====================================================\n");
		ft_printf("============ octal  min -- unsigned int ==============\n");
		printf(C_GREEN"[ PRINTF ]\t: valeur de %D --> %o\n"C_NONE"\n", c, c);
		ft_printf("ft_printf\t: valeur de %D en octal %o\n", c, c);
		c++;
	}
	while (g < h)
	{
		ft_printf("====================================================\n");
		ft_printf("============ octal min -- char ======================\n");
		printf(C_GREEN"[ PRINTF ]\t: valeur de %c --> %o\n"C_NONE"\n", g, g);
		ft_printf("ft_printf\t: valeur de %c en octal %o\n", g, g);
		g++;
	}
	ft_printf("====================================================\n");
	return (0);
}

int	ft_octal_unint(void)
{
	int				a = 10;
	int				b = 20;
	unsigned int	c = -20;
	unsigned int	d = -10;
	float			e = 10.5;
	float			f = 15.7;
	char			g = 'A';
	char			h = 'Z';
	char			*nbr = "12";

	while (a < b)
	{
		ft_printf("====================================================\n");
		ft_printf("================ octal unsigned int ================\n");
		printf(C_GREEN"[ PRINTF ]\t: valeur de %d --> %X\n"C_NONE"\n", a, a);
		ft_printf("ft_printf\t: valeur de %d en octal -> %O\n", a, a);
		a++;
	}
	while (c < d)
	{
		ft_printf("====================================================\n");
		ft_printf("================ octal unsigned int ================\n");
		printf(C_GREEN"[ PRINTF ]\t: valeur de %D --> %O\n"C_NONE"\n", c, c);
		ft_printf("ft_printf\t: valeur de %D en octal %O\n", c, c);
		c++;
	}
	while (e < f)
	{
		ft_printf("====================================================\n");
		ft_printf("=============== octal unsigned int =================\n");
		printf(C_GREEN"[ PRINTF ]\t: valeur de %D --> %O\n"C_NONE"\n", e, e);
		ft_printf("ft_printf\t: valeur de %D en octal %O\n", e, e);
		e++;
	}
	while (g < h)
	{
		ft_printf("====================================================\n");
		ft_printf("============== octal unsigned int ==================\n");
		printf(C_GREEN"[ PRINTF ]\t: valeur de %c --> %O\n"C_NONE"\n", g, g);
		ft_printf("ft_printf\t: valeur de %c en octal %O\n", g, g);
		g++;
	}
	ft_printf("=========================================================\n");
	return (0);
}

int	ft_long_int(void)
{
	ft_putendl("ft_long_int");
	return (0);
}

int		ft_option_charunint(void)
{
	char	*str = "texte ßƒ∂¬∂ƒ˚ø´…ææœπœ´®ƒß";
	int		i = 0;

	ft_printf("============================================================\n");
	ft_printf("===================== Option S -- char  ====================\n");
	while (str[i] != '\0')
	{
		printf(C_GREEN"[ PRINTF ]\t: [%C]"C_NONE"\n", str[i]);
		ft_printf("[ FT_PRINTF ]\t: [%C]\n", str[i]);
		i++;
	}
	ft_printf("============================================================\n");
	ft_printf("============================================================\n");
	return (0);
}

int		ft_option_champlarge(void)
{
/*	int 			i = -42;
	unsigned int 	b = 42;
	float			c = 42.42;
	char			d = 'A';

	ft_printf("============================================================\n");
	ft_printf("============================================================\n");
	ft_printf("================= Largeur de champs -- int ==================\n");
	printf(C_GREEN"[ PRINTF ]\t : int -> option hh --> %hhd"C_NONE"\n", i);
	printf(C_GREEN"[ PRINTF ]\t : int -> option h  --> %hd"C_NONE"\n", i);
	printf(C_GREEN"[ PRINTF ]\t : int -> option l  --> %ld"C_NONE"\n", i);
	printf(C_GREEN"[ PRINTF ]\t : int -> option ll --> %lld"C_NONE"\n", i);
	printf(C_GREEN"[ PRINTF ]\t : int -> option j  --> %jd"C_NONE"\n", i);
	printf(C_GREEN"[ PRINTF ]\t : int -> option t  --> %td"C_NONE"\n", i);
	printf(C_GREEN"[ PRINTF ]\t : int -> option z  --> %zd"C_NONE"\n", i);
	ft_printf("[ FT_PRINTF ]\t : int -> option hh --> %hhd\n", i);
	ft_printf("[ FT_PRINTF ]\t : int -> option h --> %hd\n", i);
	ft_printf("[ FT_PRINTF ]\t : int -> option l --> %ld\n", i);
	ft_printf("[ FT_PRINTF ]\t : int -> option ll --> %lld\n", i);
	ft_printf("[ FT_PRINTF ]\t : int -> option j --> %jd\n", i);
	ft_printf("[ FT_PRINTF ]\t : int -> option t --> %td\n", i);
	ft_printf("[ FT_PRINTF ]\t : int -> option z --> %zd\n", i);
	ft_printf("============================================================\n");
	ft_printf("============================================================\n");
	ft_putstr("\n");
	ft_printf("============================================================\n");
	ft_printf("============================================================\n");
	ft_printf("================ Largeur de champs -- u-int ================\n");
	printf(C_GREEN"[ PRINTF ]\t : u-int -> option hh --> %hhD"C_NONE"\n", b);
	printf(C_GREEN"[ PRINTF ]\t : u-int -> option h  --> %hD"C_NONE"\n", b);
	printf(C_GREEN"[ PRINTF ]\t : u-int -> option l  --> %lD"C_NONE"\n", b);
	printf(C_GREEN"[ PRINTF ]\t : u-int -> option ll --> %llD"C_NONE"\n", b);
	printf(C_GREEN"[ PRINTF ]\t : u-int -> option j  --> %jD"C_NONE"\n", b);
	printf(C_GREEN"[ PRINTF ]\t : u-int -> option t  --> %tD"C_NONE"\n", b);
	printf(C_GREEN"[ PRINTF ]\t : u-int -> option z  --> %zD"C_NONE"\n", b);
	ft_printf("[ FT_PRINTF ]\t : u-int -> option hh --> %hhD\n", b);
	ft_printf("[ FT_PRINTF ]\t : u-int -> option h --> %hD\n", b);
	ft_printf("[ FT_PRINTF ]\t : u-int -> option l --> %lD\n", b);
	ft_printf("[ FT_PRINTF ]\t : u-int -> option ll --> %llD\n", b);
	ft_printf("[ FT_PRINTF ]\t : u-int -> option j --> %jD\n", b);
	ft_printf("[ FT_PRINTF ]\t : u-int -> option t --> %tD\n", b);
	ft_printf("[ FT_PRINTF ]\t : u-int -> option z --> %zD\n", b);
	ft_printf("============================================================\n");
	ft_printf("============================================================\n");
	ft_putstr("\n");
	ft_printf("============================================================\n");
	ft_printf("============================================================\n");
	ft_printf("================= Largeur de champs -- char ================\n");
	printf(C_GREEN"[ PRINTF ]\t : char -> option hh --> %hhc"C_NONE"\n", d);
	printf(C_GREEN"[ PRINTF ]\t : char -> option h  --> %hc"C_NONE"\n", d);
	printf(C_GREEN"[ PRINTF ]\t : char -> option l  --> %lc"C_NONE"\n", d);
	printf(C_GREEN"[ PRINTF ]\t : char -> option ll --> %llc"C_NONE"\n", d);
	printf(C_GREEN"[ PRINTF ]\t : char -> option j  --> %jc"C_NONE"\n", d);
	printf(C_GREEN"[ PRINTF ]\t : char -> option t  --> %tc"C_NONE"\n", d);
	printf(C_GREEN"[ PRINTF ]\t : char -> option z  --> %zc"C_NONE"\n", d);
	ft_printf("[ FT_PRINTF ]\t : char -> option hh --> %hhd\n", d);
	ft_printf("[ FT_PRINTF ]\t : char -> option h --> %hc\n", d);
	ft_printf("[ FT_PRINTF ]\t : char -> option l --> %lc\n", d);
	ft_printf("[ FT_PRINTF ]\t : char -> option ll --> %llc\n", d);
	ft_printf("[ FT_PRINTF ]\t : char -> option j --> %jc\n", d);
	ft_printf("[ FT_PRINTF ]\t : char -> option t --> %tc\n", d);
	ft_printf("[ FT_PRINTF ]\t : char -> option z --> %zc\n", d);
	ft_printf("============================================================\n");
	ft_printf("============================================================\n");*/
	return (0);
}

int	ft_option_big_s(void)
{
	ft_printf("============================================================\n");
	ft_printf("============================================================\n");
	ft_printf("===================== Option S + chaine ====================\n");
	printf(C_GREEN"[ PRINTF ]\t : chaine normal --> %S"C_NONE"\n", L"ceci est une chaine normal");
	ft_printf("=============== PRINTF chaine particulier ==================\n");
	printf(C_GREEN"[ PRINTF ]\t : chaine particulier --> %S"C_NONE"\n", L" chaine ˚∂ƒˆ……œ∑ø´∆∂");
	printf(C_GREEN"[ PRINTF ]\t : caracteres etranger --> %S"C_NONE"\n", L"大家好");
	ft_printf("\n============================================================\n");
	ft_printf("[ FT_PRINTF ]\t : chaine --> %S\n", "chaine qui s'affiche");
	ft_printf("============= FT_PRINTF chaine particulier =================\n");
	ft_printf("[ FT_PRINTF ]\t : chaine particulier --> %S\n", "chaine ¬ƒ∆˚∂ƒ∆ˆ´∑∆…œ∑´∑´œ");
	ft_printf("[ FT_PRINTF ]\t : caracteres etranger --> %S\n", "大家好");
	ft_printf("\n============================================================\n");
	ft_printf("============================================================\n");
	return (0);
}

int	ft_option_len(void)
{
	char	*str = "salut a tous";
	char	a = 'A';
	int		i = 42;
	int		value;

	ft_printf("============================================================\n");
	ft_printf("====================== Longeur chaine ======================\n");
	ft_printf("{ FT_PRINTF PRINTF_OF}\n");
		value = printf("PRINTF_OF : Chaine = %s\n", str);
	printf("\tlu ==> [ %d ]\n\n", value);
		value = ft_printf("FT_PRINTF : Chaine = %s\n", str);
	printf("\tlu ==> [ %d ]\n\n", value);
		value = printf("PRINTF_OF : Caractere = %c\n", a);
	printf("\tlu ==> [ %d ]\n\n", value);
		value = ft_printf("FT_PRINTF : Caractere = %c\n", a);
	printf("\tlu ==> [ %d ]\n\n", value);
		value = printf("PRINTF_OF : Int = %d\n", i);
	printf("\tlu ==> [ %d ]\n\n", value);
		value = ft_printf("FT_PRINTF : Int = %d\n", i);
	printf("\tlu ==> [ %d ]\n\n", value);
		value = printf("PRINTF_OF : hexa = %x\n", i);
	printf("\tlu ==> [ %d ]\n\n", value);
		value = ft_printf("FT_PRINTF : hexa = %x\n", i);
	printf("\tlu ==> [ %d ]\n\n", value);
		value = printf("PRINTF_OF : octal = %o\n", i);
	printf("\tlu ==> [ %d ]\n\n", value);
		value = ft_printf("FT_PRINTF : octal = %o\n", i);
	printf("\tlu ==> [ %d ]\n\n", value);
		value = printf("PRINTF_OF : adress = %p\n", &i);
	printf("\tlu ==> [ %d ]\n\n", value);
		value = ft_printf("FT_PRINTF : adress = %p\n", &i);
	printf("\tlu ==> [ %d ]\n\n", value);
	ft_printf("============================================================\n");
	return (0);
}

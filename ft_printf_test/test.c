/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 17:53:28 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/05 18:05:25 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
	int				i = 42;
	char			c = 'B';
	char			*str = "coucou tous le monde !";
	unsigned int	b = 4242;

	printf("options d = %d - options O = %O\n", i, i);
	printf("options c = %c - options O = %O\n", c, c);
	printf("options s = %s - options O = %O\n", str, str);
	printf("options D =  %D - options O = %O\n", b, b);
		
	printf("\n\noptions d = %d - options O = %o\n", i, i);
	printf("options c = %c - options O = %o\n", c, c);
	printf("options s = %s - options O = %o\n", str, str);
	printf("options D =  %D - options O = %o\n", b, b);

	
	return (0);
}

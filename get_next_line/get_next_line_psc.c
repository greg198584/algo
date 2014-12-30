/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_psc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 14:14:47 by glafitte          #+#    #+#             */
/*   Updated: 2014/11/13 14:50:58 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* pseudo code get_next_line*/

int		get_next_line(int const fd, char **line)
{
	/*
	 * declarer variable static chaine de caractere ,
	 * un tableau char, un pointeur charactere temporaire pour,
	 * stoquer une chaine , un entier.
	 *
	 * boucle (condition , recherche dans la chaine static, retour a la ligne)
	 *	--- si read ne lit pas , le fd dans le tableau de char , stopper la boucle 
	 *	--- mettre resultat de read dans la variable entiere
	 *	--- dernier caractere mis dans le tableau est egal a zero
	 *	--- la chaine , si elle est null , appelle allouer une chaine ,
	 *	--- en mettant le caractere lu, 
	 *	--- sinon joindre le nouveau caractere avec l'ancien.
	 *	--- fin de boucle.
	 *
	 *	si (variable temporaire = recherche emplacement de \n dans chaine)
	 *	line = chaine;
	 *	chaine = empl_temporaire + 1 ;
	 *	empl_temporaire = 0;
	 *	fin if.
	 *
	 *	sinon
	 *
	 *	line = chaine
	 *	retourner 0
	 *	fin sinon
	 *
	 *	retourner (1 - (empl_temporaire est il egal a null ? * 2)
	 * */
}

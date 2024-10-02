/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dna_to_rna_conversion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:47:39 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/10/02 22:04:06 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Deoxyribonucleic acid, DNA is the primary information storage molecule in biological systems. It is composed of four nucleic acid bases Guanine ('G'), Cytosine ('C'), Adenine ('A'), and Thymine ('T').

Ribonucleic acid, RNA, is the primary messenger molecule in cells. RNA differs slightly from DNA its chemical structure and contains no Thymine. In RNA Thymine is replaced by another nucleic acid Uracil ('U').

Create a function which translates a given DNA string into RNA.

For example:

"GCAT"  =>  "GCAU"

The input string can be of arbitrary length - in particular, it may be empty. All input is guaranteed to be valid, i.e. each input string will only ever consist of 'G', 'C', 'A' and/or 'T'.
*/

#include <stdlib.h>
#include <string.h>
/*
int	ft_strlen(const char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
*/
char	*dna_to_rna(const char *dna)
{
	int	i = 0;
	int len = strlen(dna);
	char *rna;
	rna = malloc(sizeof(char) * (len + 1));
	if (!rna)
		return (NULL);
	while (dna[i] != '\0')
	{
		if (dna[i] == 'T')
			rna[i] = 'U';
		else
			rna[i] = dna[i];
		i++;
	}
	rna[i] = '\0';
	return (rna);
}

#include <stdio.h>
int	main(void)
{
	char dna[] = "GCAT";
	char *rna;
	rna = dna_to_rna(dna);
	printf("%s\n", rna);
	free(rna);
} 


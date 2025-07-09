/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:15:36 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/09 17:48:20 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"
#include "ASpell.hpp"

SpellBook::SpellBook(void)
{
	for (int i = 0; i < 8; ++i)
	{
		spells[i] = NULL;
	}
	std::cout << "SpellBook created!" << std::endl;
}

SpellBook::~SpellBook()
{
	for (int i = 0; i < 8; ++i)
	{
		delete spells[i];
		spells[i] = NULL;
	}
	std::cout << "SpellBook destroyed!" << std::endl;
}

void	SpellBook::learnSpell(ASpell *s)
{
	if (!s)
		return ;
	for (int i = 0; i < 8; ++i)
	{
		if (spells[i] && spells[i]->getName() == s->getName())
			return ;
		if (!spells[i])
		{
			spells[i] = s->clone();
			return ;
		}
	}
}

void	SpellBook::forgetSpell(std::string const &sname)
{
	for (int i = 0; i < 8; ++i)
	{
		if (spells[i] && spells[i]->getName() == sname)
		{
			delete spells[i];
			spells[i] = NULL;
			return ;
		}
	}	
}

ASpell	*SpellBook::createSpell(std::string const &sname)
{
	for (int i = 0; i < 8; ++i)
	{
		if (spells[i] && spells[i]->getName() == sname)
			return (spells[i]->clone());
	}
	return NULL;
}


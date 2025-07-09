/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 21:03:39 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/09 17:47:26 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"

Warlock::Warlock(std::string const &n, std::string const &t): name(n), title(t)
{
	for (int i = 0; i < 8; ++i)
	{
		spells[i] = NULL;
	}
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	for (int i = 0; i < 8; ++i)
	{
		delete spells[i];
		spells[i] = NULL;
	}
	std::cout << name << ": My job here is done!" << std::endl;
}

std::string const Warlock::getName(void) const
{
	return (name);
}

std::string const Warlock::getTitle(void) const
{
	return (title);
}
		
void	Warlock::setTitle(std::string const &s)
{
	title = s;
}

void	Warlock::introduce(void) const
{
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell *spell)
{
	if (!spell)
		return ;
	for (int i = 0; i < 8; ++i)
	{
		if (spells[i] && spells[i]->getName() == spell->getName())
		{
			delete spell;
			return ;
		}
		if (!spells[i])
		{
			spells[i] = spell->clone();
			delete spell;
			return ;
		}		
	}
	delete spell;
}

void	Warlock::forgetSpell(std::string const &sname)
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

void	Warlock::launchSpell(std::string const &sname, ATarget const &target) const
{
	for (int i = 0; i < 8; ++i)
	{
		if (spells[i] && spells[i]->getName() == sname)
		{
			spells[i]->launch(target);
			return ;
		}
	}
}


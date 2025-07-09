/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:09:14 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/09 17:57:57 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"

Warlock::Warlock(std::string const &name, std::string const &title): _name(name), _title(title)
{
	for (int i = 0; i < 4; ++i)
		_spells[i] = NULL;
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	for (int i = 0; i < 4; ++i)
	{
		delete _spells[i];
		_spells[i] = NULL;
	}
	std::cout << _name << ": My job here is done!" << std::endl;
}

std::string	const	&Warlock::getName(void) const
{
	return (_name);
}

std::string const	&Warlock::getTitle(void) const
{
	return (_title);
}

void	Warlock::setTitle(std::string const &t)
{
	_title = t;
}

void	Warlock::introduce(void) const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell *s)
{
	if (!s)
		return ;
	for (int i = 0; i < 4; ++i)
	{
		if (_spells[i] && _spells[i]->getName() == s->getName())
		{
			return ;
		}
		if (!_spells[i])
		{
			_spells[i] = s->clone();
			return ;
		}
	}
}

void	Warlock::forgetSpell(std::string const &sn)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_spells[i] && _spells[i]->getName() == sn)
		{
			delete _spells[i];
			_spells[i] = NULL;
			return ;
		}
	}
}

void	Warlock::launchSpell(std::string const &sn, ATarget const &target)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_spells[i] && _spells[i]->getName() == sn)
		{
			_spells[i]->launch(target);
			return ;
		}
	}
}


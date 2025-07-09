/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:17:59 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/09 17:36:05 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"
#include "ASpell.hpp"

SpellBook::SpellBook(void)
{
	for (int i = 0; i < 4; ++i)
		_book[i] = NULL;
}

SpellBook::~SpellBook()
{
	for (int i = 0; i < 4; ++i)
	{
		delete _book[i];
		_book[i] = NULL;
	}
}

void	SpellBook::learnSpell(ASpell *s)
{
	if (!s)
		return ;
	for (int i = 0; i < 4; ++i)
	{
		if (_book[i] && _book[i]->getName() == s->getName())
		{
			return ;
		}
		if (!_book[i])
		{
			_book[i] = s->clone();
			return ;
		}
	}
}

void	SpellBook::forgetSpell(std::string const &sn)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_book[i] && _book[i]->getName() == sn)
		{
			delete _book[i];
			_book[i] = NULL;
		}
	}
}

ASpell	*SpellBook::createSpell(std::string const &sn) const
{
	for (int i = 0; i < 4; ++i)
	{
		if (_book[i] && _book[i]->getName() == sn)
		{
			return (_book[i]->clone());
		}
	}
	return NULL;
}















/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:09:14 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/09 17:13:46 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title): _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
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
	_book.learnSpell(s);
}

void	Warlock::forgetSpell(std::string const &sn)
{
	_book.forgetSpell(sn);
}

void	Warlock::launchSpell(std::string const &sn, ATarget const &target)
{
	ASpell	*temp = _book.createSpell(sn);

	if (temp)
	{
		temp->launch(target);
		delete temp;
	}
}


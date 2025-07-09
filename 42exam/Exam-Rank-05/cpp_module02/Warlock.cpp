/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 21:03:39 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/08 17:49:40 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"

Warlock::Warlock(std::string const &n, std::string const &t): name(n), title(t)
{
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
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
	book.learnSpell(spell);
}

void	Warlock::forgetSpell(std::string const &sname)
{
	book.forgetSpell(sname);
}

void	Warlock::launchSpell(std::string const &sname, ATarget const &target)
{
	ASpell *temp = book.createSpell(sname);
	if (temp)
	{
		temp->launch(target);
		delete temp;
	}
}


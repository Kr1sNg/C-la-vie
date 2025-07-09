/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 21:55:31 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/07 23:11:25 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::~ASpell()
{
	
}
		
ASpell::ASpell(std::string n, std::string e): name(n), effects(e)
{
	
}

ASpell::ASpell(ASpell const &src)
{
	*this = src;
}

ASpell	&ASpell::operator=(ASpell const &rhs)
{
	if (this != &rhs)
	{
		name = rhs.name;
		effects = rhs.effects;
	}
	return (*this);
}

std::string	ASpell::getName(void) const
{
	return (name);
}

std::string	ASpell::getEffects(void) const
{
	return (effects);
}

void	ASpell::launch(ATarget const &target) const
{
	target.getHitBySpell(*this);
}

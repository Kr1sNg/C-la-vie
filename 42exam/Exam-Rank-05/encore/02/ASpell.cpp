/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:42:26 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/09 13:55:09 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell(std::string const &name, std::string const &effects):
				_name(name),
				_effects(effects)
{
}

ASpell::~ASpell()
{
}

std::string const	&ASpell::getName(void) const
{
	return (_name);
}

std::string const	&ASpell::getEffects(void) const
{
	return (_effects);
}

void	ASpell::launch(ATarget const &target) const
{
	target.getHitBySpell(*this);
}


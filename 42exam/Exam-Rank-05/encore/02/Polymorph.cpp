/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:03:44 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/09 16:05:41 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorph.hpp"

Polymorph::Polymorph(void): ASpell("Polymorph", "turned into a critter")
{
}

Polymorph::~Polymorph()
{
}

ASpell	*Polymorph::clone(void) const
{
	return (new Polymorph());
}



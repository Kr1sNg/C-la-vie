/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:37:39 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/08 13:39:38 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorph.hpp"

Polymorph::Polymorph(void): ASpell("Polymorph", "turned into a critter")
{
	return ;
}

Polymorph::~Polymorph()
{
	return ;
}
		
Polymorph	*Polymorph::clone(void) const
{
	return (new Polymorph());
}

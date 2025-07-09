/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:58:04 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/09 15:59:57 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fireball.hpp"

Fireball::Fireball(void): ASpell("Fireball", "burnt to a crisp")
{
}

Fireball::~Fireball()
{
}

ASpell	*Fireball::clone(void) const
{
	return (new Fireball());
}


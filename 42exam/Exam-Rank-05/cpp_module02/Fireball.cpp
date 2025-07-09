/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:13:39 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/08 12:17:01 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fireball.hpp"

Fireball::Fireball(void): ASpell("Fireball", "burnt to a crisp")
{
	return ;
}

Fireball::~Fireball()
{
	return ;
}

Fireball	*Fireball::clone(void) const
{
	return (new Fireball());
}

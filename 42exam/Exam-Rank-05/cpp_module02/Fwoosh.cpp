/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 22:41:18 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/08 12:15:39 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fwoosh.hpp"

Fwoosh::Fwoosh(void): ASpell("Fwoosh", "fwooshed")
{
	return ;
}

Fwoosh::~Fwoosh()
{
	return ;
}
		
Fwoosh	*Fwoosh::clone(void) const
{
	return (new Fwoosh());
}

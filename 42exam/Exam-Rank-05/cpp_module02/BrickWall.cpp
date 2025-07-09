/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:51:59 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/08 13:53:30 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BrickWall.hpp"

BrickWall::BrickWall(void): ATarget("Inconspicuous Red-brick Wall")
{
	return ;
}

BrickWall::~BrickWall()
{
	return ;
}

BrickWall	*BrickWall::clone(void) const
{
	return (new BrickWall());
}
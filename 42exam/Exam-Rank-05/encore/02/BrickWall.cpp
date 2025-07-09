/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:09:45 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/09 17:16:15 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BrickWall.hpp"

BrickWall::BrickWall(void): ATarget("Inconspicuous Red-brick Wall")
{
	std::cout << "BrickWall created!" << std::endl;
}

BrickWall::~BrickWall()
{
	std::cout << "BrickWall destroyed!" << std::endl;
}

ATarget	*BrickWall::clone(void) const
{
	return (new BrickWall());
}



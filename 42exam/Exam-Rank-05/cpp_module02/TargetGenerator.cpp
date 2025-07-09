/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:04:39 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/08 17:34:42 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(void)
{
	for (int i = 0; i < 4; ++i)
	{
		targets[i] = NULL;
	}
}

TargetGenerator::~TargetGenerator()
{
	for (int i = 0; i < 4; ++i)
	{
		delete targets[i];
		targets[i] = NULL;
	}
}

void	TargetGenerator::learnTargetType(ATarget *type)
{
	if (!type)
		return ;
	for (int i = 0; i < 4; ++i)
	{
		if (targets[i] && targets[i]->getType() == type->getType())
			return ;
		if (!targets[i])
		{
			targets[i] = type->clone();
			return ;
		}
	}
}

void	TargetGenerator::forgetTargetType(std::string const &target)
{
	for (int i = 0; i < 4; ++i)
	{
		if (targets[i] && targets[i]->getType() == target)
		{
			delete targets[i];
			targets[i] = NULL;
			return ;
		}
	}
}

ATarget	*TargetGenerator::createTarget(std::string const &target)
{
	for (int i = 0; i < 4; ++i)
	{
		if (targets[i] && targets[i]->getType() == target)
		{
			return (targets[i]->clone());
		}
	}
	return NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:41:33 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/09 18:00:49 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"
#include "ATarget.hpp"

TargetGenerator::TargetGenerator(void)
{
	for (int i = 0; i < 4; ++i)
		_list[i] = NULL;
}

TargetGenerator::~TargetGenerator()
{
	for (int i = 0; i < 4; ++i)
	{
		delete _list[i];
		_list[i] = NULL;
	}
}

void	TargetGenerator::learnTargetType(ATarget *t)
{
	if (!t)
		return ;
	for (int i = 0; i < 4; ++i)
	{
		if (_list[i] && _list[i]->getType() == t->getType())
		{
			return ;
		}
		if (!_list[i])
		{
			_list[i] = t->clone();
			return ;
		}
	}
}

void	TargetGenerator::forgetTargetType(std::string const &tn)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_list[i] && _list[i]->getType() == tn)
		{
			delete _list[i];
			_list[i] = NULL;
			return ;
		}
	}
}

ATarget	*TargetGenerator::createTarget(std::string const &tn)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_list[i] && _list[i]->getType() == tn)
		{
			return (_list[i]->clone());
		}
	}
	return NULL;
}




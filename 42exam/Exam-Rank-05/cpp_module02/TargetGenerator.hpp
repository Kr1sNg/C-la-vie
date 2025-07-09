/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:43:57 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/08 17:04:19 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TARGETGENERATOR_
# define _TARGETGENERATOR_

# include <string>
# include <iostream>
# include "ATarget.hpp"

class TargetGenerator
{
	private:
		TargetGenerator(TargetGenerator const &src);
		TargetGenerator	&operator=(TargetGenerator const &rhs);
		
		ATarget	*targets[4];
		
	public:
		TargetGenerator(void);
		~TargetGenerator();

		void	learnTargetType(ATarget *type);
		void	forgetTargetType(std::string const &target);
		ATarget	*createTarget(std::string const &target);
		
};

#endif
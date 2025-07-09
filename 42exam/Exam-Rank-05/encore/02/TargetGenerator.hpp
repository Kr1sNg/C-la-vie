/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:34:37 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/09 16:55:42 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TARGETG_
# define _TARGETG_

# include <string>

class ATarget;

class TargetGenerator
{
	private:
		ATarget	*_list[4];

		TargetGenerator(TargetGenerator const &src);
		TargetGenerator	&operator=(TargetGenerator const &rhs);

	public:
		TargetGenerator(void);
		~TargetGenerator();

		void	learnTargetType(ATarget *t);
		void	forgetTargetType(std::string const &tn);
		ATarget	*createTarget(std::string const &tn);

};

#endif

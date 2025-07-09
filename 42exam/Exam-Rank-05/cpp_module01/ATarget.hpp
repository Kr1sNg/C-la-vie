/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 21:58:03 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/07 22:29:36 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ATARGET_HPP_
# define _ATARGET_HPP_

# include <string>
# include <iostream>

class ASpell;

class ATarget
{
	protected:
		std::string	type;

		ATarget(void);
		ATarget(ATarget const &src);
		ATarget	&operator=(ATarget const &rhs);
		
	public:
		virtual ~ATarget();

		ATarget(std::string t);
		
		std::string	getType(void) const;

		virtual ATarget	*clone(void) const = 0;

		void	getHitBySpell(ASpell const &spell) const;
		
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:50:03 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/09 13:47:48 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ATARGET_
# define _ATARGET_

# include <string>
# include <iostream>

class ASpell;

class ATarget
{
	protected:
		std::string	_type;
		
		ATarget();
		ATarget(ATarget const &src);
		ATarget	&operator=(ATarget const &rhs);	

	public:
		ATarget(std::string const &type);
		virtual ~ATarget();

		std::string const	&getType(void) const;
		virtual ATarget		*clone(void) const = 0;
		void				getHitBySpell(ASpell const &spell) const;

};

#endif

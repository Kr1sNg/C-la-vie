/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 21:46:06 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/08 12:28:05 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ASPELL_HPP_
# define _ASPELL_HPP_

# include <string>
# include <iostream>

class ATarget;

class ASpell
{
	protected:
		std::string	name;
		std::string	effects;

		ASpell(void);
		ASpell(ASpell const &src);
		ASpell	&operator=(ASpell const &rhs);
	
	public:
		
		virtual ~ASpell();
		
		ASpell(std::string n, std::string e);

		std::string	getName(void) const;
		std::string	getEffects(void) const;

		virtual ASpell	*clone(void) const = 0;
		
		void	launch(ATarget const &target) const;
};


#endif
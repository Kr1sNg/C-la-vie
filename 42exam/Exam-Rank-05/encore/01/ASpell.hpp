/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:35:38 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/09 13:47:03 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ASPELL_
# define _ASPELL_

# include <string>
# include <iostream>

class ATarget;

class ASpell
{
	protected:
		std::string	_name;
		std::string _effects;

		ASpell(void);
		ASpell(ASpell const &src);
		ASpell	&operator=(ASpell const &rhs);
	public:
		ASpell(std::string const &name, std::string const &effects);
		virtual ~ASpell();

		std::string const	&getName(void) const;
		std::string const	&getEffects(void) const;
		virtual ASpell		*clone(void) const = 0;
		void				launch(ATarget const &target) const;

};

#endif

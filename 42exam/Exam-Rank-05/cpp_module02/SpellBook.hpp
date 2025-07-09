/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:55:43 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/08 14:44:22 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SPELLBOOK_
# define _SPELLBOOK_

# include <string>
# include <iostream>
# include "ASpell.hpp"

class SpellBook
{
	private:
		ASpell	*spells[8];
	
		SpellBook(SpellBook const &src);
		SpellBook	&operator=(SpellBook const &rhs);
	
	public:
		SpellBook(void);
		~SpellBook();

		void	learnSpell(ASpell *s);
		void	forgetSpell(std::string const &sname);
		ASpell	*createSpell(std::string const &sname);

};

#endif
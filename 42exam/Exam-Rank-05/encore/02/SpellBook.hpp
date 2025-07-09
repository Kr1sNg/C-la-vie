/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:12:49 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/09 17:29:26 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SPELLBOOK_
# define _SPELLBOOK_

# include <string>

class ASpell;

class SpellBook
{
	private:
		ASpell	*_book[4];

		SpellBook(SpellBook const &src);
		SpellBook	&operator=(SpellBook const &rhs);

	public:
		SpellBook(void);
		~SpellBook();

		void	learnSpell(ASpell *s);
		void	forgetSpell(std::string const &sn);
		ASpell	*createSpell(std::string const &sn) const;

};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 20:19:08 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/09 17:47:11 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	_WARLOCK_HPP_
# define _WARLOCK_HPP_

# include <string>
# include <iostream>

class ASpell;
class ATarget;

class Warlock
{
	private:
		std::string	name;
		std::string	title;
		ASpell	*spells[8];

		Warlock(void);
		Warlock(Warlock const &src);
		Warlock	operator=(Warlock const &rhs);
		
	public:
		
		~Warlock();
		
		Warlock(std::string const &n, std::string const &t);

		std::string const getName(void) const;
		std::string const getTitle(void) const;
		
		void	setTitle(std::string const &s);

		void	introduce(void) const;
		
		void	learnSpell(ASpell *spell);
		void	forgetSpell(std::string const &sname);
		void	launchSpell(std::string const &sname, ATarget const &target) const;
		
};


#endif
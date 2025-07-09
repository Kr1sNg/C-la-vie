/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:09:24 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/09 12:12:43 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WARLOCK_
# define _WARLOCK_

# include <string>
# include <iostream>

class Warlock
{
	private:
		std::string	_name;
		std::string	_title;
		
		Warlock();
		Warlock(Warlock const &src);
		Warlock	&operator=(Warlock const &rhs);

	public:
		Warlock(std::string const &name, std::string const &title);
		~Warlock();
		
		std::string const	&getName(void) const;
		std::string const	&getTitle(void) const;
		void				setTitle(std::string const &t);
		void				introduce(void) const;	
	
};


#endif

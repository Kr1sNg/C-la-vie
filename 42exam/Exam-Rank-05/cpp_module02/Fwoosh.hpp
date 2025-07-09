/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 22:30:16 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/08 09:23:22 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FWOOSH_
# define _FWOOSH_

# include "ASpell.hpp"

class Fwoosh: public ASpell
{
	private:
		Fwoosh(Fwoosh const &src);
		Fwoosh	&operator=(Fwoosh const &rhs);
	
	public:
		Fwoosh(void);
		~Fwoosh();
		
		Fwoosh	*clone(void) const;

};

#endif
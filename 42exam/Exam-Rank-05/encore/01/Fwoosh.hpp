/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:04:27 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/09 13:51:22 by tat-nguy         ###   ########.fr       */
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
		
		ASpell	*clone(void) const;

};

#endif

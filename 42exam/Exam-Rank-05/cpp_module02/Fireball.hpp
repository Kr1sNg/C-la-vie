/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:01:15 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/08 12:21:24 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIREBALL_
# define _FIREBALL_

# include "ASpell.hpp"

class Fireball: public ASpell
{
	private:
		Fireball(Fireball const &src);
		Fireball	&operator=(Fireball const &rhs);
	
	public:
		Fireball(void);
		~Fireball();

		Fireball	*clone(void) const;
	
};

#endif

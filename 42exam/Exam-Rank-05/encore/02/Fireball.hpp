/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:48:31 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/09 15:57:53 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIREBALL_
# define _FIREBALL_

#include "ASpell.hpp"

class Fireball: public ASpell
{
	private:
		Fireball(Fireball const &src);
		Fireball	&operator=(Fireball const &rhs);

	public:
		Fireball(void);
		~Fireball();

		ASpell	*clone(void) const;

};

#endif

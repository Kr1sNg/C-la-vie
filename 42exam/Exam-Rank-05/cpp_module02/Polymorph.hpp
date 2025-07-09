/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:22:51 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/08 12:29:16 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _POLYMORPH_
# define _POLYMORPH_

# include "ASpell.hpp"

class Polymorph: public ASpell
{
	private:
		Polymorph(Polymorph const &src);
		Polymorph	&operator=(Polymorph const &rhs);
		
	public:
		Polymorph(void);
		~Polymorph();
		
		Polymorph	*clone(void) const;
		
};

#endif
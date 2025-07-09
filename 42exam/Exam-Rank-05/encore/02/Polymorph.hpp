/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:00:19 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/09 16:54:39 by tat-nguy         ###   ########.fr       */
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

		ASpell	*clone(void) const;

};

#endif

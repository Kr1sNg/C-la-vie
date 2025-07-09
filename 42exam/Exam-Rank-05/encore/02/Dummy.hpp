/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:12:59 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/09 13:50:40 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DUMMY_
# define _DUMMY_

# include "ATarget.hpp"

class Dummy: public ATarget
{
	private:
		Dummy(Dummy const &src);
		Dummy	&operator=(Dummy const &rhs);		

	public:
		Dummy(void);
		~Dummy();

		ATarget	*clone(void) const;

};

#endif

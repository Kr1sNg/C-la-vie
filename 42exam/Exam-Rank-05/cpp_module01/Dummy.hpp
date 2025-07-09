/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 22:45:37 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/08 09:22:48 by tat-nguy         ###   ########.fr       */
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
		
		Dummy	*clone(void) const;
};

#endif
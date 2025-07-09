/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:40:19 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/08 13:51:47 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BRICKWALL_
# define _BRICKWALL_

# include "ATarget.hpp"

class BrickWall: public ATarget
{
	private:
		BrickWall(BrickWall const &src);
		BrickWall	&operator=(BrickWall const &rhs);

	public:
		BrickWall(void);
		~BrickWall();

		BrickWall	*clone(void) const;
		
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 09:48:55 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/09 17:44:49 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"
#include "Warlock.hpp"

int	main()
{
	Warlock	richard("Richard", "the Titled");
	
	Dummy	bob;
	// Fwoosh	*fwoosh = new Fwoosh();
	Fwoosh	sh;

	// richard.learnSpell(fwoosh);
	richard.learnSpell(&sh);
	
	richard.introduce();
	richard.launchSpell("Fwoosh", bob);
	
	richard.forgetSpell("Fwoosh");
	richard.launchSpell("Fwoosh", bob);

	// delete fwoosh;
	return (0);
}

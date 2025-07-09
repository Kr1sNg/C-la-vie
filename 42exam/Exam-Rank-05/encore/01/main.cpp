/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:08:35 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/09 17:58:24 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"
#include "Warlock.hpp"


int	main()
{
	std::cout << "------- Module 00 -------" << std::endl;
	
	Warlock const	richard1("Richard1", "Mistress of Magma");
	richard1.introduce();

	std::cout << richard1.getName() << " - " << richard1.getTitle() << std::endl;

	Warlock	*jack = new Warlock("Jack", "the Long");
	jack->introduce();
	jack->setTitle("the Mighty");
	jack->introduce();

	delete jack;

	std::cout << "------- Module 01 -------" << std::endl;
	
	Warlock	richard("Richard", "the Titled");

	Dummy	bob;
	Fwoosh	*fwoosh = new Fwoosh();

	richard.learnSpell(fwoosh);

	richard.introduce();
	richard.launchSpell("Fwoosh", bob);

	richard.forgetSpell("Fwoosh");
	richard.launchSpell("Fwoosh", bob);

	delete fwoosh; //add

	return (0);
}

	


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:08:35 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/07/09 18:03:26 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"
#include "ATarget.hpp"
#include "BrickWall.hpp"
#include "Dummy.hpp"
#include "Fireball.hpp"
#include "Fwoosh.hpp"
#include "Polymorph.hpp"
#include "SpellBook.hpp"
#include "TargetGenerator.hpp"
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
	
	Warlock	richard2("Richard2", "the Titled");

	Dummy	bob;
	Fwoosh	*fwoosh = new Fwoosh();

	richard2.learnSpell(fwoosh);

	richard2.introduce();
	richard2.launchSpell("Fwoosh", bob);

	richard2.forgetSpell("Fwoosh");
	richard2.launchSpell("Fwoosh", bob);
	
	delete fwoosh;

	std::cout << "------- Module 02 -------" << std::endl;

	Warlock	richard("Richard", "foo");
	richard.setTitle("Hello, I'm Richard the Warlock!");
	BrickWall	model1;

	Polymorph	*polymorph = new Polymorph();
	TargetGenerator	tarGen;

	tarGen.learnTargetType(&model1);
	richard.learnSpell(polymorph);

	Fireball	*fireball = new Fireball();

	richard.learnSpell(fireball);

	ATarget	*wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

	richard.introduce();
	richard.launchSpell("Polymorph", *wall);
	richard.launchSpell("Fireball", *wall);

	delete polymorph; 	//add
	delete fireball; 	//add
	delete wall;		//add
	
	return (0);
}

	


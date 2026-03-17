/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msall <msall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:36:51 by msall             #+#    #+#             */
/*   Updated: 2025/11/25 12:36:52 by msall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::executeAction() const
{
	std::cout << "* BZZZZZ BZZZZZ DRILL DRILL DRILL *" << std::endl;
	std::cout << "* WHIRRRR WHIRRRR SCREECH SCREECH *" << std::endl;
	
	// Utiliser time() pour avoir un seed différent à chaque exécution
	static bool seeded = false;
	if (!seeded) {
		std::srand(std::time(NULL));
		seeded = true;
	}
	
	if (std::rand() % 2 == 0) {
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "The robotomy of " << _target << " failed!" << std::endl;
	}
}

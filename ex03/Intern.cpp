/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msall <msall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:48:05 by msall             #+#    #+#             */
/*   Updated: 2025/12/03 22:29:30 by msall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	// Constructor par défaut
}

Intern::Intern(const Intern& other)
{
	(void)other;
	std::cout << "Intern copied" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destroyed" << std::endl;
}

AForm* Intern::createShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardon(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	FormType forms[] = {
		{"shrubbery creation", &createShrubbery},
		{"robotomy request", &createRobotomy},
		{"presidential pardon", &createPresidentialPardon}
	};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i].name == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return forms[i].creator(target);
		}
	}

	std::cerr << "Error: Form \"" << formName << "\" does not exist" << std::endl;
	throw FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return "Form not found";
}

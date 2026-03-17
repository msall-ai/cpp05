/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msall <msall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:37:02 by msall             #+#    #+#             */
/*   Updated: 2025/11/25 12:55:09 by msall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::executeAction() const
{
	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());
	
	if (!file.is_open()) {
		std::cerr << "Error: could not create file " << filename << std::endl;
		return;
	}

	file << "       ###" << std::endl;
	file << "      #o###" << std::endl;
	file << "    #####o###" << std::endl;
	file << "   #o#\\#|#/###" << std::endl;
	file << "    ###\\|/#o#" << std::endl;
	file << "     # }|{  #" << std::endl;
	file << "       }|{" << std::endl;
	file << std::endl;
	file << "      @@@@@" << std::endl;
	file << "     @@@@@@@@" << std::endl;
	file << "    @@@@@@@@@@@" << std::endl;
	file << "   @@@@@@@@@@@@@@" << std::endl;
	file << "  @@@@@@@@@@@@@@@@@" << std::endl;
	file << "        |||" << std::endl;
	file << "        |||" << std::endl;

	file.close();
	std::cout << "Created shrubbery file: " << filename << std::endl;
}

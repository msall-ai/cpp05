/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msall <msall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:48:00 by msall             #+#    #+#             */
/*   Updated: 2025/11/25 12:55:13 by msall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	AForm* makeForm(const std::string& formName, const std::string& target);

	class FormNotFoundException : public std::exception {
	public:
		const char* what() const throw();
	};

private:
	struct FormType {
		std::string name;
		AForm* (*creator)(const std::string& target);
	};

	static AForm* createShrubbery(const std::string& target);
	static AForm* createRobotomy(const std::string& target);
	static AForm* createPresidentialPardon(const std::string& target);
};

#endif

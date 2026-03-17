/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msall <msall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:36:23 by msall             #+#    #+#             */
/*   Updated: 2025/11/25 12:36:24 by msall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Forme Canonique Orthodoxe
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		// Note: _name est const, donc on ne peut pas l'assigner
		// On peut seulement copier le grade
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
}

// Accesseurs
const std::string& Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

// Modification du grade
void Bureaucrat::incrementGrade() {
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade() {
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

// Implémentation des exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

// Surcharge de l'opérateur d'insertion
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}

void Bureaucrat::signForm(AForm& f)
{
	try {
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << _name << " couldn't sign " << f.getName()
				  << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << _name << " couldn't execute " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

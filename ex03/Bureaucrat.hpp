/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msall <msall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:36:31 by msall             #+#    #+#             */
/*   Updated: 2025/11/25 12:36:32 by msall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class AForm;

class Bureaucrat {
private:
	const std::string	_name;
	int					_grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	// Accesseurs
	const std::string&	getName() const;
	int					getGrade() const;

	// Modification du grade
	void	incrementGrade();
	void	decrementGrade();

	// Méthodes pour les formulaires
	void	signForm(AForm& f);
	void	executeForm(AForm const & form) const;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

// Surcharge de l'opérateur d'insertion
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif

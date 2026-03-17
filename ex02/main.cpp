/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msall <msall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:36:35 by msall             #+#    #+#             */
/*   Updated: 2025/11/25 12:55:12 by msall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void testShrubbery()
{
	std::cout << "\n========== TEST SHRUBBERY CREATION FORM ==========" << std::endl;
	
	try {
		Bureaucrat bob("Bob", 140);
		ShrubberyCreationForm form("home");
		
		std::cout << bob << std::endl;
		std::cout << form << std::endl;
		
		// Tentative d'exécution sans signature (devrait échouer)
		std::cout << "\n--- Tentative d'exécution sans signature ---" << std::endl;
		bob.executeForm(form);
		
		// Signature du formulaire
		std::cout << "\n--- Signature du formulaire ---" << std::endl;
		bob.signForm(form);
		
		// Tentative d'exécution avec grade insuffisant (devrait échouer)
		std::cout << "\n--- Tentative d'exécution avec grade 140 (requis: 137) ---" << std::endl;
		bob.executeForm(form);
		
		// Amélioration du grade et exécution réussie
		std::cout << "\n--- Amélioration du grade et exécution ---" << std::endl;
		bob.incrementGrade();
		bob.incrementGrade();
		bob.incrementGrade();
		std::cout << bob << std::endl;
		bob.executeForm(form);
		
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

void testRobotomy()
{
	std::cout << "\n========== TEST ROBOTOMY REQUEST FORM ==========" << std::endl;
	
	try {
		Bureaucrat alice("Alice", 40);
		RobotomyRequestForm form("Bender");
		
		std::cout << alice << std::endl;
		std::cout << form << std::endl;
		
		// Signature et exécution
		std::cout << "\n--- Signature et exécution ---" << std::endl;
		alice.signForm(form);
		alice.executeForm(form);
		
		// Deuxième tentative pour voir le caractère aléatoire
		std::cout << "\n--- Deuxième tentative ---" << std::endl;
		alice.executeForm(form);
		
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

void testPresidentialPardon()
{
	std::cout << "\n========== TEST PRESIDENTIAL PARDON FORM ==========" << std::endl;
	
	try {
		Bureaucrat president("President", 1);
		Bureaucrat intern("Intern", 150);
		PresidentialPardonForm form("Arthur Dent");
		
		std::cout << president << std::endl;
		std::cout << intern << std::endl;
		std::cout << form << std::endl;
		
		// Tentative de signature par l'intern (devrait échouer)
		std::cout << "\n--- Tentative de signature par Intern (grade 150, requis: 25) ---" << std::endl;
		intern.signForm(form);
		
		// Signature par le président
		std::cout << "\n--- Signature par President ---" << std::endl;
		president.signForm(form);
		
		// Tentative d'exécution par l'intern (devrait échouer)
		std::cout << "\n--- Tentative d'exécution par Intern (grade 150, requis: 5) ---" << std::endl;
		intern.executeForm(form);
		
		// Exécution par le président
		std::cout << "\n--- Exécution par President ---" << std::endl;
		president.executeForm(form);
		
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

void testAllForms()
{
	std::cout << "\n========== TEST TOUS LES FORMULAIRES ==========" << std::endl;
	
	try {
		Bureaucrat boss("Boss", 1);
		
		ShrubberyCreationForm shrub("garden");
		RobotomyRequestForm robot("Target");
		PresidentialPardonForm pardon("Criminal");
		
		std::cout << boss << std::endl;
		
		// Signature de tous les formulaires
		std::cout << "\n--- Signature de tous les formulaires ---" << std::endl;
		boss.signForm(shrub);
		boss.signForm(robot);
		boss.signForm(pardon);
		
		// Exécution de tous les formulaires
		std::cout << "\n--- Exécution de tous les formulaires ---" << std::endl;
		boss.executeForm(shrub);
		boss.executeForm(robot);
		boss.executeForm(pardon);
		
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

int main()
{
	testShrubbery();
	testRobotomy();
	testPresidentialPardon();
	testAllForms();
	
	std::cout << "\n========== FIN DES TESTS ==========" << std::endl;
	
	return 0;
}

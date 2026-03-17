/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msall <msall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:36:35 by msall             #+#    #+#             */
/*   Updated: 2025/11/25 12:55:15 by msall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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

void testInternBasic()
{
	std::cout << "\n========== TEST INTERN BASIQUE ==========" << std::endl;
	
	try {
		Intern someRandomIntern;
		AForm* rrf;
		
		std::cout << "\n--- Création de robotomy request ---" << std::endl;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		
		if (rrf) {
			std::cout << *rrf << std::endl;
			delete rrf;
		}
		
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

void testInternAllForms()
{
	std::cout << "\n========== TEST INTERN - TOUS LES FORMULAIRES ==========" << std::endl;
	
	try {
		Intern intern;
		Bureaucrat boss("Boss", 1);
		
		std::cout << "\n--- Création des trois types de formulaires ---" << std::endl;
		AForm* shrub = intern.makeForm("shrubbery creation", "home");
		AForm* robot = intern.makeForm("robotomy request", "Target");
		AForm* pardon = intern.makeForm("presidential pardon", "Criminal");
		
		std::cout << "\n--- Signature et exécution ---" << std::endl;
		if (shrub) {
			boss.signForm(*shrub);
			boss.executeForm(*shrub);
			delete shrub;
		}
		
		if (robot) {
			boss.signForm(*robot);
			boss.executeForm(*robot);
			delete robot;
		}
		
		if (pardon) {
			boss.signForm(*pardon);
			boss.executeForm(*pardon);
			delete pardon;
		}
		
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

void testInternInvalidForm()
{
	std::cout << "\n========== TEST INTERN - FORMULAIRE INVALIDE ==========" << std::endl;
	
	try {
		Intern intern;
		AForm* form;
		
		std::cout << "\n--- Tentative de création d'un formulaire inexistant ---" << std::endl;
		form = intern.makeForm("invalid form", "target");
		
		// Cette ligne ne devrait pas être atteinte
		if (form) {
			delete form;
		}
		
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

void testInternWithBureaucrat()
{
	std::cout << "\n========== TEST INTERN AVEC BUREAUCRATE ==========" << std::endl;
	
	try {
		Intern intern;
		Bureaucrat lowLevel("LowLevel", 140);
		Bureaucrat highLevel("HighLevel", 1);
		
		std::cout << "\n--- Création d'un shrubbery form ---" << std::endl;
		AForm* form = intern.makeForm("shrubbery creation", "office");
		
		if (form) {
			std::cout << *form << std::endl;
			
			std::cout << "\n--- Tentative de signature par bureaucrate bas niveau ---" << std::endl;
			lowLevel.signForm(*form);
			
			std::cout << "\n--- Signature et exécution par bureaucrate haut niveau ---" << std::endl;
			highLevel.signForm(*form);
			highLevel.executeForm(*form);
			
			delete form;
		}
		
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

int main()
{
	testInternBasic();
	testInternAllForms();
	testInternInvalidForm();
	testInternWithBureaucrat();
	
	std::cout << "\n========== FIN DES TESTS ==========" << std::endl;
	
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msall <msall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:06:26 by msall             #+#    #+#             */
/*   Updated: 2025/12/03 21:18:37 by msall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	std::cout << "=== Test 1: Valid Bureaucrats ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 1);
		std::cout << bob << std::endl;
		
		Bureaucrat alice("Alice", 150);
		std::cout << alice << std::endl;
		
		Bureaucrat charlie("Charlie", 75);
		std::cout << charlie << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Grade Too High Exception ===" << std::endl;
	try {
		Bureaucrat invalid("Invalid", 0);
		std::cout << invalid << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Grade Too Low Exception ===" << std::endl;
	try {
		Bureaucrat invalid("Invalid", 151);
		std::cout << invalid << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Increment Grade ===" << std::endl;
	try {
		Bureaucrat john("John", 2);
		std::cout << john << std::endl;
		john.incrementGrade();
		std::cout << john << " (after increment)" << std::endl;
		john.incrementGrade(); // This should throw
		std::cout << john << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Decrement Grade ===" << std::endl;
	try {
		Bureaucrat jane("Jane", 149);
		std::cout << jane << std::endl;
		jane.decrementGrade();
		std::cout << jane << " (after decrement)" << std::endl;
		jane.decrementGrade(); // This should throw
		std::cout << jane << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: Copy Constructor ===" << std::endl;
	try {
		Bureaucrat original("Original", 42);
		Bureaucrat copy(original);
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy: " << copy << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}

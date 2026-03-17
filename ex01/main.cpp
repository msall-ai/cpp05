/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msall <msall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:06:58 by msall             #+#    #+#             */
/*   Updated: 2025/11/25 12:29:21 by msall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try {
        Bureaucrat bob("Bob", 10);
        Form f("Contract", 40, 30);

        bob.signForm(f);        // should fail - grade 50 too low
        bob.incrementGrade();   // grade 50 → 49
        bob.incrementGrade();   // grade 49 → 48
        // keep incrementing until Bob can sign (needs grade 40 or better)
        
    } catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

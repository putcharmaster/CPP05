/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 22:46:02 by sanhwang          #+#    #+#             */
/*   Updated: 2025/05/17 22:57:23 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
    try {
        Bureaucrat high("Alice", 1);
        Bureaucrat low("Bob", 150);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robo("Bender");
        PresidentialPardonForm pardon("Ford");

        high.signForm(shrub);
        high.signForm(robo);
        high.signForm(pardon);

        high.executeForm(shrub);
        high.executeForm(robo);
        high.executeForm(pardon);

        std::cout << "\nTrying with low-level bureaucrat:\n";
        low.signForm(shrub); // this will fail
        low.executeForm(shrub); // this will fail
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
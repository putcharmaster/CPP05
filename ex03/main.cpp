/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 22:46:02 by sanhwang          #+#    #+#             */
/*   Updated: 2025/05/21 00:02:07 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp" 

int main() {
    Intern randomIntern;
    Bureaucrat boss("final boss", 1);

    AForm *form1 = randomIntern.makeForm("robotomy request", "Bender");
    AForm *form2 = randomIntern.makeForm("shrubbery creation", "home");
    AForm *form3 = randomIntern.makeForm("presidential pardon", "Arthur Dent");
    AForm *form4 = randomIntern.makeForm("nonsense form", "Nobody");

    std::cout << std::endl;

    if (form1) {
        boss.signForm(*form1);
        boss.executeForm(*form1);
        delete form1;
    }

    if (form2) {
        boss.signForm(*form2);
        boss.executeForm(*form2);
        delete form2;
    }

    if (form3) {
        boss.signForm(*form3);
        boss.executeForm(*form3);
        delete form3;
    }

    if (!form4)
        std::cout << "Form creation failed as expected. \n";
/*
    std::string names[4] = {
        "robotomy request",
        "shrubbery creation",
        "presidential pardon",
        "nonsense form"
    };

    std::string targets[4] = {
        "Bender",
        "home",
        "Arthur Dent",
        "Nobody"
    };

    AForm* forms[4];

    for (int i = 0; i < 4; ++i)
        forms[i] = someRandomIntern.makeForm(names[i], targets[i]);

    for (int i = 0; i < 4; ++i) {
        if (forms[i]) {
            boss.signForm(*forms[i]);
            boss.executeForm(*forms[i]);
            delete forms[i];
        }
    }
*/
    return 0;
}
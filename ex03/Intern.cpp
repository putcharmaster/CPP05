/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 22:40:05 by sanhwang          #+#    #+#             */
/*   Updated: 2025/05/20 23:24:13 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp" 
#include <iostream>

static AForm *createShrubbery(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

static AForm *createRobotomy(const std::string &target) {
    return new RobotomyRequestForm(target);
}

static AForm *createPardon(const std::string &target) {
    return new PresidentialPardonForm(target);
}

Intern::Intern(){}
Intern::Intern(const Intern &other){
    (void)other;
}
Intern &Intern::operator=(const Intern &other){ 
    (void)other;
    return *this; 
}
Intern::~Intern(){}

AForm *Intern::makeForm(const std::string &formName, const std::string &target){
    std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm *(*constructors[3])(const std::string&) = {
        &createShrubbery,
        &createRobotomy,
        &createPardon
    };

    for (int i = 0; i < 3; ++i){
        if (formName == names[i]){
            std::cout << "Intern creates " << formName << std::endl;
            return constructors[i](target);
        }
    }

    std::cerr << "Intern couldn't find the form \"" << formName << "\"" << std::endl;
    return NULL;

}
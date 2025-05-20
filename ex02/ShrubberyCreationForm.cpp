/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:58:55 by sanhwang          #+#    #+#             */
/*   Updated: 2025/05/20 23:35:07 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) 
    : AForm("ShrubberyCreationForm", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    (void)other;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void    ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
    if(!isSigned())
        throw FormNotSignedException();
    if(executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::ofstream file((getTarget() + "_shrubbery").c_str());
    //this one line is same as folling two lines of code
    //std::string filename = getTarget() + "_shrubbery";
    //std::ofstream file(filename.c_str());
    if(file.is_open()) {
        file << "     *\n";
        file << "    ***\n";
        file << "   *****\n";
        file << "  *******\n";
        file << " *********\n";
        file << "     ||\n";
        file.close();
    }
}
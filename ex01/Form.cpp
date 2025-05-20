/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:10:24 by sanhwang          #+#    #+#             */
/*   Updated: 2025/04/25 22:30:05 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
        if (gradeToSign < 1 || gradeToExecute < 1)
            throw GradeTooHighException();
        if (gradeToSign > 150 || gradeToExecute > 150)
            throw GradeTooLowException();
    }

Form::Form(const Form &other)
    : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign),
    gradeToExecute(other.gradeToExecute) {}

Form &Form::operator=(const Form &other){
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

Form::~Form() {}

const std::string &Form::getName() const { return name; }
bool Form::getIsSigned() const { return isSigned; }
int Form::getGradeToSign() const { return gradeToSign; }
int Form::getGradeToExecute() const { return gradeToExecute; }

void Form::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Form: Grade too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Form: Grade too low!";
}

std::ostream &operator<<(std::ostream &out, const Form &f){
    out << "Form \"" << f.getName() << "\", signed: " << std::boolalpha << f.getIsSigned()
    << ", grade to sign: " << f.getGradeToSign()
    << ", grade to execute: " << f.getGradeToExecute();
    return out;
}

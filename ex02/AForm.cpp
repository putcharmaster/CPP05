/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:43:32 by sanhwang          #+#    #+#             */
/*   Updated: 2025/05/16 12:36:35 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute, const std::string &target)
    : name(name), signedStatus(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), target(target) {
        if (gradeToSign < 1 || gradeToExecute < 1)
            throw GradeTooHighException();
        if (gradeToSign > 150 || gradeToExecute > 150)
            throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : name(other.name), signedStatus(other.signedStatus),
    gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute), target(other.target) {}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other)
        signedStatus = other.signedStatus;
    return *this;
}

const std::string &AForm::getName() const {
    return name;
}

bool AForm::isSigned() const {
    return signedStatus;
}

int AForm::getGradeToSign() const {
    return gradeToSign;
}

int AForm::getGradeToExecute() const {
    return gradeToExecute;
}

const std::string &AForm::getTarget() const {
    return target;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign)
        throw GradeTooLowException();
    signedStatus = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "Form not signed";
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
    out << form.getName() << " form, signed: " << (form.isSigned() ? "yes" : "no")
        << ", grade to sign: " << form.getGradeToSign()
        << ", grade to execute: " << form.getGradeToExecute();
    return out;
}


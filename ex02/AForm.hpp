/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 22:29:27 by sanhwang          #+#    #+#             */
/*   Updated: 2025/05/16 11:43:19 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <stdexcept>
#include <iostream>

class Bureaucrat;

class AForm {
    private:
        const std::string name;
        bool signedStatus;
        const int gradeToSign;
        const int gradeToExecute;
        const std::string target;

    public:
        AForm(const std::string &name, int gradeToSign, int gradeToExecute, const std::string &target);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();

        const std::string &getName() const;
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        const std::string &getTarget() const;

        void beSigned(const Bureaucrat &bureatcrat);
        virtual void execute(const Bureaucrat &executor) const = 0;

        class GradeTooHighException : public std::exception {
            public:
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw();
        };

        class FormNotSignedException : public std::exception {
            public:
                const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
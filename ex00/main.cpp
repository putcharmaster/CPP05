/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 02:21:47 by sanhwang          #+#    #+#             */
/*   Updated: 2025/04/07 18:31:56 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(){
    try{
        Bureaucrat a("Alice", 2);
        std::cout << a << std::endl;
        a.incrementGrade();
        std::cout << a << std::endl;
        a.incrementGrade();
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b("Bob", 151);
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() <<std::endl;
    }

    try {
        Bureaucrat c("Sam", 149);
        std::cout << c << std::endl;
        c.decrementGrade();
        std::cout << c << std::endl;
        c.decrementGrade();
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
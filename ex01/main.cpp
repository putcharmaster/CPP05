/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:33:49 by sanhwang          #+#    #+#             */
/*   Updated: 2025/04/26 10:07:31 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
    try{
        Bureaucrat bob("Bob", 5);
        Bureaucrat jim("Jim", 120);

        Form topSecret("Top Secret", 10, 50);
        Form casual("Casual Form", 130, 140);

        std::cout << topSecret << std::endl;
        std::cout << casual << std::endl;

        bob.signForm(topSecret);   // should succeed
        jim.signForm(topSecret);   // should fail
        jim.signForm(casual);      // should succeed

        std::cout << topSecret << std::endl;
        std::cout << casual << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
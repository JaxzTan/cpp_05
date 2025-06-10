/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 09:31:54 by chtan             #+#    #+#             */
/*   Updated: 2025/06/10 11:15:57 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern &other) {
    (void)other; // Avoid unused parameter warning
}

Intern &Intern::operator=(const Intern &other) {
    if (this != &other) {
        // Copy assignment logic if needed
    }
    return *this;
}

Intern::~Intern()
{}

AForm *Intern::makeForm(const std::string form_name, const std::string form_target)
{
	int i = 0;
	std::string available_forms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	while (i < 3 && form_name != available_forms[i])
		i++;
	
	switch (i)
	{
		case 0:
			std::cout << "Intern creates " << form_name << std::endl;
			return (new ShrubberyCreationForm(form_target));
		case 1:
			std::cout << "Intern creates " << form_name << std::endl;
			return (new RobotomyRequestForm(form_target));
		case 2:
			std::cout << "Intern creates " << form_name << std::endl;
			return (new PresidentialPardonForm (form_target));
		default:
			std::cout << "Form is not existing" << std::endl;
			return NULL;
	}
}

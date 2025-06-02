/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:23:41 by chtan             #+#    #+#             */
/*   Updated: 2025/06/02 11:26:43 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern &other)
{
    (void) other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void) other;
    return (*this);
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
        return (new PresidentialPardonForm(form_target));
    default:
        throw std::invalid_argument("Invalid form name: " + form_name);
    }
}

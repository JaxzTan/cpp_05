/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:10:00 by chtan             #+#    #+#             */
/*   Updated: 2025/06/02 10:10:59 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5), _target("default")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) 
    : AForm("Presidential Pardon Form", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) 
    : AForm(other), _target(other._target)
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void PresidentialPardonForm::performAction() const {
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &form) {
    os << "Presidential Pardon Form: " << form.getName() 
       << ", Signed: " << (form.getIsSigned() ? "Yes" : "No") 
       << ", Sign Grade: " << form.getSignGrade() 
       << ", Execute Grade: " << form.getExecuteGrade();
    return os;
}

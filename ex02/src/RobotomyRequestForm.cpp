/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:11:14 by chtan             #+#    #+#             */
/*   Updated: 2025/06/02 10:12:00 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("Robotomy Request Form", 72, 45), _target("default") 
{
    srand(time(NULL)); // Seed the random number generator
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) 
    : AForm("Robotomy Request Form", 72, 45), _target(target) 
{
    srand(time(NULL)); // Seed the random number generator
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) 
    : AForm(other), _target(other._target) 
{
    srand(time(NULL)); // Seed the random number generator
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() 
{}

void RobotomyRequestForm::performAction() const {
    std::cout << "Drilling noises..." << std::endl;
    if (rand() % 2) { // 50% chance of success
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    } else {
        throw RobotizationFailed();
    }
}

const char *RobotomyRequestForm::RobotizationFailed::what() const throw() {
    return "Robotization failed!";
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:12:06 by chtan             #+#    #+#             */
/*   Updated: 2025/06/11 14:53:10 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("Shrubbery Creation Form", 145, 137), _target("default") 
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) 
    : AForm("Shrubbery Creation Form", 145, 137), _target(target) 
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) 
    : AForm(other), _target(other._target) 
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() 
{}

void ShrubberyCreationForm::performAction() const {
    std::ofstream ofs((_target + "_shrubbery").c_str());
    if (!ofs.is_open()) {
        throw OpenFileExeption();
    }
    ofs << "         _-_\n"
        << "      /~~   ~~\\\n"
        << "   /~~         ~~\\\n"
        << "  {               }\n"
        << "   \\  _-     -_  /\n"
        << "     ~   ~   ~\n"
        << "         _-_\n"
        << "         _-_\n"
        << "         _-_\n"
        << "         _-_\n"
        << "        _ - _\n"
        << "       _     _\n"
        << "      `````````\n";

    ofs.close();
}

const char *ShrubberyCreationForm::OpenFileExeption::what() const throw() {
    return "Failed to open file for writing.";
}


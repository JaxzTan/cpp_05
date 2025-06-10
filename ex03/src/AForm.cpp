/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:05:17 by chtan             #+#    #+#             */
/*   Updated: 2025/06/02 10:08:01 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

AForm::AForm() : _name("Default"), _is_signed(false), _sign_grade(150), _execute_grade(150)
{}

AForm::AForm(const std::string name, const int sign_grade, const int execute_grade)
    : _name(name), _is_signed(false), _sign_grade(sign_grade), _execute_grade(execute_grade) {
    if (sign_grade < 1 || execute_grade < 1)
        throw GradeTooHighException();
    if (sign_grade > 150 || execute_grade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : _name(other._name), _is_signed(other._is_signed), _sign_grade(other._sign_grade), _execute_grade(other._execute_grade)
{}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        _is_signed = other._is_signed;
        // _name, _sign_grade, and _execute_grade are const, so they cannot be assigned
    }
    return *this;
}

AForm::~AForm()
{}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _sign_grade)
        throw GradeTooLowException();
    _is_signed = true;
}

std::string AForm::getName() const {
    return _name;
}

bool AForm::getIsSigned() const {
    return _is_signed;
}

int AForm::getSignGrade() const {
    return _sign_grade;
}

int AForm::getExecuteGrade() const {
    return _execute_grade;
}

void AForm::setIsSigned(bool is_signed) {
    _is_signed = is_signed;
}

void AForm::execute(const Bureaucrat &executor) const {
    if (!_is_signed)
        throw IsNotSignedException();
    if (executor.getGrade() > _execute_grade)
        throw GradeTooLowException();
    performAction();
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char *AForm::IsNotSignedException::what() const throw() {
    return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
    os << "AForm: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << ", Sign Grade: " << form.getSignGrade() << ", Execute Grade: " << form.getExecuteGrade();
    return os;
}

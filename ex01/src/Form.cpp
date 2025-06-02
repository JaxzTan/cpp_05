/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:05:43 by chtan             #+#    #+#             */
/*   Updated: 2025/06/02 16:01:10 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

Form::Form() : _name("Default"), _is_signed(false), _sign_grade(150), _execute_grade(150)
{}

Form::Form(const std::string name, const int sign_grade, const int execute_grade) : _name(name), _is_signed(false), _sign_grade(sign_grade), _execute_grade(execute_grade)
{
    if (sign_grade < 1 || execute_grade < 1)
        throw GradeTooHighException();
    if (sign_grade > 150 || execute_grade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _is_signed(other._is_signed), _sign_grade(other._sign_grade), _execute_grade(other._execute_grade)
{}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        _is_signed = other._is_signed;
    }
    return (*this);
}

Form::~Form()
{}

// Member function
void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->_sign_grade)
        this->_is_signed = true;
    else
        throw GradeTooLowException();
}

std::string Form::getName() const
{
    return (this->_name);
}

bool Form::getIsSigned() const
{
    return (this->_is_signed);
}

int Form::getSignGrade() const
{
    return (_sign_grade);
}

int Form::getExecuteGrade() const
{
    return (this->_execute_grade);
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &os, Form const &form)
{
    os << "Form Name: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No") << ", Sign Grade: " << form.getSignGrade() << ", Execute Grade: " << form.getExecuteGrade();
    return os;
}

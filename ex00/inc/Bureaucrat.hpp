/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:13:33 by chtan             #+#    #+#             */
/*   Updated: 2025/05/31 11:13:33 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#define Yellow "\033[33m"
#define Reset "\033[0m"

class Bureaucrat {
    private:
        const std::string   _name;
        int                 _grade;

    public:
        // Constructors and destructors
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& tocopy);
        Bureaucrat& operator=(const Bureaucrat& other);
    
        // Member functions
        void         incrementGrade(void);
        void         decrementGrade(void);

        // Getters
        std::string getName() const;
        int         getGrade() const;
        
        // Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:

				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream & os, Bureaucrat const &other);

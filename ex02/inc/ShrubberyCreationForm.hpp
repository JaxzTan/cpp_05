/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:04:19 by chtan             #+#    #+#             */
/*   Updated: 2025/06/02 10:04:33 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
		virtual void	performAction() const;
	
	public:
	// Constructors
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();

		// exceptions
		class OpenFileExeption : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

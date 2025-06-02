/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:23:44 by chtan             #+#    #+#             */
/*   Updated: 2025/06/02 11:24:06 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

class AForm;

class Intern
{
	private:

	public:
		// Constructors
		Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();

		// Member functions
		AForm	*makeForm(const std::string form_name, const std::string form_target) ;
};

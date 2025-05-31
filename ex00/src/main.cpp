/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:13:47 by chtan             #+#    #+#             */
/*   Updated: 2025/05/31 11:15:38 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

// int main(void)
// {
//     try {
//     Bureaucrat bob("Bob", 2);
//     bob.incrementGrade(); // Now grade = 1 (highest possible)
//     bob.incrementGrade(); // Throws GradeTooHighException!
//     }
//     catch (std::exception &e) 
//     {
//         std::cerr << e.what() << std::endl;
//     }
// }

int main(void)
{
	std::cout << Yellow << "Test ex00" << Reset << std::endl;
	std::cout << Yellow << std::endl << "Test too high and too low creation" << Reset << std::endl;
	try
	{
		Bureaucrat Sleeper1("Bernd", 1500);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat Sleeper2("Olaf", -10);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << Yellow << std::endl << "Test increasing" << Reset << std::endl;
	Bureaucrat bob("Bob", 2);
	std::cout << bob << std::endl;
	try
	{
		bob.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << bob << std::endl;
	
	try
	{
		bob.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << bob << std::endl;


	std::cout << Yellow << std::endl << "Test decreasing" << Reset << std::endl;
	Bureaucrat tim("Tim", 149);
	std::cout << tim << std::endl;
	try
	{
		tim.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << tim << std::endl;
	
	try
	{
		tim.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << tim << std::endl;
	
	return (0);
}

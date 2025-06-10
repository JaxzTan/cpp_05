/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:13:47 by chtan             #+#    #+#             */
/*   Updated: 2025/06/10 16:42:47 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"


int main(void)
{
	std::cout << YELLOW << std::endl << "Test ex00" << RESET << std::endl;

	std::cout << YELLOW << "Test too high and too low creation" << RESET << std::endl;
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

	std::cout << YELLOW << std::endl << "Test increasing" << RESET << std::endl;
	Bureaucrat bob("Bob", 2);
	std::cout << bob;
	try
	{
		bob.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << bob;
	
	try
	{
	bob.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << bob;

	std::cout << YELLOW << std::endl << "Test decreasing" << RESET << std::endl;
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

	std::cout << YELLOW << std::endl << "Test ex01" << RESET << std::endl;
	Form id_form("ID FORM", 100, 90);
	Bureaucrat mr_slow;
	Bureaucrat mr_id("MR_ID", 100);
	std::cout << id_form;
	
	mr_slow.signForm(id_form);
	std::cout << id_form;

	mr_id.signForm(id_form);
	std::cout << id_form;
	
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:13:47 by chtan             #+#    #+#             */
/*   Updated: 2025/05/24 13:51:11 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main(void)
{
    try {
    Bureaucrat bob("Bob", 2);
    bob.incrementGrade(); // Now grade = 1 (highest possible)
    bob.incrementGrade(); // Throws GradeTooHighException!
    }
    catch (std::exception &e) 
    {
    std::cerr << e.what() << std::endl;
    }
}

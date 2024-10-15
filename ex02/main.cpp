#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main ()
{
	
	Bureaucrat john ("John", 150);
	Bureaucrat alice ("Alice", 50);
	Bureaucrat bob ("Bob", 20);

	
	ShrubberyCreationForm shrubbery ("shrubbery");
	std::cout<< shrubbery << " is created" << std::endl;
	RobotomyRequestForm robotomy ("robotomy");
	std::cout<< robotomy << " is created" << std::endl;
	PresidentialPardonForm pardon ("pardon");
	std::cout<< pardon << " is created" << std::endl;

		
	try
	{
		john.signForm (shrubbery);
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what () << std::endl;
	}

	try
	{
		alice.signForm (robotomy);
		alice.signForm (pardon);
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what () << std::endl;
	}

	
	try
	{
		bob.executeForm (shrubbery);
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what () << std::endl;
	}

	try
	{
		bob.signForm (shrubbery);
		bob.executeForm (shrubbery);
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what () << std::endl;
	}

	try
	{
		bob.executeForm (robotomy);
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what () << std::endl;
	}

	try
	{
		alice.executeForm (pardon);
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what () << std::endl;
	}

	
	try
	{
		bob.executeForm (robotomy);
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what () << std::endl;
	}

	return 0;
}

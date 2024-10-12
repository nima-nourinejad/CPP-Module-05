#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main ()
{
	// Create bureaucrats with various grades
	Bureaucrat john ("John", 150);	// low grade
	Bureaucrat alice ("Alice", 50); // medium grade
	Bureaucrat bob ("Bob", 20);	// high grade

	// Create forms
	ShrubberyCreationForm shrubbery ("home");
	RobotomyRequestForm robotomy ("Bob");
	PresidentialPardonForm pardon ("Alice");

	// Try signing the forms
	try
	{
		john.signForm (shrubbery); // Should fail
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what () << std::endl;
	}

	try
	{
		alice.signForm (robotomy); // Should succeed
		alice.signForm (pardon);   // Should succeed
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what () << std::endl;
	}

	// Try executing the forms
	try
	{
		bob.executeForm (shrubbery); // Should fail (not signed)
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what () << std::endl;
	}

	try
	{
		bob.signForm (shrubbery); // Should succeed
		bob.executeForm (shrubbery);
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what () << std::endl;
	}

	try
	{
		bob.executeForm (robotomy); // Should succeed
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what () << std::endl;
	}

	try
	{
		alice.executeForm (pardon); // Should succeed
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what () << std::endl;
	}

	// Check the outcome of RobotomyRequestForm execution
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

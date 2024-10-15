#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main ()
{
	Intern intern;

	{
		AForm * form = intern.makeForm ("shrubbery creation", "shrubberyForm");
		if (form)
			delete form;
	}

	{
		AForm * form = intern.makeForm (" ", "shrubberyForm");
		if (form)
			delete form;
	}

	{
		AForm * form = intern.makeForm ("  	", "shrubberyForm");
		if (form)
			delete form;
	}

	{
		AForm * form  = intern.makeForm ("robotomy request", "robotomyRequest");
		if (form)
			delete form;
	}

	{
		AForm * form  = intern.makeForm ("presidential pardon", "presidentialPardon");
		Bureaucrat john("john", 1);
		form->beSigned(john);
		std::cout << "After signing:" << *form << std::endl;
		if (form)
			delete form;
	}

	{
		AForm * form  = intern.makeForm ("invalid", "presidentialPardon");
		if (form)
			delete form;
	}

	try
	{
		std::unique_ptr<AForm> shrubberyForm = intern.makeSmartForm ("shrubbery creation", "shrubberyForm");
		std::cout << "Created form: " << *shrubberyForm << std::endl;
	}
	catch (std::invalid_argument const & e)
	{
		std::cerr << e.what () << std::endl;
	}

	try
	{
		std::unique_ptr<AForm> shrubberyForm = intern.makeSmartForm ("invalid", "shrubberyForm");
		std::cout << "Created form: " << *shrubberyForm << std::endl;
	}
	catch (std::invalid_argument const & e)
	{
		std::cerr << e.what () << std::endl;
	}

	return 0;
}

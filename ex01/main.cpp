#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <memory>

int main ()
{
	std::unique_ptr<Form> form1 = std::make_unique<Form> ("f1", 75, 75);
	std::unique_ptr<Form> form2 = std::make_unique<Form> ("f2", 100, 100);
	std::unique_ptr<Bureaucrat> bureaucrat = std::make_unique<Bureaucrat> ("b1", 80);
	try
	{
		form1->beSigned (*bureaucrat);
		std::cout << "Successful signing of " << *form1 << std::endl;
	}
	catch (std::exception const & e)
	{
		std::cerr << e.what () << std::endl;
	}
	try
	{
		form2->beSigned (*bureaucrat);
		std::cout << "Successful signing of " << *form2 << std::endl;
	}
	catch (std::exception const & e)
	{
		std::cerr << e.what () << std::endl;
	}
	try
	{
		bureaucrat->signForm (*form1);
	}
	catch (...)
	{
	}
	try
	{
		bureaucrat->signForm (*form2);
	}
	catch (...)
	{
	}
}
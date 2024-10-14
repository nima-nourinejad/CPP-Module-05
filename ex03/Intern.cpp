#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void coustomPrint (std::string const & name, AForm const *form, std::string flag)
{
	if (flag == "Fail")
		std::cerr << name << " form does not exists" << std::endl;
	else if (flag == "Successfull")
		std::cout << "Intern creates " << *form << std::endl;
};
std::string parseName (std::string const & name)
{
	size_t find = name.find (" ");
	if (find == std::string::npos)
		return ("Error");
	std::string formName = name.substr (0, find) + name.substr (find + 1);
	return formName;
}

//////Raw Pointer
AForm * Intern::makeForm (std::string const & name, std::string const & target) const
{
	std::string formName = parseName (name);
	std::string forms[] = {"shrubberycreation", "robotomyrequest", "presidentialpardon"};
	formMaker formMakers[] =
	    {[] (std::string const & target) -> AForm *
	     { return new ShrubberyCreationForm (target); },
	     [] (std::string const & target) -> AForm *
	     { return new RobotomyRequestForm (target); },
	     [] (std::string const & target) -> AForm *
	     { return new PresidentialPardonForm (target); }};
	int index = 0;
	while (index < 3)
	{
		if (formName == forms[index])
		{
			AForm *form = formMakers[index](target);
			coustomPrint(name, form, "Successfull");
			return form;
		}
		index++;
	}
	coustomPrint(name, nullptr, "Fail");
	return nullptr;
};

//////Smart Pointer
std::unique_ptr<AForm> Intern::makeSmartForm (std::string const & name, std::string const & target) const
{
	std::string formName = parseName (name);
	std::string forms[] = {"shrubberycreation", "robotomyrequest", "presidentialpardon"};
	int index = 0;
	while (index < 3)
	{
		if (formName == forms[index])
			break;
		index++;
	}
	switch (index)
	{
		case 0:
			return std::make_unique<ShrubberyCreationForm> (target);
			break;
		case 1:
			return std::make_unique<RobotomyRequestForm> (target);
			break;
		case 2:
			return std::make_unique<PresidentialPardonForm> (target);
			break;
		default:
			throw std::invalid_argument (name + " form does not exists");
	}
};

///////Insertation Operator
std::ostream & operator<< (std::ostream & out, Intern const & src)
{
	(void)src;
	out << "Intern";
	return out;
};
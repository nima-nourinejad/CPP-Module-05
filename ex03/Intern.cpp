#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void customPrint (std::string const & name, AForm const *form, std::string flag)
{
	if (flag == "Fail")
		std::cerr << name << " form does not exist" << std::endl;
	else if (flag == "Successfull")
		std::cout << "Intern creates " << *form << std::endl;
};

std::string parseName (std::string const & name)
{
	if (name.empty())
		return ("Error");
	size_t find = name.find (" ");
	if (find == std::string::npos)
		return ("Error");
	std::string formName = name.substr (0, find) + name.substr (find + 1);
	return formName;
}


/////////Constructors
Intern::Intern (){};
Intern::Intern (Intern const & src)
{
	(void)src;
};
Intern::Intern (Intern && src)
{
	(void)src;
};

/////////Assignment Operator
Intern & Intern::operator= (Intern const & src)
{
	(void)src;
	return *this;
}
Intern & Intern::operator= (Intern && src)
{
	(void)src;
	return *this;
}

//////Destructor
Intern::~Intern (){};

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
			customPrint(name, form, "Successfull");
			return form;
		}
		index++;
	}
	customPrint(name, nullptr, "Fail");
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
		case 1:
			return std::make_unique<RobotomyRequestForm> (target);
		case 2:
			return std::make_unique<PresidentialPardonForm> (target);
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
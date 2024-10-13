#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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

////////Destructor
Intern::~Intern (){};

///////makeForm
AForm * printError (std::string const & name)
{
	std::cerr << name << " form does not exists" << std::endl;
	return nullptr;
};
AForm * Intern::makeForm (std::string const & name, std::string const & target) const
{
	size_t find = name.find (" ");
	if (find == std::string::npos)
		return (printError (name));
	std::string formName = name.substr (0, find) + name.substr (find + 1);
	std::string forms[] = {"ShrubberyCreation", "RobotomyRequest", "PresidentialPardon"};
	fptr formMakers[] = (ShrubberyCreationForm::ShrubberyCreationForm, RobotomyRequestForm::RobotomyRequestForm, PresidentialPardonForm::PresidentialPardonForm);
	int index = 0;
	while (index < 3)
	{
		if (formName == forms[index])
			return (formMakers[index]);
		index++;
	}
	return (printError (name));
};

///////Insertation Operator
std::ostream & operator<< (std::ostream & out, Intern const & src)
{
	(void)src;
	out << "Intern";
	return out;
};
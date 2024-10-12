#include "ShrubberyCreationForm.hpp"

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm ()
    : ShrubberyCreationForm ("no_target"){};
ShrubberyCreationForm::ShrubberyCreationForm (std::string const & target)
    : AForm ("ShrubberyCreationForm", 25, 5), _target (target){};
ShrubberyCreationForm::ShrubberyCreationForm (ShrubberyCreationForm const & src)
    : AForm (src), _target (src._target){};
// Copy Assignment
ShrubberyCreationForm & ShrubberyCreationForm::operator= (ShrubberyCreationForm const & src)
{
	if (this != &src)
	{
		AForm::operator= (src);
		_target = src._target;
	}
	return *this;
};
// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm (){};
// Execute
void ShrubberyCreationForm::perform () const
{
	std::string fileName = _target + "_shrubbery";
	std::ostream file = open(fileName.c_str());
}

// Move
ShrubberyCreationForm::ShrubberyCreationForm (ShrubberyCreationForm && src)
    : AForm::AForm (std::move (src)), _target (std::move (src._target)){};
ShrubberyCreationForm & ShrubberyCreationForm::operator= (ShrubberyCreationForm && src)
{
	if (this != &src)
	{
		AForm::operator= (std::move (src));
		_target = std::move (src._target);
	}
	return *this;
};

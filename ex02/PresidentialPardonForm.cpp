#include "PresidentialPardonForm.hpp"

// Constructor
PresidentialPardonForm::PresidentialPardonForm ()
    : PresidentialPardonForm ("no_target"){};
PresidentialPardonForm::PresidentialPardonForm (std::string const & target)
    : AForm ("PresidentialPardonForm", 25, 5), _target (target){};
PresidentialPardonForm::PresidentialPardonForm (PresidentialPardonForm const & src)
    : AForm (src), _target (src._target){};
// Copy Assignment
PresidentialPardonForm & PresidentialPardonForm::operator= (PresidentialPardonForm const & src)
{
	if (this != &src)
	{
		AForm::operator= (src);
		_target = src._target;
	}
	return *this;
};
// Destructor
PresidentialPardonForm::~PresidentialPardonForm (){};
// Execute
void PresidentialPardonForm::perform () const
{

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

// Move
PresidentialPardonForm::PresidentialPardonForm (PresidentialPardonForm && src)
    : AForm::AForm (std::move (src)), _target (std::move (src._target)){};
PresidentialPardonForm & PresidentialPardonForm::operator= (PresidentialPardonForm && src)
{
	if (this != &src)
	{
		AForm::operator= (std::move (src));
		_target = std::move (src._target);
	}
	return *this;
};

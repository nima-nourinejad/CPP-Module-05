#include "RobotomyRequestForm.hpp"

// Static
bool RobotomyRequestForm::_success = true;
// Constructor
RobotomyRequestForm::RobotomyRequestForm ()
    : RobotomyRequestForm ("no_target"){};
RobotomyRequestForm::RobotomyRequestForm (std::string const & target)
    : AForm ("RobotomyRequestForm", 72, 45), _target (target){};
RobotomyRequestForm::RobotomyRequestForm (RobotomyRequestForm const & src)
    : AForm (src), _target (src._target){};
// Copy Assignment
RobotomyRequestForm & RobotomyRequestForm::operator= (RobotomyRequestForm const & src)
{
	if (this != &src)
	{
		AForm::operator= (src);
		_target = src._target;
	}
	return *this;
};
// Destructor
RobotomyRequestForm::~RobotomyRequestForm (){};
// Execute
void RobotomyRequestForm::perform () const
{
	std::cout << "Drilling noise ...." << std::endl;
	if (_success)
	{
		std::cout << _target << " has been robotomized" << std::endl;
		_success = false;
	}
	else
	{
		std::cout << "Robotomy failed" << std::endl;
		_success = true;
	}
};

//Move
RobotomyRequestForm::RobotomyRequestForm (RobotomyRequestForm  && src) : AForm::AForm(std::move(src)), _target(std::move(src._target)){};
RobotomyRequestForm & RobotomyRequestForm::operator= (RobotomyRequestForm && src){
	if (this != &src)
	{
		AForm::operator=(std::move(src));
		_target = std::move(src._target);
	}
	return *this;
};

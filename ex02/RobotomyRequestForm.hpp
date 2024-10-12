#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>

class RobotomyRequestForm : public AForm
{
	private:
		static bool _success;
		std::string _target;

	public:
		RobotomyRequestForm ();
		RobotomyRequestForm (std::string const & target);
		RobotomyRequestForm (RobotomyRequestForm const & src);
		RobotomyRequestForm & operator= (RobotomyRequestForm const & src);
		~RobotomyRequestForm ();
		void perform () const override;
		RobotomyRequestForm (RobotomyRequestForm  && src);
		RobotomyRequestForm & operator= (RobotomyRequestForm && src);
};

#endif

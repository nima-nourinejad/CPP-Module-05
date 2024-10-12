#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;

	public:
		PresidentialPardonForm ();
		PresidentialPardonForm (std::string const & target);
		PresidentialPardonForm (PresidentialPardonForm const & src);
		PresidentialPardonForm & operator= (PresidentialPardonForm const & src);
		~PresidentialPardonForm ();
		void perform () const override;
		PresidentialPardonForm (PresidentialPardonForm  && src);
		PresidentialPardonForm & operator= (PresidentialPardonForm && src);
};

#endif

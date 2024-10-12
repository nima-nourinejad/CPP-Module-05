#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>
#include <ostream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;

	public:
		ShrubberyCreationForm ();
		ShrubberyCreationForm (std::string const & target);
		ShrubberyCreationForm (ShrubberyCreationForm const & src);
		ShrubberyCreationForm & operator= (ShrubberyCreationForm const & src);
		~ShrubberyCreationForm ();
		void perform () const override;
		ShrubberyCreationForm (ShrubberyCreationForm  && src);
		ShrubberyCreationForm & operator= (ShrubberyCreationForm && src);
};

#endif

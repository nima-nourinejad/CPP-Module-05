#include "Form.hpp"

Form::GradeTooHighException::GradeTooHighException (std::string const & name, Bureaucrat const & bureaucrat)
    : std::out_of_range (name + " : form Error : " + (std::ostringstream () << bureaucrat).str () + " is too high"){};
Form::GradeTooLowException::GradeTooLowException (std::string const & name, Bureaucrat const & bureaucrat)
    : std::out_of_range (name + " from Error : " + (std::ostringstream () << bureaucrat).str () + " is too low"){};

void Form::beSigned (Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade () >= _signGrade)
		_signed = true;
	else
		throw Form::GradeTooLowException (_name, bureaucrat);
};

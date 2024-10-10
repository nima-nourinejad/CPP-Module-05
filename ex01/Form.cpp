#include "Form.hpp"

Form::GradeTooHighException::GradeTooHighException (std::string const& name, Bureaucrat const& bureaucrat)
    : std::out_of_range (name + " : Error : " + (std::ostringstream () << bureaucrat).str () + " is too high")
{
}
Form::GradeTooLowException::GradeTooLowException (std::string const& name, Bureaucrat const& bureaucrat)
    : std::out_of_range (name + " Error : " + (std::ostringstream () << bureaucrat).str () + " is too low")
{
}

void Form::beSigned (Bureaucrat const& bureaucrat)
{
}
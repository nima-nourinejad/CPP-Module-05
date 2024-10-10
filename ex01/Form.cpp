#include "Form.hpp"
#include "Bureaucrat.hpp"

/////////////////////// Construtors
Form::Form ()
    : _name ("no_name_form"), _signed (false), _signGrade (0), _executeGrade (0){};
Form::Form (std::string const & name, int signGrade, int executeGrade)
    : _name (name), _signed (false), _signGrade (signGrade), _executeGrade (executeGrade){};
Form::Form (Form const & src)
    : _name (src._name), _signed (false), _signGrade (src._signGrade), _executeGrade (src._executeGrade){};

/////////////////////// Copy Assignment
Form & Form::operator= (Form const & src)
{
	if (this == &src)
		return *this;
	this->_signed = src._signed;
	return *this;
};

/////////////////////// Destructor
Form::~Form (){};

/////////////////////// Getters
std::string const & Form::getName () const
{
	return _name;
};
bool Form::getSigned () const
{
	return _signed;
};
int Form::getSignGrade () const
{
	return _signGrade;
};
int Form::getExecuteGrade () const
{
	return _executeGrade;
};

/////////////////////// beSigned
void Form::beSigned (Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade () <= _signGrade)
		_signed = true;
	else
		throw Form::GradeTooLowException (*this, bureaucrat);
};

/////////////////////// Exceptions
Form::GradeTooHighException::GradeTooHighException (Form const & form, Bureaucrat const & bureaucrat)
    : std::out_of_range ((std::ostringstream () << bureaucrat).str () + " is too high level for " + form.getName ()){};
Form::GradeTooLowException::GradeTooLowException (Form const & form, Bureaucrat const & bureaucrat)
    : std::out_of_range ((std::ostringstream () << bureaucrat).str () + " is too low level for " + form.getName ()){};

/////////////////////// Insertation Operator
std::ostream & operator<< (std::ostream & out, Form const & src)
{
	out << src.getName () << " form";
	out << "(signGrade: " << src.getSignGrade ();
	out << ", executeGrade: " << src.getExecuteGrade ();
	if (src.getSigned ())
		out << ", signed)";
	else
		out << ", not signed)";
	return out;
};
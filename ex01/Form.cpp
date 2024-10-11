#include "Form.hpp"
#include "Bureaucrat.hpp"

/////////////////////// Statics
int const Form::_lowestGrade = 150;
int const Form::_highestGrade = 1;

void Form::check_valid_grades (int signGrade, int executeGrade, std::string const & name, std::string const & type) const
{

	if (signGrade > _lowestGrade)
		throw GradeTooLowException (name, type, signGrade);
	if (signGrade < _highestGrade)
		throw GradeTooHighException (name, type, signGrade);
	if (executeGrade > _lowestGrade)
		throw GradeTooLowException (name, type, executeGrade);
	if (executeGrade < _highestGrade)
		throw GradeTooHighException (name, type, executeGrade);
}

/////////////////////// Construtors
Form::Form ()
    : _name ("no_name_form"), _signed (false), _signGrade (_highestGrade), _executeGrade (_highestGrade){};
Form::Form (std::string const & name, int signGrade, int executeGrade)
    : _name (name), _signed (false), _signGrade (signGrade), _executeGrade (executeGrade)
{
	check_valid_grades (signGrade, executeGrade, name, "construction");
};
Form::Form (Form const & src)
    : _name (src._name), _signed (false), _signGrade (src._signGrade), _executeGrade (src._executeGrade)
{
	check_valid_grades (src._signGrade, src._executeGrade, _name, "copy construction");
};

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
		throw GradeTooLowException (_name, "beSigned", bureaucrat.getGrade ());
};

/////////////////////// Exceptions
Form::GradeTooHighException::GradeTooHighException (std::string const & name, std::string const & type, int grade)
    : std::out_of_range (name + " form : " + type + " Error: Grade " + std::to_string (grade) + " is too high"){};
Form::GradeTooHighException::GradeTooHighException ()
    : std::out_of_range ("The grade is too high"){};
Form::GradeTooHighException::GradeTooHighException (GradeTooHighException const & src)
    : std::out_of_range (src.what ()){};
Form::GradeTooHighException & Form::GradeTooHighException::operator= (GradeTooHighException const & src)
{
	if (this != &src)
		std::out_of_range::operator= (src);
	return *this;
}
Form::GradeTooHighException::~GradeTooHighException (){};
///////////
Form::GradeTooLowException::GradeTooLowException (std::string const & name, std::string const & type, int grade)
    : std::out_of_range (name + " form : " + type + " Error: Grade " + std::to_string (grade) + " is too low"){};
Form::GradeTooLowException::GradeTooLowException ()
    : std::out_of_range ("The grade is too low"){};
Form::GradeTooLowException::GradeTooLowException (Form::GradeTooLowException const & src)
    : std::out_of_range (src.what ()){};
Form::GradeTooLowException & Form::GradeTooLowException::operator= (Form::GradeTooLowException const & src)
{
	if (this != &src)
		std::out_of_range::operator= (src);
	return *this;
};
Form::GradeTooLowException::~GradeTooLowException (){};
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
#include "AForm.hpp"
#include "Bureaucrat.hpp"

/////////////////////// Statics
int const AForm::_lowestGrade = 150;
int const AForm::_highestGrade = 1;

void AForm::check_valid_grades (int signGrade, int executeGrade, std::string const & name, std::string const & type) const
{

	if (signGrade > _lowestGrade)
		throw AForm::GradeTooLowException (name, type, signGrade);
	if (signGrade < _highestGrade)
		throw AForm::GradeTooHighException (name, type, signGrade);
	if (executeGrade > _lowestGrade)
		throw AForm::GradeTooLowException (name, type, executeGrade);
	if (executeGrade < _highestGrade)
		throw AForm::GradeTooHighException (name, type, executeGrade);
}

/////////////////////// Construtors
AForm::AForm ()
    : _name ("no_name_form"), _signed (false), _signGrade (_highestGrade), _executeGrade (_highestGrade){};
AForm::AForm (std::string const & name, int signGrade, int executeGrade)
    : _name (name), _signed (false), _signGrade (signGrade), _executeGrade (executeGrade)
{
	AForm::check_valid_grades (signGrade, executeGrade, name, "construction");
};
AForm::AForm (AForm const & src)
    : _name (src._name), _signed (false), _signGrade (src._signGrade), _executeGrade (src._executeGrade)
{
	AForm::check_valid_grades (src._signGrade, src._executeGrade, _name, "copy construction");
};

/////////////////////// Copy Assignment
AForm & AForm::operator= (AForm const & src)
{
	if (this == &src)
		return *this;
	this->_signed = src._signed;
	return *this;
};

/////////////////////// Destructor
AForm::~AForm (){};

/////////////////////// Getters
std::string const & AForm::getName () const
{
	return _name;
};
bool AForm::getSigned () const
{
	return _signed;
};
int AForm::getSignGrade () const
{
	return _signGrade;
};
int AForm::getExecuteGrade () const
{
	return _executeGrade;
};

/////////////////////// beSigned
void AForm::beSigned (Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade () <= _signGrade)
		_signed = true;
	else
		throw AForm::GradeTooLowException (_name, "beSigned", bureaucrat.getGrade ());
};

/////////////////////// Exceptions
AForm::GradeTooHighException::GradeTooHighException (std::string const & name, std::string const & type, int grade)
    : std::out_of_range (name + " form : " + type + " Error: Grade " + std::to_string (grade) + " is too high"){};
AForm::GradeTooLowException::GradeTooLowException (std::string const & name, std::string const & type, int grade)
    : std::out_of_range (name + " form : " + type + " Error: Grade " + std::to_string (grade) + " is too low"){};

/////////////////////// Insertation Operator
std::ostream & operator<< (std::ostream & out, AForm const & src)
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
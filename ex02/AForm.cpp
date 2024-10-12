#include "AForm.hpp"
#include "Bureaucrat.hpp"

/////////////////////// Statics
int const AForm::_lowestGrade = 150;
int const AForm::_highestGrade = 1;

void AForm::check_valid_grades (int signGrade, int executeGrade, std::string const & name, std::string const & type) const
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
AForm::AForm ()
    : _name ("no_name_form"), _signed (false), _signGrade (_highestGrade), _executeGrade (_highestGrade){};
AForm::AForm (std::string const & name, int signGrade, int executeGrade)
    : _name (name), _signed (false), _signGrade (signGrade), _executeGrade (executeGrade)
{
	check_valid_grades (signGrade, executeGrade, name, "construction");
};
AForm::AForm (AForm const & src)
    : _name (src._name), _signed (false), _signGrade (src._signGrade), _executeGrade (src._executeGrade)
{
	check_valid_grades (src._signGrade, src._executeGrade, _name, "copy construction");
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
		throw GradeTooLowException (_name, "beSigned", bureaucrat.getGrade ());
};

/////////////////////// Exceptions
AForm::GradeTooHighException::GradeTooHighException (std::string const & name, std::string const & type, int grade)
    : std::out_of_range (name + " form : " + type + " Error: Grade " + std::to_string (grade) + " is too high"){};
AForm::GradeTooHighException::GradeTooHighException ()
    : std::out_of_range ("The grade is too high"){};
AForm::GradeTooHighException::GradeTooHighException (GradeTooHighException const & src)
    : std::out_of_range (src.what ()){};
AForm::GradeTooHighException & AForm::GradeTooHighException::operator= (GradeTooHighException const & src)
{
	if (this != &src)
		std::out_of_range::operator= (src);
	return *this;
}
AForm::GradeTooHighException::~GradeTooHighException (){};
///////////

AForm::GradeTooLowException::GradeTooLowException (std::string const & name, std::string const & type, int grade)
    : std::out_of_range (name + " form : " + type + " Error: Grade " + std::to_string (grade) + " is too low"){};
AForm::GradeTooLowException::GradeTooLowException ()
    : std::out_of_range ("The grade is too low"){};
AForm::GradeTooLowException::GradeTooLowException (AForm::GradeTooLowException const & src)
    : std::out_of_range (src.what ()){};
AForm::GradeTooLowException & AForm::GradeTooLowException::operator= (AForm::GradeTooLowException const & src)
{
	if (this != &src)
		std::out_of_range::operator= (src);
	return *this;
};
AForm::GradeTooLowException::~GradeTooLowException (){};

///////////////////////
AForm::FormNotSignedException::FormNotSignedException (std::string const & name)
    : std::exception (), _message (name + " form: The form is not signed."){};
AForm::FormNotSignedException::FormNotSignedException ()
    : std::exception (), _message ("The form is not signed"){};
AForm::FormNotSignedException::FormNotSignedException (AForm::FormNotSignedException const & src)
    : std::exception (), _message (src._message){};
AForm::FormNotSignedException & AForm::FormNotSignedException::operator= (AForm::FormNotSignedException const & src)
{
	if (this != &src)
	{
		std::exception::operator= (src);
		this->_message = src._message;
	}
	return *this;
}
AForm::FormNotSignedException::~FormNotSignedException (){};
char const * AForm::FormNotSignedException::what () const
{
	return (_message.c_str ());
};
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

/////////////////////// checkAndExecute
void AForm::checkForExecute (Bureaucrat const & executor) const
{
	if (!_signed)
		throw FormNotSignedException (_name);
	if (executor.getGrade () < _executeGrade)
		throw GradeTooLowException (_name, "execution", executor.getGrade ());
};

void AForm::execute (Bureaucrat const & executor) const
{
	checkForExecute(executor);
	perform();
};
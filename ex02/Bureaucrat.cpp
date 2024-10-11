#include "Bureaucrat.hpp"
#include "AForm.hpp"

const int Bureaucrat::_lowestGrade = 150;
const int Bureaucrat::_highestGrade = 1;

Bureaucrat::Bureaucrat ()
    : _name ("no_name_bureaucrat"), _grade (_lowestGrade){};

Bureaucrat::Bureaucrat (std::string const & name, int grade)
    : _name (name)
{
	if (grade > _lowestGrade)
		throw GradeTooLowException (name, "construction", grade);
	if (grade < _highestGrade)
		throw GradeTooHighException (name, "construction", grade);
	_grade = grade;
};

Bureaucrat::Bureaucrat (Bureaucrat const & src)
    : _name (src._name)
{
	if (src._grade > _lowestGrade)
		throw GradeTooLowException (_name, "copy construction", src._grade);
	if (src._grade < _highestGrade)
		throw GradeTooHighException (_name, "copy construction", src._grade);
	_grade = src._grade;
};

Bureaucrat & Bureaucrat::operator= (Bureaucrat const & src)
{
	if (this == &src)
		return *this;

	if (src._grade > _lowestGrade)
		throw GradeTooLowException (_name, "copy assignment", src._grade);
	if (src._grade < _highestGrade)
		throw GradeTooHighException (_name, "copy assignment", src._grade);
	_grade = src._grade;
	return *this;
};

Bureaucrat::~Bureaucrat (){};

std::string const & Bureaucrat::getName () const
{
	return _name;
};

int Bureaucrat::getGrade () const
{
	return _grade;
};

void Bureaucrat::incrementGrade ()
{
	if ((_grade - 1) < _highestGrade)
		throw GradeTooHighException (_name, "incrementGrade", (_grade - 1));
	--_grade;
};

void Bureaucrat::decrementGrade ()
{
	if ((_grade + 1) > _lowestGrade)
		throw GradeTooLowException (_name, "decrementGrade", (_grade + 1));
	++_grade;
};

std::ostream & operator<< (std::ostream & out, Bureaucrat const & src)
{
	out << src.getName () << " bureaucrat grade " << src.getGrade ();
	return out;
};

////////////////
Bureaucrat::GradeTooHighException::GradeTooHighException (std::string const & name, std::string const & type, int grade)
    : std::out_of_range (name + " bureaucrat : " + type + " Error: Grade " + std::to_string (grade) + " is too high"){};
Bureaucrat::GradeTooHighException::GradeTooHighException ()
    : std::out_of_range ("The grade is too high"){};
Bureaucrat::GradeTooHighException::GradeTooHighException (GradeTooHighException const & src)
    : std::out_of_range (src.what ()){};
Bureaucrat::GradeTooHighException & Bureaucrat::GradeTooHighException::operator= (GradeTooHighException const & src)
{
	if (this != &src)
		std::out_of_range::operator= (src);
	return *this;
}
Bureaucrat::GradeTooHighException::~GradeTooHighException (){};
///////////
Bureaucrat::GradeTooLowException::GradeTooLowException (std::string const & name, std::string const & type, int grade)
    : std::out_of_range (name + " bureaucrat : " + type + " Error : Grade " + std::to_string (grade) + " is too low"){};
Bureaucrat::GradeTooLowException::GradeTooLowException ()
    : std::out_of_range ("The grade is too low"){};
Bureaucrat::GradeTooLowException::GradeTooLowException (Bureaucrat::GradeTooLowException const & src)
    : std::out_of_range (src.what ()){};
Bureaucrat::GradeTooLowException & Bureaucrat::GradeTooLowException::operator= (Bureaucrat::GradeTooLowException const & src)
{
	if (this != &src)
		std::out_of_range::operator= (src);
	return *this;
};
Bureaucrat::GradeTooLowException::~GradeTooLowException (){};
///////////////////////
void Bureaucrat::signForm (AForm & form) const
{
	try
	{
		form.beSigned (*this);
		std::cout << *this << " signed " << form << std::endl;
	}
	catch (AForm::GradeTooLowException const & e)
	{
		std::cerr << *this << " couldn't sign " << form << " because: " << e.what () << std::endl;
	}
};
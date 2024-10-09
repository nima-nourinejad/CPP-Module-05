#include "Bureaucrat.hpp"

constexpr int LOWEST_GRADE = 150;
constexpr int HIGHEST_GRADE = 1;

Bureaucrat::Bureaucrat ()
    : _name ("no_name"), _grade (LOWEST_GRADE){};

Bureaucrat::Bureaucrat (std::string const& name, int grade)
    : _name (name)
{
	if (grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException (name, "construction", grade);
	if (grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException (name, "construction", grade);
	_grade = grade;
};

Bureaucrat::Bureaucrat (Bureaucrat const& src)
    : _name (src._name), _grade (src._grade){};

Bureaucrat& Bureaucrat::operator= (Bureaucrat const& src)
{
	if (this != &src)
		_grade = src._grade;
	return *this;
};

Bureaucrat::~Bureaucrat ()
{
	std::cout << _name << " destroyed" << std::endl;
};

std::string const& Bureaucrat::getName () const
{
	return _name;
};

int Bureaucrat::getGrade () const
{
	return _grade;
};

void Bureaucrat::incrementGrade ()
{
	if ((_grade - 1) < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException (_name, "incrementGrade", (_grade - 1));
	--_grade;
};

void Bureaucrat::decrementGrade ()
{
	if ((_grade + 1) > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException (_name, "decrementGrade", (_grade + 1));
	++_grade;
};

std::ostream& operator<< (std::ostream& out, Bureaucrat const& src)
{
	out << src.getName () << " bureaucrat grade " << src.getGrade ();
	return out;
};

Bureaucrat::GradeTooHighException::GradeTooHighException (std::string const& name, std::string const& type, int grade)
    : std::out_of_range (name + " bureaucrat : " + type + " Error: Grade " + std::to_string (grade) + " is too high"){};

Bureaucrat::GradeTooLowException::GradeTooLowException (std::string const& name, std::string const& type, int grade)
    : std::out_of_range (name + " bureaucrat : " + type + " Error : Grade " + std::to_string (grade) + " is too low"){};
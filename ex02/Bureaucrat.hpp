#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>

class AForm;

class Bureaucrat
{
	private:
		std::string const _name;
		int _grade;
		class GradeTooHighException : public std::out_of_range
		{
			public:
				GradeTooHighException (std::string const & name, std::string const & type, int grade);
				GradeTooHighException();
				GradeTooHighException(GradeTooHighException const & src);
				GradeTooHighException & operator=(GradeTooHighException const & src);
				~GradeTooHighException() noexcept;
		};
		class GradeTooLowException : public std::out_of_range
		{
			public:
				GradeTooLowException (std::string const & name, std::string const & type, int grade);
				GradeTooLowException();
				GradeTooLowException(GradeTooLowException const & src);
				GradeTooLowException & operator=(GradeTooLowException const & src);
				~GradeTooLowException() noexcept;
		};
		static const int _lowestGrade;
		static const int _highestGrade;

	public:
		Bureaucrat (std::string const & name, int grade);
		Bureaucrat ();
		Bureaucrat (Bureaucrat const & src);
		Bureaucrat & operator= (Bureaucrat const & src);
		~Bureaucrat ();
		std::string const & getName () const;
		int getGrade () const;
		void incrementGrade ();
		void decrementGrade ();
		void signForm (AForm & form) const;
		void executeForm(AForm const & form) const;
};

std::ostream & operator<< (std::ostream & out, Bureaucrat const & src);

#endif
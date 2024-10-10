#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>

class Form
{
	private:
		std::string const _name;
		bool _signed;
		int const _signGrade;
		int const _executeGrade;

	public:
		Form ();
		Form (std::string const & name, int grade);
		Form (Form const & src);
		Form & operator= (Form const & src);
		~Form ();
		std::string & getName () const;
		bool getSigned () const;
		int getSignGrade () const;
		int getExecuteGrade () const;
		void beSigned (Bureaucrat const & bureaucrat);
		class GradeTooHighException : public std::out_of_range
		{
			public:
				GradeTooHighException (std::string const & name, Bureaucrat const & bureaucrat);
		};
		class GradeTooLowException : public std::out_of_range
		{
			public:
				GradeTooLowException (std::string const & name, Bureaucrat const & bureaucrat);
		};
};

std::ostream & operator<< (std::ostream & out, Form const & src);

#endif
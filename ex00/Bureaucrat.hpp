#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>

class Bureaucrat
{
	private:
		std::string const _name;
		int _grade;
		class GradeTooHighException : public std::out_of_range
		{
			public:
				GradeTooHighException (std::string const & name, std::string const & type, int grade);
		};
		class GradeTooLowException : public std::out_of_range
		{
			public:
				GradeTooLowException (std::string const & name, std::string const & type, int grade);
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
};

std::ostream & operator<< (std::ostream & out, Bureaucrat const & src);

#endif
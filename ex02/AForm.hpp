#ifndef FORM_HPP
#define FORM_HPP

#include <ostream>
#include <stdexcept>
#include <string>

class Bureaucrat;

class AForm
{
	private:
		std::string const _name;
		bool _signed;
		int const _signGrade;
		int const _executeGrade;
		static int const _lowestGrade;
		static int const _highestGrade;
		void check_valid_grades (int signGrade, int executeGrade, std::string const & name, std::string const & type) const;

	public:
		AForm ();
		AForm (std::string const & name, int signGrade, int executeGrade);
		AForm (AForm const & src);
		AForm & operator= (AForm const & src);
		virtual ~AForm ();
		std::string const & getName () const;
		bool getSigned () const;
		int getSignGrade () const;
		int getExecuteGrade () const;
		void beSigned (Bureaucrat const & bureaucrat);
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
};

std::ostream & operator<< (std::ostream & out, AForm const & src);

#endif
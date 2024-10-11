#ifndef FORM_HPP
#define FORM_HPP

#include <ostream>
#include <exception>
#include <string>

class Bureaucrat;

class Form
{
	private:
		std::string const _name;
		bool _signed;
		int const _signGrade;
		int const _executeGrade;
		static int const _lowestGrade;
		static int const _highestGrade;
		void check_valid_grades (int signGrade, int executeGrade, std::string const & name, std::string const & type) const;
		class GradeTooHighException : public std::out_of_range
		{
			public:
				GradeTooHighException (std::string const & name, std::string const & type, int grade);
				GradeTooHighException();
				GradeTooHighException(GradeTooHighException const & src);
				GradeTooHighException & operator=(GradeTooHighException const & src);
				~GradeTooHighException() noexcept;
		};

	public:
		Form ();
		Form (std::string const & name, int signGrade, int executeGrade);
		Form (Form const & src);
		Form & operator= (Form const & src);
		~Form ();
		std::string const & getName () const;
		bool getSigned () const;
		int getSignGrade () const;
		int getExecuteGrade () const;
		void beSigned (Bureaucrat const & bureaucrat);
		class GradeTooLowException : public std::out_of_range
		{
			public:
				GradeTooLowException (std::string const & name, std::string const & type, int grade);
				GradeTooLowException();
				GradeTooLowException(GradeTooLowException const & src);
				GradeTooLowException & operator=(GradeTooLowException const & src);
				~GradeTooLowException() noexcept;
		};
};

std::ostream & operator<< (std::ostream & out, Form const & src);

#endif
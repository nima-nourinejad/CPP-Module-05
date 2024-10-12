#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <ostream>
#include <string>
#include <utility>

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
		class GradeTooHighException : public std::out_of_range
		{
			public:
				GradeTooHighException (std::string const & name, std::string const & type, int grade);
				GradeTooHighException ();
				GradeTooHighException (GradeTooHighException const & src);
				GradeTooHighException & operator= (GradeTooHighException const & src);
				~GradeTooHighException () noexcept;
		};

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
		class GradeTooLowException : public std::out_of_range
		{
			public:
				GradeTooLowException (std::string const & name, std::string const & type, int grade);
				GradeTooLowException ();
				GradeTooLowException (GradeTooLowException const & src);
				GradeTooLowException & operator= (GradeTooLowException const & src);
				~GradeTooLowException () noexcept;
		};
		class FormNotSignedException : public std::exception
		{
			private:
				std::string _message;

			public:
				FormNotSignedException ();
				FormNotSignedException (FormNotSignedException const & src);
				FormNotSignedException & operator= (FormNotSignedException const & src);
				~FormNotSignedException () noexcept;
				FormNotSignedException (std::string const & name);
				char const * what () const noexcept override;
		};
		void checkForExecute (Bureaucrat const & executor) const;
		virtual void perform () const = 0;
		void execute (Bureaucrat const & executor) const;

		AForm(AForm && src);
		AForm & operator =(AForm && src);
};

std::ostream & operator<< (std::ostream & out, AForm const & src);

#endif
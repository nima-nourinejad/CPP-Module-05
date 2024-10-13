#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include <ostream>
class AForm;

class Intern
{
	public:
		Intern ();
		Intern (Intern const & src);
		Intern (Intern && src);
		Intern & operator= (Intern const & src);
		Intern & operator= (Intern && src);
		~Intern ();
		AForm * makeForm(std::string const & name, std::string const & target) const;
		using fptr = AForm * (std::string const & target);
};

std::ostream & operator<<(std::ostream & out, Intern const & src);

#endif
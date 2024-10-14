#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <ostream>
#include <string>
#include <memory>
class AForm;

class Intern
{
	public:
		Intern () = default;
		Intern (Intern const & src) = default;
		Intern (Intern && src) = default;
		Intern & operator= (Intern const & src) = default;
		Intern & operator= (Intern && src) = default;
		~Intern () = default;
		AForm * makeForm (std::string const & name, std::string const & target) const;
		std::unique_ptr<AForm> makeSmartForm (std::string const & name, std::string const & target) const;
		using formMaker = AForm * (*)(const std::string &);
};

std::ostream & operator<< (std::ostream & out, Intern const & src);

#endif
#ifndef HARL_HPP
#define HARL_HPP

# include <string>
# include <iostream>
# include <map>

class Harl {
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		typedef void (Harl::*HarlMemFn)();
		std::map<std::string, HarlMemFn> complaints;
	public:
		Harl();
		void	complain(std::string level);
};

#endif
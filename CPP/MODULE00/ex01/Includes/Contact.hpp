#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {

private:
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_darkest_secret;

public:
	Contact(void);
	~Contact(void);

	void	set_attributes(void);
	void	display_columns(void);
	void	display_fields(void);

};

#endif

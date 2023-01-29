#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {

private:
	Contact _contacts[8];
	int		_nb_contacts;
	int		_curr_index;

public:
	PhoneBook(void);
	~PhoneBook(void);

	void	add_contact(Contact contact);
	void	display_contacts(void);
	void	get_contact(void);
};

#endif

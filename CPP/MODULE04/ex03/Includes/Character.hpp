#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"

class Character : public ICharacter {

private:
	const std::string	_name;
	AMateria			*_inventory[4];

public:
	Character( void );
	Character( std::string const & name );
	Character( const Character &other );
	~Character( void );
	Character &operator=( const Character &other );

	virtual std::string const & getName( void ) const;
	virtual void equip( AMateria* m );
	virtual void unequip( int idx );
	virtual void use( int idx, ICharacter& target );
};

#endif

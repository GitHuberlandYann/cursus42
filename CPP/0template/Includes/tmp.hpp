#ifndef TMP_HPP
# define TMP_HPP

class Tmp {

private:

public:
	Tmp( void );
	Tmp( const Tmp &other );
	~Tmp( void );
	Tmp &operator=( const Tmp &other );

};

#endif

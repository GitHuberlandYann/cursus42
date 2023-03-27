#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

private:
	AMateria	*_templates[4];

public:
	MateriaSource( void );
	MateriaSource( const MateriaSource &other );
	~MateriaSource( void );
	MateriaSource &operator=( const MateriaSource &other );

	virtual void learnMateria(AMateria* m);
	virtual AMateria* createMateria(std::string const & type);
};

#endif

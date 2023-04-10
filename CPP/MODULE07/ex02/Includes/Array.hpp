#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template<typename T>
class Array {

private:
	unsigned int _size;
	T* _array;

public:
	Array<T>( void ) : _size(0), _array(new T[0]) {
		std::cout << "Default constructor of Array called" << std::endl;
		return ;
	}
	Array<T>( unsigned int size ) : _size(size), _array(new T[size]) {
		std::cout << "Setter constructor of Array called" << std::endl;
		return ;
	}
	Array<T>( const Array &other ) : _size(other._size), _array(new T[other._size]) {
		std::cout << "Copy constructor of Array called" << std::endl;
		for (unsigned int i = 0; i < this->_size; i++) {
			this->_array[i] = other._array[i];
		}
		return ;
	}
	~Array<T>( void ) {
		std::cout << "Destructor of Array called" << std::endl;
		delete [] this->_array;
		return ;
	}
	Array &operator=( const Array &other ) {
		std::cout << "Copy assignment operator of Array called" << std::endl;
		delete [] this->_array;
		this->_array = new T[other._size];
		for (unsigned int i = 0; i < other._size; i++) {
			this->_array[i] = other._array[i];
		}
		this->_size = other._size;
		return (*this);
	}
	T& operator[] ( unsigned int index ) {
		if (index >= this->_size) {
			throw Array<T>::IndexOutOfBoundsException();
		}
		return (this->_array[index]);
	}

	unsigned int size( void ) {
		return (this->_size);
	}

	class IndexOutOfBoundsException: public std::exception {
	
	public:
		virtual const char* what() const throw() {
			return ("[Array<T>::IndexOutOfBoundsException] Index is out of bounds.");
		}
	};
};

#endif

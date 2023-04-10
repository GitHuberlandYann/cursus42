#ifndef ITER_HPP
# define ITER_HPP

template<typename T, typename Function>
void iter( T array[], int lenght, Function fun ) {
	for (int i = 0; i < lenght; i++) {
		fun(array[i]);
	}
}

#endif

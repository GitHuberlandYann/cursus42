/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:49:12 by yhuberla          #+#    #+#             */
/*   Updated: 2023/04/17 13:49:12 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// ************************************************************************** //
//                                 Parsing                                    //
// ************************************************************************** //

static int check_int( char *str ) {
	if (str[0] == '0' && str[1])
		return (1);
	int index = 0;
	for (; isdigit(str[index]); index++);
	if (str[index])
		return (1);

	std::istringstream iss( str );
	int toint;
	iss >> toint;
	return (iss.fail());
}

void parse_inputs( char **args ) {
	for (int index = 1; args[index]; index++) {
		if (check_int( args[index] )) {
			throw InvalidInputException();
		}
	}
}

// ************************************************************************** //
//                                  vector                                    //
// ************************************************************************** //

static void insert_vector( std::vector<int> &vect, int left, int right ) {
	// std::cout << "insert left " << left << " right " << right << std::endl;
	for (int index = left; index < right; index++) {
		int tmp_value = vect[index + 1];
		int jndex = index + 1;
		while (jndex > left && vect[jndex - 1] > tmp_value) {
			vect[jndex] = vect[jndex - 1];
			jndex--;
		}
		vect[jndex] = tmp_value;
	}
}

static void merge_vector( std::vector<int> &vect, int left, int mid, int right ) {
	int section1 = mid - left + 1;
	int section2 = right - mid;

	// std::vector<int>::iterator iit = vect.begin();
	// std::vector<int>::iterator iite = vect.end();
	// for (; iit != iite; iit++) {
	// 	std::cout << *iit << " ";
	// }
	// std::cout << std::endl;
	// std::cout << "merge left " << left << " mid " << mid << " right " << right << std::endl;

	std::vector<int>::iterator it = vect.begin() + left;
	std::vector<int>::iterator itm = vect.begin() + mid;
	std::vector<int>::iterator ite = vect.begin() + right;
	std::vector<int> vect_left = std::vector<int>(it, itm + 1);
	std::vector<int> vect_right = std::vector<int>(itm + 1, ite + 1);
	int right_index = 0;
	int left_index = 0;
	for (int index = left; index < right + 1; index++) {
		if (right_index == section2) {
			vect[index] = vect_left[left_index];
			left_index++;
		} else if (left_index == section1) {
			vect[index] = vect_right[right_index];
			right_index++;
		} else if (vect_right[right_index] > vect_left[left_index]) {
			vect[index] = vect_left[left_index];
			left_index++;
		} else {
			vect[index] = vect_right[right_index];
			right_index++;
		}
	}

	// iit = vect.begin();
	// iite = vect.end();
	// for (; iit != iite; iit++) {
	// 	std::cout << *iit << " ";
	// }
	// std::cout << std::endl;
}

static void merge_sort_vector( std::vector<int> &vect, int left, int right )
{
	// std::cout << "at " << left << ' ' << right << ": ";
	// std::vector<int>::iterator it = vect.begin();
	// std::vector<int>::iterator ite = vect.end();
	// for (; it != ite; it++) {
	// 	std::cout << *it << " ";
	// }
	// std::cout << std::endl;
	if (right - left > K_LIMIT) {
		int mid = (left + right) / 2;
		// std::cout << "m left " << left << " mid " << mid << " right " << right << std::endl;
		merge_sort_vector( vect, left, mid );
		merge_sort_vector( vect, mid + 1, right );
		merge_vector( vect, left, mid, right );
	} else {
		insert_vector( vect, left, right );
	}
}

void merge_insert_vector( char **args ) {
	{
	std::vector<int> vect;

	for (int index = 1; args[index]; index++) {
		std::istringstream iss( args[index] );
		int toint;
		iss >> toint;
		vect.push_back( toint );
	}
	merge_sort_vector( vect, 0, vect.size() - 1 );
	std::cout << "After  : ";
	std::vector<int>::iterator it = vect.begin();
	std::vector<int>::iterator ite = vect.end();
	for (; it != ite; it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	}
	clock_t a = clock();
	{
	std::vector<int> vect;

	for (int index = 1; args[index]; index++) {
		std::istringstream iss( args[index] );
		int toint;
		iss >> toint;
		vect.push_back( toint );
	}
	// std::cout << "before : ";
	// std::vector<int>::iterator it = vect.begin();
	// std::vector<int>::iterator ite = vect.end();
	// for (; it != ite; it++) {
	// 	std::cout << *it << " ";
	// }
	// std::cout << std::endl;
	clock_t sort_time = clock();
	merge_sort_vector( vect, 0, vect.size() - 1 );
	sort_time = clock() - sort_time;
	std::cout << "time with std::vector : " << ((float)sort_time * 1000) / CLOCKS_PER_SEC << std::endl;
	// std::cout << "after  : ";
	// it = vect.begin();
	// ite = vect.end();
	// for (; it != ite; it++) {
	// 	std::cout << *it << " ";
	// }
	// std::cout << std::endl;
	}
	a = clock() - a;
	std::cout << "total time with std::vector : " << ((float)a * 1000) / CLOCKS_PER_SEC << std::endl;
}

// ************************************************************************** //
//                                   deque                                    //
// ************************************************************************** //

static void insert_deque( std::deque<int> &dequarr, int left, int right ) {
	for (int index = left; index < right; index++) {
		int tmp_value = dequarr[index + 1];
		int jndex = index + 1;
		while (jndex > left && dequarr[jndex - 1] > tmp_value) {
			dequarr[jndex] = dequarr[jndex - 1];
			jndex--;
		}
		dequarr[jndex] = tmp_value;
	}
}

static void merge_deque( std::deque<int> &dequarr, int left, int mid, int right ) {
	int section1 = mid - left + 1;
	int section2 = right - mid;

	std::deque<int>::iterator it = dequarr.begin() + left;
	std::deque<int>::iterator itm = dequarr.begin() + mid;
	std::deque<int>::iterator ite = dequarr.begin() + right;
	std::deque<int> dequarr_left = std::deque<int>(it, itm + 1);
	std::deque<int> dequarr_right = std::deque<int>(itm + 1, ite + 1);
	int right_index = 0;
	int left_index = 0;
	for (int index = left; index < right + 1; index++) {
		if (right_index == section2) {
			dequarr[index] = dequarr_left[left_index];
			left_index++;
		} else if (left_index == section1) {
			dequarr[index] = dequarr_right[right_index];
			right_index++;
		} else if (dequarr_right[right_index] > dequarr_left[left_index]) {
			dequarr[index] = dequarr_left[left_index];
			left_index++;
		} else {
			dequarr[index] = dequarr_right[right_index];
			right_index++;
		}
	}
}

static void merge_sort_deque( std::deque<int> &dequarr, int left, int right )
{
	if (right - left > K_LIMIT) {
		int mid = (left + right) / 2;
		merge_sort_deque( dequarr, left, mid );
		merge_sort_deque( dequarr, mid + 1, right );
		merge_deque( dequarr, left, mid, right );
	} else {
		insert_deque( dequarr, left, right );
	}
}

void merge_insert_deque( char **args ) {
	clock_t a = clock();
	{
	std::deque<int> dequarr;

	for (int index = 1; args[index]; index++) {
		std::istringstream iss( args[index] );
		int toint;
		iss >> toint;
		dequarr.push_back( toint );
	}
	// std::cout << "before : ";
	// std::deque<int>::iterator it = dequarr.begin();
	// std::deque<int>::iterator ite = dequarr.end();
	// for (; it != ite; it++) {
	// 	std::cout << *it << " ";
	// }
	// std::cout << std::endl;
	clock_t sort_time = clock();
	merge_sort_deque( dequarr, 0, dequarr.size() - 1 );
	sort_time = clock() - sort_time;
	std::cout << "time with std::deque : " << ((float)sort_time * 1000) / CLOCKS_PER_SEC << std::endl;
	// std::cout << "after  : ";
	// it = dequarr.begin();
	// ite = dequarr.end();
	// for (; it != ite; it++) {
	// 	std::cout << *it << " ";
	// }
	// std::cout << std::endl;
	}
	a = clock() - a;
	std::cout << "total time with std::deque : " << ((float)a * 1000) / CLOCKS_PER_SEC << std::endl;
}

// ************************************************************************** //
//                                 Exceptions                                 //
// ************************************************************************** //

const char* InvalidInputException::what() const throw() {
	return ("[InvalidInputException] Input is invalid.");
}

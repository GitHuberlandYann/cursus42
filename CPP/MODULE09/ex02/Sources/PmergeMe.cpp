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

	int arr_left[section1];
	int arr_right[section2];

	for (int index = 0; index < section1; index++) {
		arr_left[index] = vect[index + left];
	}
	for (int index = 0; index < section2; index++) {
		arr_right[index] = vect[index + mid + 1];
	}
	int right_index = 0;
	int left_index = 0;
	for (int index = left; index < right + 1; index++) {
		if (right_index == section2) {
			vect[index] = arr_left[left_index];
			left_index++;
		} else if (left_index == section1) {
			vect[index] = arr_right[right_index];
			right_index++;
		} else if (arr_right[right_index] > arr_left[left_index]) {
			vect[index] = arr_left[left_index];
			left_index++;
		} else {
			vect[index] = arr_right[right_index];
			right_index++;
		}
	}
}

static void merge_sort_vector( std::vector<int> &vect, int left, int right )
{
	if (right - left > K_LIMIT) {
		int mid = (left + right) / 2;
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
	clock_t sort_time = clock();
	merge_sort_vector( vect, 0, vect.size() - 1 );
	sort_time = clock() - sort_time;
	std::cout << "/std::vector\\ time to sort : " << ((float)sort_time * 1000) / CLOCKS_PER_SEC << "ms, ";
	}
	a = clock() - a;
	std::cout << "total time : " << ((float)a * 1000) / CLOCKS_PER_SEC << "ms." << std::endl;
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

	int arr_left[section1];
	int arr_right[section2];

	for (int index = 0; index < section1; index++) {
		arr_left[index] = dequarr[index + left];
	}
	for (int index = 0; index < section2; index++) {
		arr_right[index] = dequarr[index + mid + 1];
	}
	int right_index = 0;
	int left_index = 0;
	for (int index = left; index < right + 1; index++) {
		if (right_index == section2) {
			dequarr[index] = arr_left[left_index];
			left_index++;
		} else if (left_index == section1) {
			dequarr[index] = arr_right[right_index];
			right_index++;
		} else if (arr_right[right_index] > arr_left[left_index]) {
			dequarr[index] = arr_left[left_index];
			left_index++;
		} else {
			dequarr[index] = arr_right[right_index];
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
	clock_t sort_time = clock();
	merge_sort_deque( dequarr, 0, dequarr.size() - 1 );
	sort_time = clock() - sort_time;
	std::cout << "/std::deque\\ time to sort : " << ((float)sort_time * 1000) / CLOCKS_PER_SEC << "ms, ";
	// std::cout << "after deque : ";
	// std::deque<int>::iterator it = dequarr.begin();
	// std::deque<int>::iterator ite = dequarr.end();
	// for (; it != ite; it++) {
	// 	std::cout << *it << " ";
	// }
	// std::cout << std::endl;
	}
	a = clock() - a;
	std::cout << "total time : " << ((float)a * 1000) / CLOCKS_PER_SEC << "ms." << std::endl;
}

// ************************************************************************** //
//                                 Exceptions                                 //
// ************************************************************************** //

const char* InvalidInputException::what() const throw() {
	return ("[InvalidInputException] Input is invalid.");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:09:23 by yhuberla          #+#    #+#             */
/*   Updated: 2023/04/17 13:09:23 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void RPN( std::string str ) {
	std::stack<int> rpn_stack;
	int tmp;

	for (int index = 0; str[index]; index++) {
		if (index & 1) {
			if (str[index] != ' ') {
				throw InvalidInputException();
			}
		} else if (isdigit( str[index] )) {
			rpn_stack.push( str[index] - '0' );
		} else {
			if (rpn_stack.size() < 2) {
				throw InvalidInputException();
			}
			switch ( str[index] ) {
				case '+':
					tmp = rpn_stack.top();
					rpn_stack.pop();
					rpn_stack.top() += tmp;
					break;
				case '-':
					tmp = rpn_stack.top();
					rpn_stack.pop();
					rpn_stack.top() -= tmp;
					break;
				case '*':
					tmp = rpn_stack.top();
					rpn_stack.pop();
					rpn_stack.top() *= tmp;
					break;
				case '/':
					tmp = rpn_stack.top();
					rpn_stack.pop();
					if (!tmp) {
						throw DivByZeroException();
					}
					rpn_stack.top() /= tmp;
					break;
				default:
					throw InvalidInputException();
			}
		}
	}
	if (rpn_stack.size() != 1) {
		throw BadStackSizeException();
	}
	std::cout << rpn_stack.top() << std::endl;
}

// ************************************************************************** //
//                                 Exceptions                                 //
// ************************************************************************** //

const char* InvalidInputException::what() const throw() {
	return ("[InvalidInputException] Input is invalid.");
}

const char* DivByZeroException::what() const throw() {
	return ("[DivByZeroException] Div by 0.");
}

const char* BadStackSizeException::what() const throw() {
	return ("[BadStackSizeException] Stack size not equal to 1 after operations.");
}

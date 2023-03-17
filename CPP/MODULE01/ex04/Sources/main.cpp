/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:37:50 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/17 10:10:31 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main( int ac, char **av ) {
	if (ac != 4) {
		std::cout << "Usage : ./replace <filename> s1 s2" << std::endl;
		return (1);
	}

	std::ifstream	infile(av[1]);
	if (!infile.is_open()) {
        std::cout << "failed to open " << av[1] << std::endl;
		return (1);
	}
	
	std::string	filename = av[1];
	filename.append(".replace");
	const char	*fname = filename.c_str();
	std::ofstream	outfile(fname);
	if (!outfile.is_open()) {
		std::cout << "failed to create " << fname << std::endl;
		infile.close();
		return (1);
	}

	std::string	src = av[2];
	std::string	dst = av[3];

	std::string	line;
	while (!infile.eof()) {
		std::getline(infile, line);
		for (size_t i = 0; i < line.size(); ++i) {
		if (!line.compare(i, src.size(), src)) {
			outfile << dst;
			i += src.size() - 1;
		} else {
			outfile << line[i];
		}
		}
		if (!infile.eof()) {
			outfile << std::endl;
		}
	}
	infile.close();
	outfile.close();
	return (0);
}

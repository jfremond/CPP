/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:38:56 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/05 22:09:08 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int	main(int argc, char **argv)
{
	std::string	s1;
	std::string	s2;
	std::string	outfile;
	std::string	buffer;
	std::string	write_outfile;
	size_t		s1_pos;
	
	if (check_args(argc))
		return (1);
	s1 = argv[2];
	s2 = argv[3];
	if (check_strings(s1, s2))
		return (1);
	std::ifstream 	ifs(argv[1]);
	if (check_infile(ifs, argv[1]))
		return (1);
	outfile = create_oufile(argv[1]);
	std::ofstream	ofs(outfile.c_str());
	if (check_outfile(ofs))
		return (1);
	while (!ifs.eof())
	{
		getline(ifs, buffer);
		s1_pos = buffer.find(s1);
		while (s1_pos != std::string::npos)
		{
			write_outfile = buffer.substr(0, s1_pos);
			ofs << write_outfile << s2;
			buffer.erase(0, s1_pos + s1.length());
			s1_pos = buffer.find(s1);
		}
		if (!ifs.eof())
			ofs << buffer << std::endl;
	}
	ofs.close();
	ifs.close();
	return (0);
}
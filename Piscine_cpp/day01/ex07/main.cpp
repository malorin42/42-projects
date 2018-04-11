/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 19:44:31 by malorin           #+#    #+#             */
/*   Updated: 2018/03/28 20:01:33 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string		capital(std::string filePath)
{
	std::string		tmp;
	size_t			i;

	i = 0;
	while (i < filePath.size())
	{
		tmp += toupper(filePath[i]);
		i++;
	}
	return (tmp);
}

void			ft_replace(std::string filePath, std::string s1, std::string s2)
{
	std::string 	text;
	std::string 	tmp;
	std::string		newFile;
	std::streampos	size;
	std::ofstream	fileReplaced;
	std::ifstream 	file;

	newFile = capital(filePath);
	newFile+= ".replace";
	fileReplaced.open(newFile);
	file.open(filePath);
	if (file.is_open())
	{
		file.seekg(0, std::ios::end);
		size = file.tellg();
		std::string	buffer(size, ' ');
		file.seekg(0, std::ios::beg);
		file.read(&buffer[0], size);
		while (buffer.find(s1) != (size_t)-1)
			buffer.replace(buffer.find(s1), s1.length(), s2);
		fileReplaced << buffer;
		file.close();
	}
	else
	{
		std::cout << "Error : The file was not found." << std::endl;
		return ;
	}
}

int				main(int argc, char **argv)
{
	std::string 	filePath;
	std::string 	s1;
	std::string		s2;

	if (argc != 4)
	{
		std::cout << "Error : Wrong number of argument ! " << std::endl;
		return (0);
	}
	filePath = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	if (filePath.empty() || s1.empty() || s2.empty())
	{
		std::cout << "Error : string(s) empty(s) !" << std::endl;
		return (0);
	}
	ft_replace(filePath, s1, s2);
	return (0);
}






// int main () {

//   std::ifstream ifs ("test.txt", std::ifstream::in);

//   char c = ifs.get();

//   while (ifs.good()) {
//     std::cout << c;
//     c = ifs.get();
//   }

//   ifs.close();

//   return 0;
// }

#include <iostream>
#include <fstream>
#include <string>

int	main(int ac, char **av)
{
	std::ifstream filename;
	std::string	s1;
	std::string	s2;
	std::ofstream outname;
	std::string out;
	std::string	str;

	s1 = av[2];
	s2 = av[3];
	int	s1_len;
	int	s2_len;
	s1_len = s1.length();
	s2_len = s2.length();

	if (ac != 4)
	{
		std::cout << " argument count err " << std::endl;
		return (1);
	}
	if (!s1_len || !s2_len)
	{
		std::cout << " length err " << std::endl;
		return (1);
	}
	filename.open(av[1]);
	if (filename.fail())
	{
		std::cout << " can't read infile " << std::endl;
		return (1);
	}
	out = av[1];
	out.append(".replace");
	outname.open(out);
	if (outname.fail())
	{
		std::cout << " can't read outfile " << std::endl;
		return (1);
	}
	while (!filename.eof())
	{
		std::getline(filename, str);
		size_t	s1_idx = 0;
		while (!filename.eof())
		{
			s1_idx = str.find(s1, s1_idx);
			if (s1_idx == std::string::npos)
				break ;
			str.erase(s1_idx, s1_len);
			str.insert(s1_idx, s2);
			s1_idx += s2_len;
		}
		outname << str << std::endl;
	}
	filename.close();
	outname.close();
}
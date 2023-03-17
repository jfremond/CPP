void	BitcoinExchange::_fillList(std::string filename)
{
	std::ifstream	file;
	file.open(filename.c_str());
	if (!file)
	{
		std::cout << "Error: cannot open file" << std::endl;
		return ;
	}
	std::string		line;
	std::string		bp;
	std::string		ap;
	size_t			pipe;
	while (!file.eof())
	{
		getline(file, line);
		pipe = line.find("|");
		if (pipe == 0)
			bp = " ";
		else
			bp = line.substr(0, pipe);
		if (pipe == std::string::npos)
			ap = "-42";
		else
			ap = line.substr(pipe + 1, line.length());
		if (!file.eof())
		{
			// std::cout << bp << "\t\t" << ap << std::endl;
			if (!bp.empty())
				_date.push_back(bp);
			if (!ap.empty())
				_value.push_back(atof(ap.c_str()));
			if (bp == "date ")
			{
				_date.pop_back();
				_value.pop_back();
			}
		}
	}
}
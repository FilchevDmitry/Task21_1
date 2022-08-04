#include <iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
struct Pay
{
	std::string f_name;
	std::string l_name;
	std::string data;
	int sum;
};
void print(std::vector<Pay>&payments)
{
	for (int j = 0; j < payments.size(); j++)
	{
		std::cout << payments[j].f_name << " " << payments[j].l_name << " " << payments[j].data << " " << payments[j].sum << std::endl;
	}
}
int main()
{	
	std::vector<Pay> payments;
	std::ifstream load("statement.txt");
	int i = 0;
	while (!load.eof())
	{
		payments.push_back(Pay());
		std::string text;
		std::getline(load, text);
		std::stringstream temp(text);
		temp >> payments[i].f_name >>payments[i].l_name>> payments[i].data >> payments[i].sum;
		i++;
	}
	print(payments);
	load.close();
}

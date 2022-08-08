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
void print(std::vector<Pay>& payments)
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
	if (load.is_open()) {
		while (!load.eof())
		{
			payments.push_back(Pay());
			std::string text;
			std::getline(load, text);
			std::stringstream temp(text);
			temp >> payments[i].f_name >> payments[i].l_name >> payments[i].data >> payments[i].sum;
			i++;
		}
	}
	else 
	{
		std::cout << "The file did not open"<<std::endl;
	}
	load.close();
	std::string option;
	std::cout << "Enter list to display the statement or add to enter data"<<std::endl;
	std::cin >> option;
	if (option == "list")
	{
		print(payments);
	}
	else if (option == "add")
	{
		std::string date;
		std::string f_name;
		std::string l_name;
		int sum = 0;
		std::cout << "Enter a name : ";
		std::cin>> f_name;
		std::cout << "Enter a last name : ";
		std::cin>>l_name;
		bool ok;
		do
		{
			std::cout << "Date : ";
			std::cin >> date;
			int a = stoi(date.substr(0, 2));
			int b = stoi(date.substr(3, 2));
			int c = stoi(date.substr(6, 4));
			if (a > 31 || b > 12 || c > 2025)
			{
				std::cout << "Error!!!!\n";
				ok = true;
			}
			else {
				ok = false;
			}
		} while (ok);
		std::cout << "Sum :";
		std::cin >> sum;
		payments.push_back(Pay());
		payments[i].f_name = f_name;
		payments[i].l_name = l_name;
		payments[i].data = date;
		payments[i].sum = sum;
		std::ofstream text("statement.txt", std::ios::app);
		text <<std::endl<< payments[i].f_name << " "<< payments[i].l_name <<" "<< payments[i].data << " " << payments[i].sum;
		text.close();
		print(payments);
	}
	else
	{
		std::cout << "Invalid input" << std::endl;
	}

}

#include <iostream>
#include <stdlib.h> 
using namespace std;


int BinToDec(string s)
{
	int i,j, sum;

		sum = 0;
    	for (i = s.length()-1, j=1 ; i >=0; i--, j*=2) 
    	{ 
			sum = sum + ((int)s[i]-(int)'0')*j ; 
			 
	    }
	

	return sum;
}

string DecToBin(int a, int l)
{
	string s;

	s.clear();
	if (a >= 0) 
	{
		while (a != 0) 
		{
			s = (char)((a % 2) + (int)'0') + s; 
			a = a / 2;
		}
		if (l <= s.length()) l = s.length() + 1; 
		s = string(l - s.length(), '0') + s; 
	}
	else
	{
		while (a != -1)
		{
			s = (char)((a % 2) + (int)'0') + s;
			a = a / 2;
		}
		if (l <= s.length()) l = s.length() + 1;
		s = string(l - s.length(), '1') + s;  
	}
	return s;
}

int main(int argc, char *argv[])
{	
	string s, t, v;
	int a, b, c;

	setlocale(LC_ALL, "Rus");
	if (argc < 6)
	{
		cout << "Бiнарний калькулятор \n";
		cout << " Функцiонал \n";
		cout << "add -f \"00111\" -s \"01111\" - додати 00111 i 01111\n";
		cout << "sub -f \"00111\" -s \"01111\" - вiдняти 00111 вiд 01111\n";
		cout << "mul -f \"00111\" -s \"01111\" - помножити 00111 на 01111\n";
		cout << "div -f \"00111\" -s \"01111\" - подiлити 00111 на 01111\n";
		cout << "Також можна використовувати десятичнi числа у дужках: add -f \"(7)\" -s \"(15)\"" << endl;
	}
	else
	{
		s = argv[2]; t = argv[4];
		if ((s == "-f") && (t == "-s"))
		{
			s = argv[3];
			t = argv[5];
		}
		else if ((s == "-s") && (t == "-f"))
		{
			s = argv[5];
			t = argv[3];
		}
		else
		{
			cout << " Не вказанi -f -s." << endl;
			system("pause");
			return 1;
		}
		if ((s.substr(0, 1) == "(") && (s.substr(s.length() - 1, 1) == ")")) 
		{
			a = atoi(s.substr(1, s.length() - 2).c_str());
			s = DecToBin(a, 0);
		}
		else
		{
			a = BinToDec(s);
		}
		if ((t.substr(0, 1) == "(") && (t.substr(t.length() - 1, 1) == ")"))
		{
			b = atoi(t.substr(1, t.length() - 2).c_str());
			t = DecToBin(b, 0);
		}
		else
		{
			b = BinToDec(t);
		}
		v = argv[1];
		if (v == "add")
		{
			c = a + b;
			v = DecToBin(c, 0);
			cout << s << " (" << a << ") + " << t << " (" << b << ") = " << v << " (" << c << ")" << endl;
		}
		else if (v == "sub")
		{
			c = a - b;
			v = DecToBin(c, 0);
			cout << s << " (" << a << ") - " << t << " (" << b << ") = " << v << " (" << c << ")" << endl;
		}
		else if (v == "mul")
		{
			c = a * b;
			v = DecToBin(c, 0);
			cout << s << " (" << a << ") * " << t << " (" << b << ") = " << v << " (" << c << ")" << endl;
		}
		else if (v == "div")
		{
			c = a / b;
			v = DecToBin(c, 0);
			cout << s << " (" << a << ") / " << t << " (" << b << ") = " << v << " (" << c << ")" << endl;
		}
		else
		{
			cout << "Помилка в командi. Не вказана add | sub | mul | div." << endl;
			system("pause");
			return 2;
		}
	}
	system("pause");
	return 0;
}

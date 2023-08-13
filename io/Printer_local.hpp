#pragma once

struct Printer
{
	template<typename T>
	void print(T x)
	{
		std::cout << x;
	}

	void putchar(char x)
	{
		putchar(x);
	}

	template<typename T>
	void println(T x)
	{
		std::cout << x << endl;
	}
};
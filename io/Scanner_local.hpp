#pragma once

struct Scanner
{
	template<typename T>
	void scan(T &x)
	{
		std::cin >> x;
	}

	template<typename... T>
	void scan(T& ...x)
	{
		((std::cin >> x), ...);
	}
};
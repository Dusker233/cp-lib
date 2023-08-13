#pragma once

template<typename T>
struct Fenwick
{
	const int n;
	std::vector<T> a;

	Fenwick(int _n) : n(_n), a(_n) {}

	void add(int x, T v)
	{
		for(int i = x;i <= n;i += i & -i)
			a[i] += v;
		return;
	}

	T sum(int x)
	{
		T Ans = 0;
		for(int i = x;i;i -= i & -i)
			Ans += a[i];
		return Ans;
	}

	T Rangesum(int l, int r) {return sum(r) - sum(l - 1);} // [l, r]
};
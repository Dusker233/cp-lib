#pragma once

template<typename T>
struct DSU
{
	std::vector<T> f, siz;

	DSU() {}
	DSU(int n) {init(n);}

	void init(int n)
	{
		f.resize(n);
		std::iota(f.begin(), f.end(), 0);
		siz.assign(n, 1);
	}

	T find(T x)
	{
		while(x != f[x])
			x = f[x] = f[f[x]];
		return x;
	}

	bool same(T x, T y) {return find(x) == find(y);}

	bool merge(T x, T y)
	{
		x = find(x);
		y = find(y);
		if(x == y)
			return false;
		siz[x] += siz[y];
		f[y] = x;
		return true;
	}

	T size(T x) {return siz[find(x)];}
};
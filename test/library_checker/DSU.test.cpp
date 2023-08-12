#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "my_template.hpp"
#include "data_structure/DSU.hpp"

int main()
{
	#ifdef ONLINE_JUDGE
	ioclear;
	#endif

	int n, q;
	std::cin >> n >> q;
	DSU<int> dsu(n + 10);
	for(int i = 1;i <= q;i++)
	{
		int t, u, v;
		std::cin >> t >> u >> v;
		if(t == 0)
			dsu.merge(u, v);
		else
			std::cout << (dsu.same(u, v) ? 1 : 0) << endl;
	}
}
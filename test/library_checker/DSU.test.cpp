#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "head.hpp"
#include "data_structure/DSU.hpp"
#include "io/Scanner.hpp"
#include "io/Printer.hpp"

Scanner scanner;
Printer printer;

int main()
{
	#ifdef ONLINE_JUDGE
	ioclear;
	#endif

	int n, q;
	scanner.scan(n, q);
	DSU<int> dsu(n + 10);
	for(int i = 1;i <= q;i++)
	{
		int t, u, v;
		scanner.scan(t, u, v);
		if(t == 0)
			dsu.merge(u, v);
		else
			printer.print(dsu.same(u, v)), printer.putchar('\n');
	}
}
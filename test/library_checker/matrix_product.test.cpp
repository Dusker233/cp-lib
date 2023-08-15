#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"
#include "head.hpp"
#include "math/modint.hpp"
#include "math/matrix.hpp"
#include "io/Scanner.hpp"
#include "io/Printer.hpp"

Scanner scanner;
Printer printer;

int main()
{
	ioclear;
	int n, m, k;
	scanner.scan(n, m, k);
	std::vector<std::vector<Z>> a(n + 1, std::vector<Z>(m + 1)), b(m + 1, std::vector<Z>(k + 1));
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
		{
			i64 x;
			scanner.scan(x);
			a[i][j] = x;
		}
	for(int i = 1;i <= m;i++)
		for(int j = 1;j <= k;j++)
		{
			i64 x;
			scanner.scan(x);
			b[i][j] = x;
		}
	matrix<Z> A(n, m, a), B(m, k, b);
	A *= B;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= k;j++)
			printer.print(A.m[i][j].val()), printer.putchar(' ');
		printer.putchar('\n');
	}
}
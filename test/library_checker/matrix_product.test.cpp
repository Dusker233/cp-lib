#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"
#include "head.hpp"
#include "math/matrix.hpp"
#include "io/Scanner.hpp"
#include "io/Printer.hpp"

Scanner scanner;
Printer printer;

int main()
{
	int n, m, k;
	scanner.scan(n, m, k);
	std::vector<std::vector<i64>> a(n + 1, std::vector<i64>(m + 1)), b(m + 1, std::vector<i64>(k + 1));
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			scanner.scan(a[i][j]);
	for(int i = 1;i <= m;i++)
		for(int j = 1;j <= k;j++)
			scanner.scan(b[i][j]);
	matrix<i64> A(n, m, a, 998244353ll), B(m, k, b, 998244353ll);
	A *= B;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= k;j++)
			printer.print(A.m[i][j]), printer.putchar(' ');
		printer.putchar('\n');
	}
}
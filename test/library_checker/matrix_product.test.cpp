#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"
#include "head.hpp"
#include "math/modint.hpp"
#include "math/matrix.hpp"

int main()
{
	ioclear;
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<std::vector<Z>> a(n + 1, std::vector<Z>(m + 1)), b(m + 1, std::vector<Z>(k + 1));
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			std::cin >> a[i][j];
	for(int i = 1;i <= m;i++)
		for(int j = 1;j <= k;j++)
			std::cin >> b[i][j];
	matrix<Z> A(n, m, a), B(m, k, b);
	A *= B;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= k;j++)
			std::cout << A.m[i][j] << " \n"[j == k];
}
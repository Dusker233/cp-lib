#define PROBLEM "https://yukicoder.me/problems/no/1750"
#include "head.hpp"
#include "math/matrix.hpp"
#include "io/Scanner.hpp"
#include "io/Printer.hpp"

Scanner scanner;
Printer printer;

int main()
{
	int n, m;
	i64 T;
	scanner.scan(n, m, T);
	matrix<i64> a(n, n);
	for(int i = 1;i <= m;i++)
	{
		int s, t;
		scanner.scan(s, t);
		s++, t++;
		a.m[s][t] = a.m[t][s] = 1;
	}
	a = a.pow(T);
	printer.println(a.m[1][1]);
}
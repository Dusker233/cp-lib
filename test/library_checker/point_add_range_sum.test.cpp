#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "head.hpp"
#include "data_structure/1D-fenwick.hpp"
#include "io/Scanner.hpp"
#include "io/Printer.hpp"

using i64 = long long;
constexpr int mmax = 5E5 + 10;

Scanner scanner;
Printer printer;
Fenwick<i64> fenwick(mmax);

int main()
{
    i64 n, q;
    scanner.scan(n, q);
    
    for(int i = 1;i <= n;i++)
    {
            i64 x;
            scanner.scan(x);
            fenwick.add(i, x);
    }
    for(int i = 1;i <= q;i++)
    {
            i64 op, l, r;
            scanner.scan(op, l, r);
            if(op == 0)
                    fenwick.add(++l, r);
            else
                    printer.print(fenwick.Rangesum(++l, r)), printer.putchar('\n');
    }
}
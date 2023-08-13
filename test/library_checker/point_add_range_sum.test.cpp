#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "head.hpp"
#include "data_structure/1D-fenwick.hpp"
#include "io/Scanner.hpp"
#include "io/Printer.hpp"

Scanner scanner;
Printer printer;

int main()
{
    int n, q;
    scanner.scan(n, q);
    Fenwick<int> fenwick(n);
    for(int i = 1;i <= n;i++)
    {
            int x;
            scanner.scan(x);
            fenwick.add(i, x);
    }
    for(int i = 1;i <= q;i++)
    {
            int op, l, r;
            scanner.scan(op, l, r);
            if(op == 0)
                    fenwick.add(++l, r);
            else
                    printer.print(fenwick.Rangesum(++l, r)), printer.putchar('\n');
    }
}
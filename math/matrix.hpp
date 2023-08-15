#pragma once

template<typename T>
struct matrix
{
	int row, col;
	std::vector<std::vector<T>> m;
	matrix(int r, int c, int val): row(r), col(c), m(row + 1, std::vector<T>(col + 1, val)) {}
    matrix(int r, int c, std::vector<std::vector<T>> _m): row(r), col(c), m(_m) {}
	 matrix operator *= (const matrix &rhs)
	 {
	 	assert(col == rhs.row);
	 	std::vector<std::vector<T>> tmp(row + 1, std::vector<T>(rhs.col + 1, 0));
	 	for(int k = 1;k <= col;k++)
	 		for(int i = 1;i <= row;i++)
	 			for(int j = 1;j <= rhs.col;j++)
	 				tmp[i][j] += m[i][k] * rhs.m[k][j];
	 	m = tmp;
	 	return *this;
	 }
	friend matrix operator *(const matrix &lhs, const matrix &rhs)
	{
		assert(lhs.col == rhs.row);
        matrix res = lhs;
        res *= rhs;
        return res;
	}
};

matrix<int> pow(int k, matrix<int> m)
{
    k--;
	matrix<int> Ans = m;
	while(k)
	{
		if(k & 1)
			Ans *= m;
		m *= m;
		k >>= 1;
	}
	return Ans;
}
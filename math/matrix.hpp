#pragma once

using i64 = long long;
constexpr i64 P = 998244353;
constexpr int mmax = 2000;

template<typename T>
struct matrix
{
	int row, col;
	i64 m[mmax][mmax];
	matrix(int r, int c, int val): row(r), col(c)
	{
		memset(m, 0, sizeof(m));
		for(int i = 1;i <= row;i++)
			for(int j = 1;j <= col;j++)
				m[i][j] = val;
	}
    matrix(int r, int c, std::vector<std::vector<T>> _m): row(r), col(c)
    {
    	memset(m, 0, sizeof(m));
		for(int i = 1;i <= row;i++)
			for(int j = 1;j <= col;j++)
				m[i][j] = _m[i][j];
    }
	 matrix operator *= (const matrix &rhs)
	 {
	 	assert(col == rhs.row);
	 	i64 tmp[mmax][mmax];
	 	for(int k = 1;k <= col;k++)
	 		for(int i = 1;i <= row;i++)
	 			for(int j = 1;j <= rhs.col;j++)
	 				tmp[i][j] = (tmp[i][j] + ((m[i][k] * rhs.m[k][j]))) % P;
	 	memcpy(m, tmp, sizeof(tmp));
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
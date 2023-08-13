#pragma once

class Printer
{
public:
	Printer(std::FILE *f = stdout, std::size_t buffer_size = 100000)
		: f_(f), buffer_(new char[buffer_size + 32]), buffer_head_(buffer_),
		  buffer_end_(buffer_ + buffer_size + 32), stk_(new char[32]), top_(stk_) {}
	~Printer()
	{
		flush();
		delete[] stk_;
		delete[] buffer_;
	}

	void flush()
	{
		std::fwrite(buffer_, buffer_head_ - buffer_, sizeof(char), f_);
		buffer_head_ = buffer_;
	}

	void putchar(char x)
	{
		if(buffer_end_ == buffer_head_)
			flush();
		*buffer_head_++ = x;
	}

	template<typename T>
	std::enable_if_t<std::is_integral_v<T> && !std::is_same_v<T, char> && std::is_signed_v<T>, void>
	print(T x)
	{
		if(x == 0)
			return this->putchar('0');
		if(x < 0)
		{
			putchar('-');
			do
			{
				T y = x / 10;
				*top_++ = y * 10 - x + '0';
				x = y;
			} while(x != 0);
		}
		else
		{
			do
			{
				T y = x / 10;
				*top_++ = x - y * 10 + '0';
				x = y;
			} while(x != 0);
		}
		if(buffer_end_ - buffer_head_ < top_ - stk_)
			flush();
		while(top_ != stk_) *buffer_head_++ = *--top_;
	}

	void print(char x) {return this->putchar(x);}

	template<typename T>
	std::enable_if_t<std::is_integral_v<T> && !std::is_same_v<T, char> && std::is_unsigned_v<T>, void>
	print(T x)
	{
		if(x == 0)
			return this->putchar('0');
		do
		{
			T y = x / 10;
			*top_++ = x - y * 10 + '0';
			x = y;
		} while(x != 0);
		if(buffer_end_ - buffer_head_ < top_ - stk_)
			flush();
		while(top_ != stk_) *buffer_head_++ = *--top_;
	}

	template<typename... T>
	void print(T... x)
	{
		return (..., print(x));
	}

	template<typename T>
	void println(T x)
	{
		return this->print(x), this->putchar('\n');
	}

private:
	std::FILE *f_;
	char *buffer_, *buffer_head_, *buffer_end_, *stk_, *top_;
};
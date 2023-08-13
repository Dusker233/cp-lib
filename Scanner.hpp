#pragma once

class Scanner
{
public:
	Scanner(std::FILE *f = stdin, std::size_t enough_buffer_size = 1 << 25)
		: f_(f), buffer_(new char[enough_buffer_size + 32]), buffer_head_(buffer_),
		  buffer_tail_(buffer_ + std::fread(buffer_, sizeof(char), enough_buffer_size + 32, f_)) {*buffer_tail_ = '\0';}
	~Scanner() {delete[] buffer_;}
	
	template<typename T>
	std::enable_if_t<std::is_integral_v<T> && !std::is_same_v<T, char> && std::is_signed_v<T>, bool>
	scan(T &x)
	{
		x = 0;
		while(*buffer_head_ != '-' && std::isspace(*buffer_head_))
			++buffer_head_;
		bool is_neg = *buffer_head_ == '-' && ++buffer_head_;
		char *old_buffer_head = buffer_head_;
		if(is_neg)
			while(std::isdigit(*buffer_head_)) x = x * 10 - (*buffer_head_++ - '0');
		else
			while(std::isdigit(*buffer_head_)) x = x * 10 + (*buffer_head_++ - '0');
		return buffer_head_ != old_buffer_head;
	}  

	template<typename... T>
	bool scan(T &...x)
	{
		return (... && scan(x));
	}

private:
	std::FILE *f_;
	char *buffer_, *buffer_head_, *buffer_tail_;
};
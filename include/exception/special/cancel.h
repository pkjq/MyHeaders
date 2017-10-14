#ifndef G63D0D501_BE38_4BDD_8953_BB2423AA47CD
#define G63D0D501_BE38_4BDD_8953_BB2423AA47CD


#include <exception>


namespace special_exception
{
class cancel_exception: public std::runtime_error
{
	using _Mybase = std::runtime_error;

public:
	cancel_exception(): _Mybase("cancel") {}
};
}


#endif//G63D0D501_BE38_4BDD_8953_BB2423AA47CD

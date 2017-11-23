#ifndef G9EC3F86D_1B76_43A4_A83A_BEDD12291909
#define G9EC3F86D_1B76_43A4_A83A_BEDD12291909


#include <functional>


namespace scoped
{
class FunctionCall final
{
	using AtEnterFuncType	= void();
	using AtExitFuncType	= void();

public:
	FunctionCall(const FunctionCall&)				= delete;
	FunctionCall& operator =(const FunctionCall&)	= delete;

	FunctionCall(FunctionCall&&)					= delete;
	FunctionCall& operator =(FunctionCall&&)		= delete;

public:
	explicit FunctionCall(std::function<AtEnterFuncType> enterFunc, std::function<AtExitFuncType> exitFunc):
		exitFunc(std::move(exitFunc))
	{
		enterFunc();
	}

	~FunctionCall()
	{
		exitFunc();
	}
	
private:
	const std::function<AtExitFuncType> exitFunc;
};
}


#endif//G9EC3F86D_1B76_43A4_A83A_BEDD12291909

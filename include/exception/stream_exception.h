#ifndef G3B7CF49D_C07B_4610_8CFE_3FF1EFDA8A67
#define G3B7CF49D_C07B_4610_8CFE_3FF1EFDA8A67


#include <exception>
#include <stdexcept>
#include <system_error> // system_error
#include <typeinfo> 	// bad_typeid
#include <memory>		// bad_weak_ptr
#include <functional>	// bad_function_call
#include <sstream>


namespace stream_exception
{
template <typename BaseExeption>
class StreamExceptionT: public BaseExeption
{
public:
	StreamExceptionT(int line, const char *function): BaseExeption("<undefined>")
	{
		stream << "[" << function << ":" << line << "]: ";
		CorrectBaseException();
	}

	StreamExceptionT(const StreamExceptionT&) = delete;

	StreamExceptionT(StreamExceptionT &&se):
		BaseExeption(se),
		//stream(std::move(se.stream)) 	// stringstream в этой версии не умеет move :(
		stream(se.stream.str()) 		// TODO: fix this
	{}

public:
	template <typename T>
	inline StreamExceptionT&& operator<<(T &&data) &&
	{
		stream << data;
		CorrectBaseException();

		return std::move(*this);
	}

	template <typename T>
	inline StreamExceptionT& operator<<(T &&data) &
	{
		stream << data;
		CorrectBaseException();

		return *this;
	}

private:
	inline void CorrectBaseException()
	{
		static_cast<BaseExeption&>(*this) = std::move(BaseExeption(stream.str().c_str()));
	}

private:
	std::stringstream stream;
};


using StreamLogicError 				= StreamExceptionT<std::logic_error>;
	using StreamInvalidArgument 		= StreamExceptionT<std::invalid_argument>;
	using StreamDomainError 			= StreamExceptionT<std::domain_error>;
	using StreamLengthError 			= StreamExceptionT<std::length_error>;
	using StreamOutOfRange 				= StreamExceptionT<std::out_of_range>;

using StreamRuntimeError 			= StreamExceptionT<std::runtime_error>;
	using StreamRangeError 				= StreamExceptionT<std::range_error>;
	using StreamOverflowError 			= StreamExceptionT<std::overflow_error>;
	using StreamUnderflowError 			= StreamExceptionT<std::underflow_error>;
	using StreamSystemError 			= StreamExceptionT<std::system_error>;


using StreamBadTypeid  				= StreamExceptionT<std::bad_typeid>;
using StreamBadCast  				= StreamExceptionT<std::bad_cast>;
using StreamBadWeakPtr  			= StreamExceptionT<std::bad_weak_ptr>;
using StreamBadFunctionCall  		= StreamExceptionT<std::bad_function_call>;
using StreamBadAlloc  				= StreamExceptionT<std::bad_alloc>;
using StreamBadArrayNewLength 		= StreamExceptionT<std::bad_array_new_length>;
using StreamBadException  			= StreamExceptionT<std::bad_exception>;
using StreamBadAlloc  				= StreamExceptionT<std::bad_alloc>;
}



#endif//G3B7CF49D_C07B_4610_8CFE_3FF1EFDA8A67

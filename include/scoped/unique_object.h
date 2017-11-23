#ifndef G365E3467_5201_4644_9E0C_FCC0F1AEFC3B
#define G365E3467_5201_4644_9E0C_FCC0F1AEFC3B


#include <functional>


namespace scoped
{
template <typename Type, typename CloseFuncType>
class unique_object final
{
public:
	explicit unique_object(Type &&object, std::function<CloseFuncType> closeFunc):
		object(std::move(object)), closeFunc(std::move(closeFunc)), valid(true)
	{}

	explicit unique_object(std::function<CloseFuncType> closeFunc):
		closeFunc(std::move(closeFunc))
	{}
	
	~unique_object()
	{
		if (valid)
			closeFunc(object);
	}
	
	unique_object(const unique_object&) = delete;

	unique_object(unique_object &&obj) noexcept
	{
		if (!obj.valid)
			return;

		obj.valid 	= false;

		object	  	= std::move(obj.object);
		closeFunc 	= std::move(obj.closeFunc);
		valid 		= true;
	}

	unique_object& operator= (const unique_object&) = delete;

	unique_object& operator= (unique_object &&obj) noexcept
	{
		std::swap(object, 		obj.object);
		std::swap(closeFunc, 	obj.closeFunc);
		std::swap(valid, 		obj.valid);

		return *this;
	}

public:
	inline Type get() const
	{
		if (valid)
			return object;
		throw std::runtime_error("object is invalid");
	}

	inline void reset()
	{
		if (!valid)
			return;

		closeFunc(object);
		valid = false;
	}

	inline void reset(Type obj)
	{
		if (valid)
			closeFunc(object);

		object 	= std::move(obj);
		valid 	= true;
	}

private:
	Type object {};
	std::function<CloseFuncType> closeFunc;
	bool valid = false;
};
}


#endif//G365E3467_5201_4644_9E0C_FCC0F1AEFC3B

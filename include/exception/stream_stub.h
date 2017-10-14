#ifndef GFF0BA0F7_40D8_4F6D_BED5_C14289015267
#define GFF0BA0F7_40D8_4F6D_BED5_C14289015267


namespace stream_exception
{
class StreamStub
{
public:
	StreamStub() = default;
	StreamStub(StreamStub &&se) = default;

	StreamStub(const StreamStub&) = delete;

public:
	template <typename T>
	inline StreamStub&& operator<<(T&&) &&
	{
		return std::move(*this);
	}

	template <typename T>
	inline StreamStub& operator<<(T&&) &
	{
		return *this;
	}
};
}


#endif//GFF0BA0F7_40D8_4F6D_BED5_C14289015267

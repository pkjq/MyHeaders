#ifndef GA68E7B78_CAA4_46C9_A286_81082A73EBBC
#define GA68E7B78_CAA4_46C9_A286_81082A73EBBC


#include <exception/stream_exception.h>
#include <exception/stream_stub.h>


#define UNUSED_PARAM(param) (void)((param))


#define THROW_IF_NOT_EXPRESSION(expression) \
	for (;!(expression);) \
		throw stream_exception::StreamRuntimeError(__LINE__, __FUNCTION__)

#define CHECK(expression) 		THROW_IF_NOT_EXPRESSION((expression)) << "[CHECK]: "
#define INVARIANT(expression) 	THROW_IF_NOT_EXPRESSION((expression)) << "[INVARIANT]: "
#define REQUIRE(expression) 	THROW_IF_NOT_EXPRESSION((expression)) << "[REQUIRE]: "
#define EXPECT(expression) 		THROW_IF_NOT_EXPRESSION((expression)) << "[EXPECT]: "
		


#ifdef DEBUG
	#define DEBUG_CHECK(expression) CHECK((expression))

	#define DEBUG_THROW() throw stream_exception::StreamRuntimeError(__LINE__, __FUNCTION__)
#else
	#define DEBUG_CHECK(expression) UNUSED_PARAM((expression)), stream_exception::StreamStub()

	#define DEBUG_THROW() stream_exception::StreamStub()
#endif


#endif//GA68E7B78_CAA4_46C9_A286_81082A73EBBC

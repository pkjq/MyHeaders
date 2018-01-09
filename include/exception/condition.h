#ifndef GA68E7B78_CAA4_46C9_A286_81082A73EBBC
#define GA68E7B78_CAA4_46C9_A286_81082A73EBBC


#include <exception/stream_exception.h>
#include <exception/stream_stub.h>


#define UNUSED_PARAM(param) (void)((param))


#define THROW_IF_NOT_EXPRESSION_EX(expression, StreamExceptionClass) \
	for (;!(expression);) \
		throw StreamExceptionClass(__LINE__, __FUNCTION__)

#define CHECK_EX(expression, StreamExceptionClass) 		THROW_IF_NOT_EXPRESSION_EX((expression), StreamExceptionClass) << "[CHECK]: "
#define INVARIANT_EX(expression, StreamExceptionClass) 	THROW_IF_NOT_EXPRESSION_EX((expression), StreamExceptionClass) << "[INVARIANT]: "
#define REQUIRE_EX(expression, StreamExceptionClass)	THROW_IF_NOT_EXPRESSION_EX((expression), StreamExceptionClass) << "[REQUIRE]: "
#define EXPECT_EX(expression, StreamExceptionClass) 	THROW_IF_NOT_EXPRESSION_EX((expression), StreamExceptionClass) << "[EXPECT]: "
		
#define CHECK(expression) 								CHECK_EX((expression),		stream_exception::StreamRuntimeError)
#define INVARIANT(expression) 							INVARIANT_EX((expression),	stream_exception::StreamRuntimeError)
#define REQUIRE(expression) 							REQUIRE_EX((expression),	stream_exception::StreamRuntimeError)
#define EXPECT(expression) 								EXPECT_EX((expression),		stream_exception::StreamRuntimeError)


#ifdef DEBUG
	#define DEBUG_CHECK(expression) CHECK((expression))

	#define DEBUG_THROW() throw stream_exception::StreamRuntimeError(__LINE__, __FUNCTION__)
#else
	#define DEBUG_CHECK(expression) UNUSED_PARAM((expression)), stream_exception::StreamStub()

	#define DEBUG_THROW() stream_exception::StreamStub()
#endif


#endif//GA68E7B78_CAA4_46C9_A286_81082A73EBBC

#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER fib_app

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./tp.h"

#if !defined(_TP_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define _TP_H
#include <lttng/tracepoint.h>

LTTNG_UST_TRACEPOINT_EVENT(
	fib_app,
	call,
	LTTNG_UST_TP_ARGS(
		int, n
	),
	LTTNG_UST_TP_FIELDS(
		lttng_ust_field_integer(int, value, n)
	)
)

#endif
#include <lttng/tracepoint-event.h>

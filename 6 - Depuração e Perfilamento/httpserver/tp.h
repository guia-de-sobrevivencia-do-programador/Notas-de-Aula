#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER httpservertp

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./tp.h"

#if !defined(_TP_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define _TP_H

#include <lttng/tracepoint.h>

LTTNG_UST_TRACEPOINT_EVENT(
	httpservertp,
	file_read,
	LTTNG_UST_TP_ARGS(
		const char *, filepath,
		size_t, filesize
	),
	LTTNG_UST_TP_FIELDS(
		lttng_ust_field_string(filepath, filepath)
		lttng_ust_field_integer(size_t, filesize, filesize)
	)
)

LTTNG_UST_TRACEPOINT_EVENT(
	httpservertp,
	file_write,
	LTTNG_UST_TP_ARGS(
		const char *, filepath,
		size_t, filesize
	),
	LTTNG_UST_TP_FIELDS(
		lttng_ust_field_string(filepath, filepath)
		lttng_ust_field_integer(size_t, filesize, filesize)
	)
)

LTTNG_UST_TRACEPOINT_EVENT(
	httpservertp,
	network_recv,
	LTTNG_UST_TP_ARGS(
		size_t, size
	),
	LTTNG_UST_TP_FIELDS(
		lttng_ust_field_integer(size_t, size, size)
	)
)

LTTNG_UST_TRACEPOINT_EVENT(
	httpservertp,
	network_send,
	LTTNG_UST_TP_ARGS(
		size_t, size
	),
	LTTNG_UST_TP_FIELDS(
		lttng_ust_field_integer(size_t, size, size)
	)
)

#endif
#include <lttng/tracepoint-event.h>

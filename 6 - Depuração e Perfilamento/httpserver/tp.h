#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER httpservertp

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./tp.h"

#if !defined(_TP_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define _TP_H

#include <lttng/tracepoint.h>

LTTNG_UST_TRACEPOINT_EVENT(
	httpservertp,
	file_read_start,
	LTTNG_UST_TP_ARGS(
		const char *, filepath
	),
	LTTNG_UST_TP_FIELDS(
		lttng_ust_field_string(filepath, filepath)
	)
)

LTTNG_UST_TRACEPOINT_EVENT(
	httpservertp,
	file_read_end,
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
	file_write_start,
	LTTNG_UST_TP_ARGS(
		const char *, filepath
	),
	LTTNG_UST_TP_FIELDS(
		lttng_ust_field_string(filepath, filepath)
	)
)

LTTNG_UST_TRACEPOINT_EVENT(
	httpservertp,
	file_write_end,
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
	network_recv_start,
	LTTNG_UST_TP_ARGS(),
	LTTNG_UST_TP_FIELDS()
)

LTTNG_UST_TRACEPOINT_EVENT(
	httpservertp,
	network_recv_end,
	LTTNG_UST_TP_ARGS(
		size_t, size
	),
	LTTNG_UST_TP_FIELDS(
		lttng_ust_field_integer(size_t, size, size)
	)
)

LTTNG_UST_TRACEPOINT_EVENT(
	httpservertp,
	network_send_start,
	LTTNG_UST_TP_ARGS(),
	LTTNG_UST_TP_FIELDS()
)

LTTNG_UST_TRACEPOINT_EVENT(
	httpservertp,
	network_send_end,
	LTTNG_UST_TP_ARGS(
		size_t, size
	),
	LTTNG_UST_TP_FIELDS(
		lttng_ust_field_integer(size_t, size, size)
	)
)

#endif
#include <lttng/tracepoint-event.h>

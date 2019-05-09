#include <limits.h>
#include "options.h"
#define C(n) switch(n){case n:;}
static void f()
{
#ifdef __wasilibc_unmodified_upstream // WASI has no embedded shell commands
C(BC_BASE_MAX)
C(BC_DIM_MAX)
C(BC_SCALE_MAX)
C(BC_STRING_MAX)
#endif
C(CHARCLASS_NAME_MAX)
C(COLL_WEIGHTS_MAX)
#ifdef __wasilibc_unmodified_upstream // WASI has no embedded shell commands
C(EXPR_NEST_MAX)
C(LINE_MAX)
#endif
C(NGROUPS_MAX)
C(RE_DUP_MAX)
C(_POSIX_CLOCKRES_MIN)
C(_POSIX_AIO_LISTIO_MAX)
C(_POSIX_AIO_MAX)
C(_POSIX_ARG_MAX)
C(_POSIX_CHILD_MAX)
C(_POSIX_DELAYTIMER_MAX)
C(_POSIX_HOST_NAME_MAX)
C(_POSIX_LINK_MAX)
C(_POSIX_LOGIN_NAME_MAX)
C(_POSIX_MAX_CANON)
C(_POSIX_MAX_INPUT)
#ifdef POSIX_MESSAGE_PASSING
C(_POSIX_MQ_OPEN_MAX)
C(_POSIX_MQ_PRIO_MAX)
#endif
C(_POSIX_NAME_MAX)
C(_POSIX_NGROUPS_MAX)
C(_POSIX_OPEN_MAX)
C(_POSIX_PATH_MAX)
C(_POSIX_PIPE_BUF)
C(_POSIX_RE_DUP_MAX)
C(_POSIX_RTSIG_MAX)
C(_POSIX_SEM_NSEMS_MAX)
C(_POSIX_SEM_VALUE_MAX)
C(_POSIX_SIGQUEUE_MAX)
C(_POSIX_SSIZE_MAX)
#if defined(POSIX_SPORADIC_SERVER) || defined(POSIX_THREAD_SPORADIC_SERVER)
C(_POSIX_SS_REPL_MAX)
#endif
C(_POSIX_STREAM_MAX)
C(_POSIX_SYMLINK_MAX)
C(_POSIX_SYMLOOP_MAX)
C(_POSIX_THREAD_DESTRUCTOR_ITERATIONS)
C(_POSIX_THREAD_KEYS_MAX)
C(_POSIX_THREAD_THREADS_MAX)
C(_POSIX_TIMER_MAX)
C(_POSIX_TTY_NAME_MAX)
C(_POSIX_TZNAME_MAX)
C(_POSIX2_BC_BASE_MAX)
C(_POSIX2_BC_DIM_MAX)
C(_POSIX2_BC_SCALE_MAX)
C(_POSIX2_BC_STRING_MAX)
C(_POSIX2_CHARCLASS_NAME_MAX)
C(_POSIX2_COLL_WEIGHTS_MAX)
C(_POSIX2_EXPR_NEST_MAX)
C(_POSIX2_LINE_MAX)
#ifdef _XOPEN_SOURCE
C(_XOPEN_IOV_MAX)
C(_XOPEN_NAME_MAX)
C(_XOPEN_PATH_MAX)
#endif
C(CHAR_BIT)
C(CHAR_MAX)
C(CHAR_MIN)
C(INT_MAX)
C(INT_MIN)
C(LLONG_MAX)
C(LLONG_MIN)
C(LONG_BIT)
C(LONG_MAX)
C(LONG_MIN)
C(MB_LEN_MAX)
C(SCHAR_MAX)
C(SCHAR_MIN)
C(SHRT_MAX)
C(SHRT_MIN)
C(SSIZE_MAX)
C(UCHAR_MAX)
C(UINT_MAX)
C(ULLONG_MAX)
C(ULONG_MAX)
C(USHRT_MAX)
C(WORD_BIT)
C(NL_ARGMAX)
#ifdef _XOPEN_SOURCE
C(NL_LANGMAX)
#endif
C(NL_MSGMAX)
C(NL_SETMAX)
C(NL_TEXTMAX)
#ifdef _XOPEN_SOURCE
C(NZERO)
#endif
}

/**
 * Debug output macros for frank-386
 *
 * Use DBG_PRINT for informational debug messages that should only
 * appear when DEBUG_ENABLED=1 is set at compile time.
 *
 * Use printf directly for critical errors that should always be shown.
 */

#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>

#ifdef USB_CONSOLE_DEBUG
#include "pico/stdlib.h"

/* Time given to the USB stack to get a message to the host before the
 * firmware moves on to something that might crash. */
#ifndef USB_CONSOLE_FLUSH_MS
#define USB_CONSOLE_FLUSH_MS 20
#endif

#define DBG_PRINT(...) do { \
        printf(__VA_ARGS__); \
        stdio_flush(); \
        sleep_ms(USB_CONSOLE_FLUSH_MS); \
    } while (0)
#elif defined(DEBUG_ENABLED)
#define DBG_PRINT(...) printf(__VA_ARGS__)
#else
#define DBG_PRINT(...) ((void)0)
#endif

#endif /* DEBUG_H */

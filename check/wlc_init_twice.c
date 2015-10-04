#include <stdio.h>
#include <stdlib.h>
#include <wlc/wlc.h>

static void logger(enum wlc_log_type type, const char *str) {
    printf("%s\n", str);
}

int
main(int argc, char *argv[])
{
    wlc_log_set_handler(logger);

    struct wlc_interface dummy0 = {0};
    wlc_init(&dummy0, argc, argv);

    struct wlc_interface dummy1 = {0};
    wlc_init(&dummy1, argc, argv);
}

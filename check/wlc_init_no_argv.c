#include <stdio.h>
#include <wlc/wlc.h>

static void logger(enum wlc_log_type type, const char *str) {
    printf("%s\n", str);
}

int
main(int argc, char *argv[])
{
    wlc_log_set_handler(logger);

    struct wlc_interface dummy = {0};
    wlc_init(&dummy, argc, 0);
}

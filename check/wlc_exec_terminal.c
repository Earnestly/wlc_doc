#include <stdio.h>
#include <stdlib.h>
#include <wlc/wlc.h>

static void logger(enum wlc_log_type type, const char *str) {
    printf("%s\n", str);
}

int
main(void)
{
    wlc_log_set_handler(logger);

    char *terminal = getenv("TERMINAL");
    wlc_exec(terminal, (char* const*)0);
}

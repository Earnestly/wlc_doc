#!/bin/dash

delay=3s

flags=$(pkg-config --libs --cflags wlc)

compile() {
    local o=$1
    printf '\033[1;30mCOMPILE\033[0m %s\n' "$o".c >&2
    gcc $flags "$o".c -o "$o"
}

execute() {
    local o=$1
    local e r
    printf '\033[1;32m\033[2;32mEXECUTE\033[0m %s\n' "$o" >&2
    e=$(timeout --preserve-status $delay ./"$o")
    r=$?
    case $r in
        0)   return ;;
        143) printf '\033[1;33mTIMEOUT\033[0m %s\n' "$o" ;;
        *)   printf '\033[1;31mFAILURE\033[0m %s: %s (%d)\n' "$o" "$e" $r ;;
    esac
}

check() {
    local o=$1
    o=${o%*.c}
    if compile "$o"; then
        execute "$o"
    fi
}

for s in "$@"; do
    case $s in
        *.c) (check "$s")& ;;
    esac
done

# Wait until all checks have completed and all timeouts triggered before
# returning the users prompt to avoid clobbering it.
wait

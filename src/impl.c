#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "impl.h"

void initialize()
{
    if (initialized)
        return;

    initialized = true;
}

void destroy()
{
    if (!initialized)
        return;

    initialized = false;
}

bool is_initialized()
{
    return initialized;
}

static void print_impl()
{
    printf("second implementation! \n");
}

Iimpl *get_impl_instance()
{
    static Iimpl *impl = NULL;

    if (impl)
        return impl;

    impl = malloc(sizeof(Iimpl));

    memset(impl, 0, sizeof(Iimpl));

    impl->initialize = initialize;
    impl->destroy = destroy;
    impl->is_initialized = is_initialized;
    impl->print_impl = print_impl;

    return impl;
}

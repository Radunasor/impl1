#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "impl.h"

static void print_impl()
{
    printf("fisrt implementation! \n");
}

Iimpl *get_impl_instance()
{
    static Iimpl *impl = NULL;

    if (impl)
        return impl;

    impl = malloc(sizeof(Iimpl));

    memset(impl, 0, sizeof(Iimpl));

    impl->print_impl = print_impl;

    return impl;
}
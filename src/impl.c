#include <stdio.h>
#include "impl.h"

static void print_impl(int a, int b)
{
    printf("fisrt implementation! \n");
}

Iimpl *get_impl_instance()
{
    static Iimpl *impl = NULL;

    if (impl)
        return impl;

    impl->print_impl = print_impl;

    return impl;
}
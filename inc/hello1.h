#ifndef HELLO1_H
#define HELLO1_H

#include <linux/list.h>
#include <linux/ktime.h>

struct my_data {
    struct list_head list;
    ktime_t timestamp;
};

void print_hello(unsigned int hello_count);

#endif /* HELLO1_H */

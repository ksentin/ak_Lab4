// SPDX-License-Identifier: GPL-2.0
#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/list.h>
#include <linux/ktime.h>
#include <linux/slab.h>
#include "inc/hello1.h"

MODULE_AUTHOR("Tiniakova Kseniia <ksenpati@gmail.com>");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

static LIST_HEAD(my_list);

void print_hello(unsigned int hello_count)
{
	struct my_data *data;
	int i;

	if (hello_count == 0 || (hello_count < 10 && hello_count > 5))
		pr_warn("Warning! It`s better to use another!");
	for (i = 0; i < hello_count; ++i) {
		data = kmalloc(sizeof(struct my_data), GFP_KERNEL);
		if (!data)
			return;
		data->timestamp = ktime_get();
		INIT_LIST_HEAD(&data->list);
		list_add(&data->list, &my_list);
		pr_info("Hello, world!\n");
	}
}
EXPORT_SYMBOL(print_hello);

static int __init hello1_init(void)
{
	pr_info("Hello1 module loaded\n");
	return 0;
}

static void __exit hello1_exit(void)
{
	struct my_data *data, *temp;
	ktime_t delta;

	list_for_each_entry_safe(data, temp, &my_list, list) {
		delta = ktime_sub(ktime_get(), data->timestamp);
		pr_info("Time elapsed: %lld ns\n", (long long)ktime_to_ns(delta));
		list_del(&data->list);
		kfree(data);
	}
pr_info("Goodbye from hello1 module!\n");
}

module_init(hello1_init);
module_exit(hello1_exit);

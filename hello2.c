// SPDX-License-Identifier: GPL-2.0
#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include "inc/hello1.h"

MODULE_AUTHOR("Tiniakova Kseniia <ksenpati@gmail.com>");
MODULE_DESCRIPTION("Hello2, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

static unsigned int hello_count = 1;

module_param(hello_count, uint, 0444);
MODULE_PARM_DESC(hello_count, "Number of times to print 'Hello, world!' (default=1)");

static int __init hello2_init(void)
{
	if (hello_count <= 10) {
		pr_info("Hello2 module loaded\n");
	print_hello(hello_count);
	} else {
		pr_err("Invalid parameter value! Module loading failed.\n");
		return -EINVAL;
	}
return 0;
}

static void __exit hello2_exit(void)
{
	pr_info("Goodbye from hello2 module!\n");
}

module_init(hello2_init);
module_exit(hello2_exit);

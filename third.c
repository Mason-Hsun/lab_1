/*
 * third_example.c - Demonstrates command line argument passing to a module.
 *
 * Example code of kernel module
 *
 * Modified by 112753104@nccu.edu.tw
 * This code is from https://sysprog21.github.io/lkmpg/
 */

#include <linux/init.h>
#include <linux/kernel.h> /* for ARRAY_SIZE() */
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>
#include <linux/stat.h>

MODULE_LICENSE("GPL");

static char *myname = "Unknown";
static int myage = 0;
static int mybirthday[2] = {0, 0};

module_param(myname, charp, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myname, "Your name");
module_param(myage, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myage, "Your age");
module_param_array(mybirthday, int, NULL, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(mybirthday, "Your birthday (four integers)");

static int __init proc_init(void)
{
    pr_info("Hello, world\n");
    pr_info("my name is: %s\n", myname);
    pr_info("my age is: %d\n", myage);
    pr_info("my birthday: %d/%d\n", mybirthday[0], mybirthday[1]);
    return 0;
}

static void __exit proc_exit(void)
{
    pr_info("Goodbye, world\n");
}

module_init(proc_init);
module_exit(proc_exit);


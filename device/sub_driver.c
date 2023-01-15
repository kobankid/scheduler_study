#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("Dual BSD/GPL");

void sub_driver(void)
{
    printk("%s: sub() called\n", __func__);
}

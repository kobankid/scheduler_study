#include <linux/module.h>
#include <linux/init.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/sched.h>
#include <asm/current.h>
#include <asm/uaccess.h>

MODULE_LICENSE("Dual BSD/GPL");

#define DRIVER_NAME "MY_DEVICE"
#define DRIVER_MAJOR 63
#define NUM_BUFFER 256
static char stored_value[NUM_BUFFER] = {'A',};

extern void sub_driver(void);

static int my_device_open(struct inode *inode, struct file *file)
{
    printk("%s\n", __func__);
    return 0;
}

static int my_device_close(struct inode *inode, struct file *file)
{
    printk("%s\n", __func__);
    return 0;
}

static ssize_t my_device_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
    printk("%s\n", __func__);
    if (count > NUM_BUFFER) count = NUM_BUFFER;
    if (copy_to_user(buf, stored_value, count) != 0) {
        return -EFAULT;
    }
    return count;
}

static ssize_t my_device_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
    printk("%s\n", __func__);
    if (copy_from_user(stored_value, buf, count) != 0) {
        return -EFAULT;
    }
    printk("%s\n", stored_value);
    return count;
}

struct file_operations s_my_device_fops = {
    .open     = my_device_open,
    .release  = my_device_close,
    .read     = my_device_read,
    .write    = my_device_write,
};

static int my_device_init(void)
{
    printk("Hello my module\n");
    register_chrdev(DRIVER_MAJOR, DRIVER_NAME, &s_my_device_fops);
    sub_driver();

    return 0;
}

static void my_device_exit(void)
{
    printk("Bye\n");
    unregister_chrdev(DRIVER_MAJOR, DRIVER_NAME);
}

module_init(my_device_init);
module_exit(my_device_exit);



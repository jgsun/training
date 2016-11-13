#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>

MODULE_LICENSE ("GPL");

int hello_major = 555;
int hello_minor = 0;
int number_of_devices = 1;
struct cdev hello_cdev;
dev_t hello_dev = 0;

struct file_operations hello_fops = {
	.owner = THIS_MODULE
};

struct class hello_class = {
	.name = "hello_class",
};

static int __init hello_2_init(void)
{
	int ret;

	hello_dev = MKDEV(hello_major, hello_minor);
	ret = register_chrdev_region(hello_dev, number_of_devices, "hello");
	if (ret < 0) {
		printk (KERN_WARNING "hello: can't get major number %d/n", hello_major);
		return ret;
	}

	cdev_init(&hello_cdev, &hello_fops);
	hello_cdev.owner = THIS_MODULE;
	hello_cdev.ops = &hello_fops;
	ret = cdev_add(&hello_cdev, hello_dev, number_of_devices);
	if (ret)
		printk(KERN_NOTICE "Error %d adding char_reg_setup_cdev", ret);

	/* create your own class under /sysfs */
	ret = class_register(&hello_class);
	if (ret) {
		printk("Err: class_register failed./n");
		return -1;
	}

	/* register your own device in sysfs, and this will cause udev to create corresponding device node */
	device_create(&hello_class, NULL, MKDEV(hello_major, 0), NULL, "hello%d", 0);

	printk(KERN_INFO "Registered character driver/n");
	return 0;
}

static void __exit hello_2_exit (void)
{
	class_unregister(&hello_class);                               //delete class created by us

	device_destroy(&hello_class, MKDEV(hello_major, 0));         //delete device node under /dev
	unregister_chrdev_region(hello_dev, number_of_devices);
	cdev_del(&hello_cdev);

	printk(KERN_INFO "char driver cleaned up/n");
}

module_init(hello_2_init);
module_exit(hello_2_exit);

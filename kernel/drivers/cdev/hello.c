#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/uaccess.h>

MODULE_LICENSE ("GPL");

#define HELLO_MAX_DEVICES	1
#define HELLO_ON		1
#define HELLO_OFF		0
#define BUFLEN			20

static int hello_major;
static struct cdev *hello_cdev;

struct hello_device {
	struct cdev cdev;
	unsigned char value;
	unsigned char buf[BUFLEN];
};

struct class hello_class = {
	.name = "hello",
};

int hello_open(struct inode *inode, struct file *filp)
{
	struct hello_device *dev;
	dev = container_of(inode->i_cdev, struct hello_device, cdev);
	filp->private_data = dev;
	return 0;
}

ssize_t hello_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
	struct hello_device *dev = filp->private_data;
	int size = count;
	int pos = *f_pos;
	printk("%s,count=%d, position=%d\n", __func__, size, pos);
	if (copy_to_user(buf, dev->buf, count))
		return -EFAULT;
	return 1;
}

ssize_t hello_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
	struct hello_device *dev = filp->private_data;
	int size = count;
	int pos = *f_pos;
	printk("%s,count=%d, position=%d\n", __func__, size, pos);
	if (copy_from_user(dev->buf, buf, count))
		return -EFAULT;
	return 1;
}

long hello_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	struct hello_device *dev = filp->private_data;
	switch(cmd) {
	case HELLO_ON:
	      printk("hello on\n");
	      dev->value = 1;
	      break;
	case HELLO_OFF:
	      printk("hello off\n");
	      dev->value = 0;
	      break;
	default:
	      return -ENOTTY;
	}
	return 0;
}

struct file_operations hello_fops = {
	.owner = THIS_MODULE,
	.read = hello_read,
	.write = hello_write,
	.unlocked_ioctl = hello_ioctl,
	.open = hello_open,
};

static int __init hello_init(void)
{
	static const char name[] = "hello";
	struct hello_device *devp = NULL;
	int ret = 0;
	dev_t hello_dev;

	devp = kzalloc(sizeof(struct hello_device), GFP_KERNEL);
	if (!devp) {
		printk(KERN_WARNING "hello: can't alloc hello_device\n");
		ret = -ENOMEM;
		goto out;
	}

	ret = alloc_chrdev_region(&hello_dev, 0, HELLO_MAX_DEVICES, name);
	if (ret) {
		printk(KERN_WARNING "hello: can't alloc_chrdev_region, %d\n", ret);
		goto out_free;
	}

	hello_major = MAJOR(hello_dev);

	cdev_init(&devp->cdev, &hello_fops);

	devp->cdev.owner = THIS_MODULE;
	devp->cdev.ops = &hello_fops;
	hello_cdev = &devp->cdev;

	strcpy(devp->buf, "hello, kernel init");
	ret = cdev_add(&devp->cdev, hello_dev, HELLO_MAX_DEVICES);
	if (ret) {
		printk(KERN_NOTICE "Error %d adding cdev", ret);
		goto out_unregister;
	}

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

out_unregister:
	unregister_chrdev_region(hello_dev, HELLO_MAX_DEVICES);
out_free:
	kfree(devp);
out:
	return ret;
}

static void __exit hello_exit (void)
{
	device_destroy(&hello_class, MKDEV(hello_major, 0));         //delete device node under /dev
	class_unregister(&hello_class);                               //delete class created by us
	unregister_chrdev_region(MKDEV(hello_major, 0), HELLO_MAX_DEVICES);
	cdev_del(hello_cdev);

	printk(KERN_INFO "char driver cleaned up/n");
}

module_init(hello_init);
module_exit(hello_exit);

/*
 * faulty.c -- a module which generates an oops when read
 *
 * Copyright (C) 2001 Alessandro Rubini and Jonathan Corbet
 * Copyright (C) 2001 O'Reilly & Associates
 *
 * The source code in this file can be freely used, adapted,
 * and redistributed in source or binary form, so long as an
 * acknowledgment appears in derived source files.  The citation
 * should list that the code comes from the book "Linux Device
 * Drivers" by Alessandro Rubini and Jonathan Corbet, published
 * by O'Reilly & Associates.   No warranty is attached;
 * we cannot take responsibility for errors or fitness for use.
 *
 * $Id: faulty.c,v 1.3 2004/09/26 07:02:43 gregkh Exp $
 */

// #include <linux/config.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/miscdevice.h>
#include <linux/kernel.h> /* printk() */
#include <linux/fs.h>     /* everything... */
#include <linux/types.h>  /* size_t */
#include <asm/uaccess.h>

ssize_t faulty_read(struct file *filp, char __user *buf,
		    size_t count, loff_t *pos)
{
	int ret;
	char stack_buf[4];

	/* Let's try a buffer overflow  */
	memset(stack_buf, 0xff, 20);
	if (count > 4)
		count = 4; /* copy 4 bytes to the user */
	ret = copy_to_user(buf, stack_buf, count);
	if (!ret)
		return count;
	return ret;
}

ssize_t faulty_write (struct file *filp, const char __user *buf, size_t count,
		loff_t *pos)
{
	/* make a simple fault by dereferencing a NULL pointer */
	*(int *)0 = 0;
	return 0;
}

struct file_operations faulty_fops = {
	.read =  faulty_read,
	.write = faulty_write,
	.owner = THIS_MODULE
};

static struct miscdevice faulty_miscdev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "faulty",
	.fops = &faulty_fops,
};

int faulty_init(void)
{
	int ret;

	ret = misc_register(&faulty_miscdev);
	if (ret < 0) {
		printk("faulty: failed to register misc device\n");
		return ret;
	}
	return 0;
}

void faulty_cleanup(void)
{
	misc_deregister(&faulty_miscdev);
}

module_init(faulty_init);
module_exit(faulty_cleanup);
MODULE_AUTHOR("Jonathan Corbet and jianguo_sun@hotmail.com");
MODULE_DESCRIPTION("faulty driver");
MODULE_LICENSE("GPL");

#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x8b77232d, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xafb6afa9, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0x8b52d323, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0x3584fee5, __VMLINUX_SYMBOL_STR(class_unregister) },
	{ 0x3a902271, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0xe4a49992, __VMLINUX_SYMBOL_STR(__class_register) },
	{ 0xcb554b5d, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0xf0b80152, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xd8e484f0, __VMLINUX_SYMBOL_STR(register_chrdev_region) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "25A0E75FC037BA9943A7A69");

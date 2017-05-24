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
	{ 0x614554b7, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x9ded188e, __VMLINUX_SYMBOL_STR(kobject_del) },
	{ 0xecc3c7d7, __VMLINUX_SYMBOL_STR(kobject_create_and_add) },
	{ 0x319b5131, __VMLINUX_SYMBOL_STR(test_parent) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "D07E49283006C8931D28F70");

#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
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
	{ 0x7d799ea7, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xf9654328, __VMLINUX_SYMBOL_STR(free_netdev) },
	{ 0x829401eb, __VMLINUX_SYMBOL_STR(unregister_netdev) },
	{ 0xe9cf0dbb, __VMLINUX_SYMBOL_STR(netif_carrier_off) },
	{ 0x54fe5354, __VMLINUX_SYMBOL_STR(register_netdev) },
	{ 0x16cd74c3, __VMLINUX_SYMBOL_STR(alloc_etherdev_mqs) },
	{ 0x4f79237e, __VMLINUX_SYMBOL_STR(netif_carrier_on) },
	{ 0x88c1174a, __VMLINUX_SYMBOL_STR(__dev_kfree_skb_any) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "064B0801923C99ECD29364B");

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
	{ 0x9d35aeec, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xf699984e, __VMLINUX_SYMBOL_STR(kobject_put) },
	{ 0x3356b90b, __VMLINUX_SYMBOL_STR(cpu_tss) },
	{ 0xd7b77006, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0x8a9809d6, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0x2ed13d46, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0x6bf1c17f, __VMLINUX_SYMBOL_STR(pv_lock_ops) },
	{ 0xa2e59924, __VMLINUX_SYMBOL_STR(param_ops_int) },
	{ 0xd8e484f0, __VMLINUX_SYMBOL_STR(register_chrdev_region) },
	{ 0xc8b57c27, __VMLINUX_SYMBOL_STR(autoremove_wake_function) },
	{ 0x26b3c701, __VMLINUX_SYMBOL_STR(__wake_up_sync) },
	{ 0xef695c21, __VMLINUX_SYMBOL_STR(no_llseek) },
	{ 0x6dc0c9dc, __VMLINUX_SYMBOL_STR(down_interruptible) },
	{ 0x4c3654bb, __VMLINUX_SYMBOL_STR(kobject_set_name) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0xc23ede51, __VMLINUX_SYMBOL_STR(tty_devnum) },
	{ 0x3a1a444, __VMLINUX_SYMBOL_STR(nonseekable_open) },
	{ 0x9e88526, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0x4f8b5ddb, __VMLINUX_SYMBOL_STR(_copy_to_user) },
	{ 0xfb578fc5, __VMLINUX_SYMBOL_STR(memset) },
	{ 0x298f5f9, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xa1c76e0a, __VMLINUX_SYMBOL_STR(_cond_resched) },
	{ 0x823714f8, __VMLINUX_SYMBOL_STR(fasync_helper) },
	{ 0x6dc6dd56, __VMLINUX_SYMBOL_STR(down) },
	{ 0x9bced8a5, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0x7b4cebeb, __VMLINUX_SYMBOL_STR(__class_register) },
	{ 0xd31907ac, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0xc6cbbc89, __VMLINUX_SYMBOL_STR(capable) },
	{ 0xb2fd5ceb, __VMLINUX_SYMBOL_STR(__put_user_4) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x1000e51, __VMLINUX_SYMBOL_STR(schedule) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0x2142697b, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xe259ae9e, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0xa6bbd805, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0x2207a57f, __VMLINUX_SYMBOL_STR(prepare_to_wait_event) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x3bb5114a, __VMLINUX_SYMBOL_STR(prepare_to_wait) },
	{ 0x78e739aa, __VMLINUX_SYMBOL_STR(up) },
	{ 0xde95f5b, __VMLINUX_SYMBOL_STR(kill_fasync) },
	{ 0xf08242c2, __VMLINUX_SYMBOL_STR(finish_wait) },
	{ 0x4f6b400b, __VMLINUX_SYMBOL_STR(_copy_from_user) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "89DE70303950100347B2A85");

#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/cpumask.h>
#include <linux/list.h>
#include <asm-generic/local.h>
#include <linux/platform_device.h>
#include <linux/kallsyms.h>

static void force(void)
{
	int symbol_addr;

	printk("XXXXXX, force!\n");
	symbol_addr = kallsyms_lookup_name("hello");

	platform_device_unregister((struct platform_device*)(*(int*)symbol_addr));
}

static int __init force_rmmod_init(void)
{
	struct module *mod, *relate;
	int cpu;

	int symbol_addr;
	symbol_addr = kallsyms_lookup_name("vms_dev");
	printk("YYYYY, symbol_addr:0x%x\n", symbol_addr);

	printk("[module init] name:%s, state:%d\n", THIS_MODULE->name, THIS_MODULE->state);

	list_for_each_entry(mod, THIS_MODULE->list.prev, list) {
		if (strcmp(mod->name, "hello") == 0) {
			printk("[hello]:name:%s, state:%d, refcnt:%u\n",
				mod->name ,mod->state, module_refcount(mod));

			if (!list_empty(&mod->source_list)) {
				list_for_each_entry(relate, &mod->source_list, source_list)
				printk("[relate]:%s\n", relate->name);
			} else {
				printk("used by NULL...\n");
			}

			mod->state = 0;
			//mod->exit = force;

			for_each_possible_cpu(cpu)
				local_set((local_t*)per_cpu_ptr(mod->refptr, cpu), 0);
			//local_set(__module_ref_addr(mod, cpu), 0);
			//per_cpu_ptr(mod->refptr, cpu)->decs;
			//module_put(mod);

			printk("[after]:name:%s, state:%d, refcnt:%u\n",
				mod->name, mod->state, module_refcount(mod));
		}
	}
	return 0;
}

static void __exit force_rmmod_exit(void)
{
	printk("[module exit] name:%s, state:%d\n", THIS_MODULE->name, THIS_MODULE->state);
}

module_init(force_rmmod_init);
module_exit(force_rmmod_exit);

MODULE_LICENSE("GPL");

#include <linux/module.h>
#include <linux/poll.h>

#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/miscdevice.h>
#include <linux/kernel.h>
#include <linux/major.h>
#include <linux/mutex.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/stat.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/tty.h>
#include <linux/kmod.h>
#include <linux/gfp.h>
#include <linux/gpio/consumer.h>
#include <linux/platform_device.h>
#include <linux/of_gpio.h>
#include <linux/of_irq.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/slab.h>
#include <linux/fcntl.h>
#include <linux/timer.h>
#include <linux/workqueue.h>
#include <asm/current.h>




static int SR501_driver_probe(struct platform_device *pdev)
{
    printk("SR501_drviver_probe\n");

    return 0;
}
static int SR501_driver_remove(struct platform_device *pdev)
{
    printk("SR501_drviver_remove\n");

    return 0;
}
static irqreturn_t SR501_isr(int irq, void *dev_id)
{
	return IRQ_WAKE_THREAD;
}

static struct of_device_id wwj_sr501[] = {
    { .compatible = "wwj,sr501" },
    { },//!这一项是必须的,否则无法匹配
};

static struct platform_driver SR501_driver_driver = {
    .probe = SR501_driver_probe,
    .remove = SR501_driver_remove,
    .driver= {
        .name = "wwj_sr501",
        .of_match_table = wwj_sr501,
    },
    
};

static int __init SR501_drviver_init(void)
{
    printk("SR501_drviver_init\n");

    int err;
    err = platform_driver_register(&SR501_driver_driver);

    return 0;
}

static void __exit SR501_drviver_exit(void)
{
    printk("SR501_drviver_exit\n");

    platform_driver_unregister(&SR501_driver_driver);

    return;
}

module_init(SR501_drviver_init);
module_exit(SR501_drviver_exit);

MODULE_LICENSE("GPL");



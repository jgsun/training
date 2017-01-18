#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#define FIFO_CLEAR 0x1
#define BUFFER_LEN 20
void main(void)
{
	int fd, num;
	char rd_ch[BUFFER_LEN];
	fd_set rfds;	/* 读文件描述符集 */

	/* 以非阻塞方式打开/dev/globalfifo设备文件 */
	fd = open("/dev/globalfifo", O_RDONLY | O_NONBLOCK);
	if (fd != -1) {
		/* FIFO清0 */
		if (ioctl(fd, FIFO_CLEAR, 0) < 0)
			printf("ioctl command failed\n");

		while (1) {
			FD_ZERO(&rfds);
			FD_SET(fd, &rfds);
			printf("got or sleep\n");
			select(fd + 1, &rfds, NULL, NULL, NULL);
			printf("wake up!\n");
			/* 数据可获得 */
			if (FD_ISSET(fd, &rfds))
				printf("Poll monitor:can be read\n");
			num = read(fd, rd_ch, BUFFER_LEN);
			printf("read fifo = %s\n", rd_ch);
		}
	} else {
		printf("Device open failure\n");
	}
}

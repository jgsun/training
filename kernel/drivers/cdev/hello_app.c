#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFLEN		20
#define FIELDLEN	1

void main(void)
{
	int fd, num;
	FILE *fd_stream;
	char rbuf[BUFLEN];
	char wbuf[BUFLEN] = "hello, user update!";

	fd = open("/dev/hello0", O_RDWR);
	if (fd) {
		num = read(fd, rbuf, BUFLEN);
		printf("read %d, rbuf=%s\n", num, rbuf);
		num = write(fd, wbuf, sizeof(wbuf));
		printf("write %d, wbuf=%s\n", num, wbuf);
		num = read(fd, rbuf, BUFLEN);
		printf("read %d, rbuf=%s\n", num, rbuf);
	}
	close(fd);

	fd_stream = fopen("/dev/hello0", "r+");
	if (fd_stream) {
		num = fread(rbuf, 1, 1, fd_stream);
		printf("read %d fields, rbuf=%s\n", num, rbuf);
		num = fwrite(wbuf, 1, 1, fd_stream);
		printf("write %d fields, wbuf=%s\n", num, wbuf);
		num = fread(rbuf, 1, 1, fd_stream);
		printf("read %d fields, rbuf=%s\n", num, rbuf);
	}
	fclose(fd_stream);
}

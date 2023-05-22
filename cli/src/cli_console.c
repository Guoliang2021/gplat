#include "GDefs.h"
#include "cli_console.h"

int createConsole()
{
	int32_t tty_fd = -1;
	int32_t rv = -1;
	uint8_t rBuf[128] = {0};
	struct termios options;
	fd_set rset;

	tty_fd = open("/dev/tty1",O_RDWR);
	if(tty_fd < 0)
	{
		printf("open tty0 failed:%s\n\r",strerror(errno));
		goto CLOSE;
	}
	printf("open tty0 success.\n\r");

	memset(&options, 0, sizeof(struct termios));
	rv = tcgetattr(tty_fd, &options);
	if(rv != 0)
	{
		printf("tcgetattr() failed:%s\n\r",strerror(errno));
		goto CLOSE;
	}
	printf("tcgetattr success.\n\r");

	options.c_cflag |= CLOCAL|CREAD;
	options.c_cflag &= ~CSIZE;
	options.c_cflag |= CS8;
	options.c_cflag &= ~PARENB;

	cfsetispeed(&options,B115200);
	cfsetospeed(&options,B115200);

	options.c_cflag &= ~CSTOPB;
	options.c_cc[VTIME] = 0;
	options.c_cc[VMIN] = 0;
	tcflush(tty_fd, TCIFLUSH);

	if((tcsetattr(tty_fd,TCSANOW,&options)) != 0)
	{
		printf("tcsetattr failed:%s\n\r",strerror(errno));
		goto CLOSE;
	}
	printf("tcsetattr success.\n\r");

	while(1)
	{
		FD_ZERO(&rset);
		FD_SET(tty_fd,&rset);

		rv = select(tty_fd + 1, &rset, NULL, NULL, NULL);
		if(rv < 0)
		{
			printf("select failed:%s\n\r",strerror(errno));
			goto CLOSE;
		}

		if(rv == 0)
		{
			printf("select time out\n\r");
			goto CLOSE;
		}

		memset(rBuf, 0, sizeof(rBuf));
		rv = read(tty_fd, rBuf, sizeof(rBuf));
		if(rv < 0)
		{
			printf("read error:%s\n\r",strerror(errno));
			goto CLOSE;
		}
		printf("\n\r Read from tty0: %s\n\r",rBuf);
	}
CLOSE:
	close(tty_fd);
	return 0;
}

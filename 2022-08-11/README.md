```txt
├── node an simple nodejs script
├── public static file for ./server/server.js
├── rpc simple example for remote procedure call
└── server
```

### rpc 示例

编写 remote protocol ( .x 文件)

```c
/*
 * add.x: Remote protocol for addition
 */
struct number {
    int x;
    int y;
};

program ADDPROG {
    version ADDVERS {
        int add(number) = 1;
    } = 1;
} = 0x23451111;
```

使用 rpcgen 生成框架

```sh
rpcgen -a -C add.x
```

修改 client server 代码

```c
/*
 * add_server.c
 */
#include "add.h"

int *add_1_svc(number *argp, struct svc_req *rqstp) {
    static int result;

    printf("add(%d, %d) is called\n", argp->x, argp->y);
    result = argp->x + argp->y;
    return &result;
}
```

```c
/*
 * add_client.c
 */

#include "add.h"

void
addprog_1(char *host, int x, int y)
{
	CLIENT *clnt;
	int  *result_1;
	number  add_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, ADDPROG, ADDVERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	add_1_arg.x = x;
	add_1_arg.y = y;
	result_1 = add_1(&add_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}else {
		printf("the result is %d\n", *result_1);
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}

int main (int argc, char *argv[])
{
	char *host;

	if (argc < 4) {
		printf ("usage: %s server_host number1 number2\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	addprog_1 (host, atoi(argv[2]), atoi(argv[3]));
exit (0);
}

```

编译 运行

```sh
make -f Makefile.add
#确保安装rpcbind, 命令行输入rpcinfo无报错即可
#先运行server
./add_server
#运行client
./add_client localhost 10 20
#输出
the result is 30
```

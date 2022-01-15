#include <stdio.h>
#include <stdlib.h>

#if 0
struct tty_buffer {
	union {
		struct tty_buffer *next;
		struct llist_node free;
	};
	int used;
	int size;
	int read;
	unsigned long data[];
};
struct tty_struct;
struct tty_operations {
	struct tty_struct* (*loopup)(struct tty_driver *driver, struct file *filp, int index);
	int (*install) (struct tty_driver *drv, const char *input_buf);
	void (*put_char) (struct tty_driver *dev, const char *input_buf);
};
static const struct tty_operations uart_ops = {
	.install = uart_install,
	.open = uart_open,
	.close = uart_close,
};
#endif

//static DEFINE_MUTEX(port_mutex);

enum codec_type {
	VP9 = 0,
	AV1 = 1,
	HEVC = 2,
	AVC = 3,
	NON = 4,
};

struct rx_buffer {
	// buffer information
	int buf_index;
	// used to notice when we can remove the buffer from process one
	int ref_cnt;
	// hold buffer address, which was const
	const char *buf;
};

struct codec_ctx {
	void (*open) ();
	int (*decode) (const struct rx_buffer *buf, char *out_buffer);
	void (*close) (void);
};

struct codec_operations {
	int (*install) (void);
	int (*uninstall)(void);
	int (*decode) (void);
	int (*ecode) (void);
};

// return output size
static int lc3_decode_ext(const char *buf, char *out)
{
	return 100;
}

static void lc3_open(void)
{
	printf("lc3 decoder init\n");
}

static void lc3_close(void)
{
	printf("lc3 decoder closed\n");
}

static int lc3_decode(const struct rx_buffer *buf, char *out)
{
	int output_size = 0;

	output_size = lc3_decode_ext(buf->buf, out);
	free(out);

	return output_size;
}

struct codec_ctx lc3_codec = {
	.open = lc3_open,
	.decode = lc3_decode,
	.close = lc3_close,
};

int main(int argc, char* argv[])
{
	struct codec_ctx *ctx;
	struct rx_buffer rx;
	char *cc = (char*) malloc(sizeof(char)*100);

	ctx = &lc3_codec;
	
	if (ctx->open)
		ctx->open();

	int ret = ctx->decode(&rx, cc);

	printf("ret = %d\n", ret);
	if (ctx->close)
		ctx->close();

	return 0;
}

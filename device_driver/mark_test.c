#include <stdio.h>
#include <stdlib.h>

#define __IO_READ__(addr) (*((volatile unsigned int*)(addr)))
#define __IO_WRITE__(addr, data) ((*(volatile unsigned int*)(addr)) = (unsigned int)data)

/*
 *  regs = platform_get_resource(pdev, IORESOURCE_MEM, i)
 *  devm_ioremap_resource(dev, regs);
 *  void __iomem *regs[10];
 *
 */

typedef enum DEC_STATUS_T {
	DECODE_DONE,
	DECODE_ERR,
	INPUT_DATA_CORRUPTED,
	MAX,
} DEC_STATUS;

struct codec_ops {
	void (*init)(void);
	DEC_STATUS (*decode)(const char *input_buffer);
	DEC_STATUS (*encode)(const char *input_raw);
	void (*deinit)(void);
};

struct vp9_ctx_t {
	char *buf;
	int frame_count;
} vp9_ctx;

static void vp9_init(void)
{
	char *internal_buf = (char*)malloc(sizeof(char)*100);
	uint32_t reg_val = __IO_READ__(0x11223344);

	if (internal_buf != NULL)
		printf("internal buf allocated\n");

	vp9_ctx.buf = internal_buf;
}

static DEC_STATUS vp9_decode(const char *in)
{
	unsigned long flag;

	return DECODE_DONE;
}

static DEC_STATUS vp9_encode(const char *in)
{
	return DECODE_DONE;
}

static void vp9_deinit(void)
{
	if (vp9_ctx.buf)
		free(vp9_ctx.buf);

	return;
}

static const struct codec_ops vp9_ops = {
	.init = vp9_init,
	.decode = vp9_decode,
	.encode = vp9_encode,
	.deinit = vp9_deinit,
};


int check_bit(int bit, int target) {
	return target >> bit & 1;
}

int set_bit(int bit, int target) {
	return target | (1 << bit);
}

int clear_bit(int bit, int target) {
	return target & ~(1 << bit);
}

int toggle_bit(int bit, int target) {
	return target ^ (1 << bit);
}


int main(int argc, char *argv[])
{
	const struct codec_ops *ctx = &vp9_ops;
	int data = 0;

	data = set_bit(2, data);
	printf("set bit 2 => %d\n", data);

	data = set_bit(3, data);
	printf("set bit 3 => %d\n", data);
	data = toggle_bit(3, data);
	printf("toggle bit 3 => %d\n", data);
	data = toggle_bit(0, data);
	printf("toggle bit 1 => %d\n", data);
	data = clear_bit(2, data);
	printf("clear bit 2 => %d\n", data);

	if (check_bit(0, data))
		printf("bit 0 was set!!\n");
	else
		printf("bit 0 was NOT set!!\n");


	return 0;
}

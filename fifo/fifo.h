#ifndef _FIFO_H_
#define _FIFO_H_

#define	NUM_FIFO	64
/* FIFOに格納するデータ型 */
typedef unsigned char fifo_data_t;

/* FIFO構造体 */
struct TAG_FIFO {
        fifo_data_t *buf;
		fifo_data_t	data[NUM_FIFO];
        unsigned int size;
        unsigned int read;
        unsigned int write;
};

/* 型定義 */
typedef struct TAG_FIFO fifo_t;

/* 関数プロトタイプ */
void initializeFIFO(fifo_t *inst);
void fifo_delete(fifo_t *inst);
unsigned int fifo_how_fill(fifo_t *inst);
unsigned int fifo_how_empty(fifo_t *inst);
int putcFIFO(fifo_t *inst, fifo_data_t  d);
int addBlockFIFO(fifo_t *inst, fifo_data_t *ptr, unsigned int size);
int getBlockFIFO(fifo_t *inst, fifo_data_t *ptr, unsigned int size);

#endif /* _FIFO_H_ */


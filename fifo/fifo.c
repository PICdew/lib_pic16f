#include <stdlib.h>
#include <string.h>
#include "fifo.h"

/* FIFOの作成 */
void initializeFIFO(fifo_t *inst)
{
	inst->buf	= inst->data;
	inst->size	= NUM_FIFO;
	inst->read	= 0;
	inst->write	= 0;
}

/* FIFOの削除 */
void fifo_delete(fifo_t *inst)
{
        free(inst->buf);
        free(inst);
}

/* FIFOのデータ要素数を取得する */
unsigned int fifo_how_fill(fifo_t *inst)
{
        unsigned int val;

        val = (inst->size + inst->write - inst->read) % inst->size;
        return val;
}

/* FIFOの空き要素数を取得する */
unsigned int fifo_how_empty(fifo_t *inst)
{
        unsigned int val;

        val = (inst->size + inst->read - inst->write - 1) % inst->size;
        return val;
}

/* データを追加する */
int putcFIFO(fifo_t *inst, fifo_data_t d)
{
        unsigned int next = (inst->write + 1) % inst->size;
        if ( next == inst->read ) {
                return 0;
        }

        *(inst->buf+inst->write) = d;
        inst->write = next;

        return 1;
}

/* データブロックを追加する */
int addBlockFIFO(fifo_t *inst, fifo_data_t *ptr, unsigned int size)
{
        int n = fifo_how_empty(inst);
        int i;

        if ( size < n ) {
                n = size;
        }

        for (i=0;i<n;i++) {
                inst->buf[(inst->write+i)%inst->size] = *(ptr+i);
        }
        inst->write = (inst->write + n) % inst->size;

        return n;
}

/* データを読み取る */
int getBlockFIFO(fifo_t *inst, fifo_data_t *ptr, unsigned int size)
{
        int n = fifo_how_fill(inst);
        int i;

        if ( n > size ) n = size;

        for (i=0;i<n;i++) {
                *(ptr+i) = *(inst->buf + (inst->read+i)%inst->size);
        }
        inst->read = (inst->read + n) % inst->size;

        return n;
}

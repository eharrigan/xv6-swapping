#include "types.h"
#include "defs.h"
#include "param.h"
#include "spinlock.h"
#include "fs.h"
#include "buf.h"

// Write a the page at addres pg to disk at block
void
write_page(char* pg, uint block) {
    struct buf *buffer[8];

    //fill the array of buffers with the data
    for(int i = 0; i < 8; i++) {
        //get a buffer
        buffer[i] = bget(ROOTDEV, block + i);
        //copy the contents of the page to the buffer
        memmove(buffer[i]->data, pg + BSIZE * i, BSIZE);
        bwrite(buffer[i]);
        brelse(buffer[i]);
    }

}


//read the data at block into the address of pg

void
read_page(char* pg, uint block) {
    struct buf *buffer[8];
    
    for(int i = 0; i < 8; i++) {
        buffer[i] = bread(ROOTDEV, block + i);
        memmove(pg + BSIZE * i, buffer[i]->data, BSIZE);
        brelse(buffer[i]);
    }
}



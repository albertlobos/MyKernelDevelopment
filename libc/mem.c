#include "mem.h"
#include "../globals/global.h"
#include "../libc/string.h"
#include "../drivers/screen.h"
void memory_copy(u8 *source, u8 *dest, int nbytes) {
    int i;
    for (i = 0; i < nbytes; i++) {
        *(dest + i) = *(source + i);
    }
}

void memory_set(u8 *dest, u8 val, u32 len) {
    u8 *temp = (u8 *)dest;
    for ( ; len != 0; len--) *temp++ = val;
}



u32 free_mem_addr = 0x5000;
/* Implementation is just a pointer to some free memory which
 * keeps growing */

u32 kmalloc(u32 size, int align, u32 *phys_addr) {

kprint("In kmalloc");
    /* Pages are aligned to 4K, or 0x1000 */
    if (align == 1 && (free_mem_addr & 0xFFFFF000)) {
        free_mem_addr &= 0xFFFFF000;
        free_mem_addr += 0x1000;
    }
    /* Save also the physical address */
    *phys_addr = free_mem_addr;
kprint("\nprinting free_mem_addr --->");
printInt(free_mem_addr);

    u32 ret = free_mem_addr;
    free_mem_addr += size; /* Remember to increment the pointer */

kprint("\nprinting ret --->");
printInt(ret);
kprint("Out kmalloc");

kprint("\n");
    return ret;
}

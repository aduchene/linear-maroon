#include <climits>

unsigned int morton_basic(unsigned int x, unsigned int y){
	unsigned int z=0; //z curve value
	for(int i=0;i<sizeof(x)*CHAR_BIT/2;i++){
		z |= (x & 1U << i) << i | (y & 1U << i) << (i + 1);
	}
	return z;
}


//works up to 16 bits probs
unsigned int morton_magic(unsigned int xPos, unsigned int yPos)
{
    static const unsigned int MASKS[] = {0x55555555, 0x33333333, 0x0F0F0F0F, 0x00FF00FF};
    static const unsigned int SHIFTS[] = {1, 2, 4, 8};

    unsigned int x = xPos;  // Interleave lower 16 bits of x and y, so the bits of x
    unsigned int y = yPos;  // are in the even positions and bits from y in the odd;

    x = (x | (x << SHIFTS[3])) & MASKS[3];
    x = (x | (x << SHIFTS[2])) & MASKS[2];
    x = (x | (x << SHIFTS[1])) & MASKS[1];
    x = (x | (x << SHIFTS[0])) & MASKS[0];

    y = (y | (y << SHIFTS[3])) & MASKS[3];
    y = (y | (y << SHIFTS[2])) & MASKS[2];
    y = (y | (y << SHIFTS[1])) & MASKS[1];
    y = (y | (y << SHIFTS[0])) & MASKS[0];

    const unsigned int result = x | (y << 1);
    return result;
}

unsigned int morton(unsigned int x, unsigned int y){
	return morton_magic(x, y);
}
// -------------------------------------------------------
// swapbits.cpp: The function swapbits() swaps two bits
//               within an integer. 
// Arguments:    The integer and two bit positions.  
// Returns:      The new value. 
// -------------------------------------------------------

int swapbits( int x, int bitnr1, int bitnr2) 
{                                // To swap two bits in x.
    int newx, mask1, mask2;
    int msb = 8 * sizeof(int) - 1;  // Highest bit position 

    if( bitnr1 < 0 || bitnr1 > msb ||
        bitnr2 < 0 || bitnr2 > msb)
      return x;       // Return, if bit position is invalid 

    mask1 = (1 << bitnr1);    // Shift 1 to position bitnr1 
    mask2 = (1 << bitnr2);    // Shift 1 to position bitnr2 

    newx = x & ~(mask1 | mask2);         // Delete both bits 

    if( x & mask1 )  newx |= mask2;      // Swap bits.
    if( x & mask2 )  newx |= mask1;

    return( newx);
}
 

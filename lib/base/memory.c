#include "memory.h"

void memory_copy (byte* source, byte* dest, u_dword num_bytes) {
    for (int i = 0; i < num_bytes; ++i) {
        *(dest + i) = *(source + i);
    }
}

void memory_clear (byte* start, u_dword num_bytes, byte sample) {
    for (int i = 0; i < num_bytes; ++i) {
        *(start + i) = sample;
    }
}

void memory_fill (byte* dest, byte* source, u_dword source_bytes, u_dword times) {
    for (int i = 0; i < times; ++i) {
        for (int j = 0; j < source_bytes; ++j) {
            *(dest + (i * source_bytes + j)) = *(source + j);
        }
    }
}

boolean memory_compare (byte* comp1, byte* comp2, u_dword length) {
    boolean equal = true;
    for (int i = 0; i < length; ++i) {
        equal &= (*(comp1 + i) == *(comp2 + i));
    }
    return equal;
}

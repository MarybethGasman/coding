

void bitmap_clear(int *bits) {
    *bits = (*bits) & 0;
}
void bitmap_set(int *bits, int pos) {
    (*bits) = (*bits) | (1 << pos);
}
void bitmap_reset(int *bits, int pos) {
    (*bits) = (*bits) & ~(1 << pos);
}
int bitmap_get(int *bits, int pos) {
    return ((*bits) >> pos) & 1;
}

void bitmap_flip(int *bits, int pos) {
    if (bitmap_get(bits, pos) == 1) {
        bitmap_reset(bits, pos);
    } else {
        bitmap_set(bits, pos);
    }
}

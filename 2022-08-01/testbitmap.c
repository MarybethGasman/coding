

#include <assert.h>
#include <bitmap.h>

int main() {
    int bitmap;
    bitmap_clear(&bitmap);
    assert(bitmap == 0);

    bitmap_set(&bitmap, 1);
    assert(bitmap == 2);
    assert(bitmap_get(&bitmap, 1) == 1);
    for (int i = 0; i < 32; i++) {
        if(i != 1) {
            assert(bitmap_get(&bitmap, i) == 0);
        }
    }

    bitmap_set(&bitmap, 0);
    assert(bitmap == 3);

    bitmap_reset(&bitmap, 0);
    assert(bitmap == 2);

    bitmap_reset(&bitmap, 1);
    assert(bitmap == 0);

    bitmap_flip(&bitmap, 1);
    assert(bitmap == 2);

    return 0;
}
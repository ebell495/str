#define STRBUF_DEFAULT_ALLOCATOR_STDLIB

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../strbuf.h"
#include "../strview.h"
#include "../strnum.h"



int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size)
{
    if (Size > 1) {
        uint8_t opt = Data[0];
        strview_t str1, str2;
        int i = 0;
        double d = 0;
        str1.data = (Data - 1);
        str1.size = Size + 1;

        switch (opt) {
            case 0:
                str2 = strview_sub(str1, 0, Size - 1);
                break;
            case 2:
                while (strview_split_line(&str1, NULL).size > 0) {}
                break;
            case 3:
                str2 = strview_find_last(str1, cstr(""));
                strview_split_left(&str1, str2);
                strview_split_right(&str1, str2);
                break;
            case 4:
                str2 = strview_find_first(str1, cstr(""));
                strview_split_left(&str1, str2);
                strview_split_right(&str1, str2);
                break;
            case 5:
                strnum_value(&d, &str1, 0);
                strnum_value(&i, &str1, 0);
                break;
            case 6:
                strview_is_match(str1, str1);
                break;
        }
    }
}
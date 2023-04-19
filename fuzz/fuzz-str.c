
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../strbuf.h"
#include "../strview.h"
#include "../strnum.h"



int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size)
{
    if (Size > 0) {
        uint8_t opt = Data[0];
        strview_t str1, str2;
        int i = 0;
        double d = 0;
        strbuf_t* buf = STRBUF_FIXED_CAP(8196);
        strbuf_t* buf1;
        str1.data = (Data + 1);
        str1.size = Size - 1;

        switch (opt) {
            case 0:
                str2 = strview_sub(str1, 0, Size - 1);
                break;
            case 1:
                strbuf_assign(&buf, str1);
                strbuf_strip(&buf, cstr("-"));
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
            case 7:
                buf1 = strbuf_create(Size - 1, NULL);
                str2 = strbuf_assign(&buf1, str1);
                strbuf_shrink(&buf1);
                strbuf_destroy(&buf1);
                break;
            case 8:
                buf1 = strbuf_create(Size - 1, NULL);
                str2 = strbuf_assign(&buf1, str1);
                str2 = strbuf_insert_at_index(&buf1, 0, strbuf_view(&buf));
                strbuf_shrink(&buf1);
                strbuf_destroy(&buf1);
                break;
            case 9:
                if (Size > 1) {
                    strview_split_index(&str1, Data[1] - 127);
                }
                break;
        }
    }
}
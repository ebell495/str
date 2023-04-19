fuzz-str: fuzz-str.c
	clang -g -DSTRBUF_DEFAULT_ALLOCATOR_STDLIB -fsanitize=fuzzer,memory,undefined,nullability -I.. -o fuzz-str fuzz-str.c ../strbuf.c ../strnum.c ../strview.c
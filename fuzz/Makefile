fuzz-str: fuzz-str.c
	clang -g -fsanitize=fuzzer,address,undefined -I.. -o fuzz-str fuzz-str.c ../strbuf.c ../strnum.c ../strview.c
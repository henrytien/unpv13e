#include	"unp.h"

int
main(int argc, char **argv)
{
	union {
	  short  s;
      char   c[sizeof(short)];
    } un;

	un.s = 0x0102;
	printf("%s: ", CPU_VENDOR_OS);
	if (sizeof(short) == 2) {
		if (un.c[0] == 1 && un.c[1] == 2)
			printf("big-endian\n");
		else if (un.c[0] == 2 && un.c[1] == 1)
			printf("little-endian\n");
		else
			printf("unknown\n");
	} else
		printf("sizeof(short) = %d\n", sizeof(short));

	exit(0);
}

// #include <iostream>
// typedef  union {
//     short a;
//     char c;
// } test;

// int main()
// {
//     test b;
//     b.a = 0x0102;
//     if (b.c == 0x02) {
//         std:: cout << "little endian" <<std::endl;
//     } else {
//         std:: cout << "big endian" <<std::endl;
//     }
//     return 0;
// }
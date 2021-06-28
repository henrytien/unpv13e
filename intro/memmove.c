#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *
memmove(void* dest, const void* src, size_t len) {
    if (NULL == dest || NULL == src || len == 0)
        return NULL;
    char* d = (char*)dest;
    const char* s =(char*) src;
    if (d < s) {
        while (len--) {
            *d-- = *s--;
        }
    } else {
        char* lasts = s + (len - 1);
        char* lastd = d + (len - 1);
        while (len--) {
            *lastd-- = *lasts--;
        }
    }
    return dest;
}
int main()
{
    char* str = "I'm Henry";
    char* dest = NULL;
    dest = (char*)malloc(sizeof(char)+1*strlen(str));
    memmove(dest,str,strlen(str));
    printf("dest =%s\n",dest);
    return 0;
}
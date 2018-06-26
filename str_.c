#include <stdio.h>
#include <assert.h>
char* str_cat(char * dst, const char * src)
{
    assert (dst != NULL && src != NULL);
    char* cp = dst;
    while(*cp)
 	cp ++;

    while((*cp ++ = *src++));
    return dst;

}

char* str_cpy(char * dst, const char *src)
{
    assert (dst != NULL && src != NULL);
    char * cp = dst;
    while (*cp++ = *src++);
    return dst;

}
int str_cmp(const char * str1, const char * str2)
{
    while(*str2 && (*str1 == *str2))
    {
	str1 ++;
	str2 ++;
    }
   
    if (*(unsigned char*)str1 > *(unsigned char *)str2)
	return 1;
    else if (*(unsigned char*)str1 < *(unsigned char *)str2)
	return -1;
    else 
 	return 0;

}
 
char* str_ncpy(char *dest, const char* src, int count)
{
    char* cp = dest;
    while(count && (*cp ++ = *src++))
 	count --;

    if (count)  
    {
	while (--count)
 	    *cp++ = '\0';
    }
    
    return dest;

}

int main()
{
    char dst[20] = "hello";
    char src[] = "world";
    str_cat(dst, src);
    printf("%s\n", dst);

    char d[20] = {0};
    str_cpy(d, dst);
    printf("%s\n", d);

    char str1[10] = "str01";
    char str2[] = "str02";
   
    printf("str1 cmp str2: %d \n",str_cmp(str1, str2));
    str_ncpy(str1, str2, 7);
    printf("str_ncpy(str1, str2): str1 = %s \n", str1);

    return 0;
}

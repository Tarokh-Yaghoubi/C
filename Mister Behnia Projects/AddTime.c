#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
    int h1, m1, s1, h2, m2, s2, h3, m3, s3;
  
    printf("TIME1# ");
    scanf("%d:%d:%d", &h1, &m1, &s1);
  
    printf("TIME2# ");
    scanf("%d:%d:%d", &h2, &m2, &s2);
  
    s3=(s1+s2)%60;
    m3=(m1+m2+((s1+s2)/60))%60;
    h3=(h1+h2+((m1+m2)/60));
  
    printf("%2.2d:%2.2d:%2.2d\n", h3, m3, s3);
    printf("PROGRAM ENDS\n");
  
    return 0;
}
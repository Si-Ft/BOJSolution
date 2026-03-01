#include <stdio.h>
int main() {
int N, s=0;
scanf("%d",&N);
s+=N/5; s+=N/25; s+=N/125;
printf("%d", s);
return 0;
}
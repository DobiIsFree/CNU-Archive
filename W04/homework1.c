#include <stdio.h>

int main(){
   char s[] = "";
    printf("문자를 입력하세요(100자 이내).\n");
    scanf("%s", s);
    printf("입력된 문자는 %s 입니다.\n", s);

    return 0;
}

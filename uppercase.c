#include <stdio.h> 
int main()
{
  char ch;
  printf("Enter the character \n");
  scanf("%c", &ch);

  if (ch >= 'A' && ch <= 'Z'){
  printf("upper case");
  }
else if (ch >='a'&& ch <='z'){
    printf("lower case");
}
else {
    printf("Not an English alphabet");
}
return 0;

}

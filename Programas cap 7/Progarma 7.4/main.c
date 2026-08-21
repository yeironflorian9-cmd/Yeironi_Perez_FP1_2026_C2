#include <stdio.h>
#include <string.h>
void main(void)
{
char *cad0;
cad0 = "Argentina";
puts(cad0);
cad0 = "Brasil";
puts(cad0);
char cad1[20];
printf("Ingrese una cadena: ");
fflush(stdin);
fgets(cad1, 20, stdin);
cad1[strcspn(cad1, "\n")] = 0;
puts(cad1);
char cad2[20] = "Mexico";
puts(cad2);
printf("Ingrese otra cadena: ");
fflush(stdin);
fgets(cad2, 20, stdin);
cad2[strcspn(cad2, "\n")] = 0;
puts(cad2);
}

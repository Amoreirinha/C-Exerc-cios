/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */


/*p=NULL
  p=&x
  printf("O valor de p é %p.",p);
  printf("O valor de *p é %d,"*p);
  p++
  ...
  printf("O valor de p é %p.",p);
  printf("O valor de *p é %d,"*p);
  p++*/
#include <cstdlib>
#include <stdio.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

int x, y, z;
int *p;
int v[] = {11, 12, 13 ,14 ,15, 16, 17, 18, 19, 20};

x = 10;
y = 12;
z = 17;

p = &x;
printf("\n\tO valor de &x: %p e o valor de x: %d", p, *p);
printf("\n\n\tO valor de p: %p e o valor de *p: %d", p, *p);

p++;

printf("\n\n\tO valor de p: %p e o valor de *p: %d", p, *p);

/*printf("\n\n\t\t\tValores do vetor com índice\n");
for (int i = 0; i < 10; i++){
    printf("\n\tO valor de &v[%d]: %p e o valor de v[i]: %d", i, &v[i], v[i]);
}*/


printf("\n\n\t\tValores do vetor com ponteiros\n\n");
for (int *q = v; q < v + 10; q++){
    printf("\tO valor de &v: %p e o valor de v[i]: %d\n", q, *q);
}

printf("\n\n\t\tValores do vetor com ponteiros\n\n");
for (int *q = v + 9; q >= v ; q--){
    printf("\tO valor de &v: %p e o valor de v[i]: %d\n", q, *q);
}

    return 0;
}

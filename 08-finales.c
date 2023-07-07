#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Final INFO2-DIC-2016A (Parte_1-2 de 3) ##############################################

// 2.1) - E -> 0 ✅
// int main() {
//     unsigned char a=1;
//     unsigned int i;

//     for(i=0;i<8;i++) {
//         a=a&(1<<i);
//     }
    
//     printf("\n%d",a);
// }

// 2.2) - F: infinite loop ❌ -> A: "b"
// char f(char a) {
//     if (a<'c')
//         f(a+1);
//     else{
//         if (a=='b')
//         f(a+1);
//     }
//     return a;
// }

// void main() {
//     printf("%c",f('b'));
// }

// 2.3) - D: 11 ❌ -> E: error al asignar NULL
// int main() { 
//     int* p=NULL;
//     (*p)=10;
//     printf("%d",*(p)+1);
//     return 0;
// }

// 2.4) - E: 14 ✅
// void f() { 
//     int a=9, b=13;
//     int *bb, **cc;

//     bb=&b;
//     cc= &bb;
//     printf("%d", *bb+1);
// }

// int main() {
//     f();
// }


// Final PROGESTRUC-DIC-2017B (Parte_1-2 de 3).docx ##############################################

// 2.1) - E: 6 ✅

// void sum (int arr[]){
//     arr[0] = arr[0]+3;
// }
// void resta (int a){
//     a= a - 4 ;
// }
// int main(){
//     int a[3]={3,2,13}; int num=0;
//     sum(a);
//     resta(num);
//     printf("%d",a[0] + num);
//     return 0;
// }

// 2.2) - E: 14 ✅
// void f(){
//     int a=9, b=13;
//     int *bb, **cc;
//     bb=&b;
//     cc= &bb;
//     printf("%d", *bb+1);
// }
// int main(){
//     f();
//     return 0;
// }

// 2.3) - E: error ✅
// int main(){
//     int* p=NULL;
//     (*p)=10;
//     printf("%d",*(p)+1);
//     return 0;
// }

// 2.4) - B: 12 ❌ -> E: 81
// int foo(int n,int m){
//     int miFoo=1;
//     if(m>0){
//         miFoo=n*foo(n,m-1);
//     }
//     return miFoo;
// }

// int main() {
//     printf("%d",foo(3,4));
//     return 0;
// }


// Final PROGESTRUC-JUL-2017A (Parte_1-2 de 3) ##############################################

// 2.1) - H: ninguna ✅
// int foo(int n,int m){
//     int miFoo=1;
//     if(m>0){
//     miFoo=n*foo(n,m-1);
//     }
//     return miFoo;
// }

// int main() {
//     printf("%d",foo(3,4));
//     return 0;
// }

// 2.2) - A: (0,0) ✅
// int main() {
//     char* s[5]; int i=0;
//     char c='2';
//     s[i]=&c;
//     for(i=0;i<5;i++){
//         s[i]=&c;
//         c=c+1;
//     }
//     printf("(%d, %d)", (c=='2'), !(s[0]==&c));
//     return 0;
// }

// 2.3) - F: error ✅
// int main(){
//     char* s=NULL; int i;
//     for(i=0;i<4;i++){
//         *(s+i)='a'+i;
//     }
//     s[i]='\0';
//     printf("%s",s);
//     return 0;
// }

// 2.4) - E: 0 ✅
// int foo(unsigned char n,unsigned char filter){
//     return n&((255&(filter<<n+n))>1);
// }

// int main() {
//     printf("%d",foo(3,4));
//     return 0;
// }


// Final PROGESTRUC-JUL-2018A (Parte_1-2 de 3).docx ##############################################

// 2.1) - D: 7 ✅
// void sum (int arr[]){
//     *arr = *arr +3;
// }
// void resta (int a){
//     a= a - 4 ;
// }
// int main(){
//     int a[3]={3,2,13}; int num=1;
//     sum(a);
//     resta(num);
//     printf("%d",*a + num);
//     return 0;
// }

// 2.2) - E: 22 ✅
// void f(){
//     int a=9, b=13;
//     int* ar[2];
//     ar[0]=&a;
//     ar[1]= &b;
//     printf("%d", *ar[0]+*ar[1]);
// }
// int main(){
//     f();
//     return 0;
// }

// 2.3) - E: error ✅
// int main(){
//     int* p=NULL;
//     (*p)=10;
//     printf("%d",*(p)+1);
//     return 0;
// }

// 2.4) - H: ninguna ✅
// int foo(int n,int m){ 
//     int miFoo=0;
//     if(m<0){
//         miFoo=n*foo(n,m-1);
//         return miFoo;
//     }
//     return miFoo;
// }

// int main() {
//     printf("%d",foo(3,4));
//     return 0;
// }


// InformaticaII_FINAL_DIC_2013  ##############################################

// 2.1 - C: 0 ✅
// int doble(int valor) {
//     int entero=16;
//     entero=(valor<<20)&16;
//     return entero;
// }

// int main() {
//     printf("%d",doble(3));
//     return 0;
// }

// 2.2 - F: ninguna ❌ -> A: no muestra nada (printf("\0"))
// int main() {
//     char *ptrA = "Juan";
//     char *ptrB = "Pedro";
//     ptrA = ptrA + 4;
//     for(;*ptrB!='\0';ptrB++);
//     printf("%c", *ptrA);
// }

// 2.3 - D: 128 ✅
// int main() {
//     unsigned char a;
//     a= ~0 << ((sizeof(unsigned char)*8)-1);
//     printf("%d", a);
// }

// 2.4 - D: bzzzz ✅
// char x (char a) {
//     if (a<='c')
//     printf("%c", x(a+1));
//     else
//     printf("b");
//     return 'z';
// }
// void main() { 
//     printf("%c",x('a'));
// }


// InformaticaII_FINAL_FEB_2011 ##############################################

// 2.1 - C: 9 ✅
// void main() { 
//     int a=9, b=13, c=-3, d=8;
//     int *bb, **cc;
//     bb=&a;
//     cc= &bb;
//     (*bb)++;
//     a= 5;
//     **cc = **cc + 4;
//     cc = &d;
//     printf("%d", *bb);
// }

// 2.2 - E. wwww ✅
// char x (char a) {
//     if (a<='w')
//     printf("%c", x(a+1));
//     return 'w';
// }
// void main() { 
//     printf("%c",x('u'));
// }

// 2.3 - B: 893456789 ✅
// void main() { 
//     char *b = "3456789";
//     char * p = b;
//     p += 5;
//     printf( "%s%s", p,b ); 
// }

// 2.4 - D: 15 ✅
// void main() { 
//     unsigned char a;
//     a= ~( (~0) << (1<<2));
//     printf("%d",a);
// }


// InformaticaII_FINAL_FEB_2013 ##############################################

// 2.1 - c: 2 ✅
// int retorno(int valor) {
//     if( valor != (valor&&valor) ) {
//         retorno(valor&valor);
//         if(valor!=1)
//         return 144;
//     }
// return 266;
// }
// void main() { 
//     printf("%d\n", retorno(1));
//     printf("%d\n", retorno(0));
//     printf("%d\n", retorno(2));
// }

// 2.2 - E: error ❌ -> C: 3 No es error porque sobreescribe "uno"
// int main() {
//     int a[]={1,3,5,7,9,0};
//     int *uno=NULL, dos=0;
//     uno = a;
//     dos= *(uno + *uno);
//     printf("dos: %d\n", dos);
//     return 0;
// }

// 2.3 - D: 15 ✅
// void main() { 
//     unsigned char a;
//     a= ~( (~0) << (1<<2));
//     printf("%d", a);
// }

// 2.4 - A: Siempre muestra rojo ✅
// void funcion(int a, int b) {
//     if ( (a << b) > a )
//         printf("rojo");
//     else
//         printf("negro");
// }
// void main() { 
//     funcion(2,1);
// }

// InformaticaII_FINAL_JULIO_2011b ##############################################

// 2.1 - B: ab ❌ -> D: aa. No tiene {} en el if y se corta en return 'a'
// char x (char a) {
//     if (a<'b')
//     printf("%c", x(a+1));
//     return 'a';
//     if (a>='b')
//     return 'b';
// }
// void main() {
//     printf("%c",x('a'));
// }

// 2.2 - B: FAAAaAAA ✅
// void recursiva(char *nombre, int i) { 
//     char aux;
//     if(*nombre!='\0' )
//         { recursiva(nombre+1, i+1);
//     if(*nombre>'a' && *nombre<'z')
//         { *nombre=65; }
//     else
//         { *nombre=*nombre&255; }
//     }
// }
// int main() { 
//     char nombre[]="Fernando";
//     recursiva(nombre, 1);
//     printf("%s",nombre);
// }

// 2.3 - D: 993456799 ✅
// void main()
// {
//     char b[] = "3456789";
//     char * p = b+5 ;
//     int i=0;
//     while(*(b+i)!='\0')
//     i++;
//     while(i>0 && *p<'9')
//     {
//     i--;
//     *p=*p+1;
//     }
//     printf( "%s%s", p,b );
// }

// 2.4 - B: 1 ❌ -> F: 65. WHY? No hay por que
// void main() {
//     unsigned char a;
//     a = ( ~ ((31<<1)) & 127);
//     printf("%d",a);
// }
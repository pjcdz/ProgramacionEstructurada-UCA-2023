#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** 1<<7 = 1 0 0 0 0 0 0 0 = 128 = 2^7
//  1<<6 = 0 1 0 0 0 0 0 0 =  64 = 2^6
//  1<<5 = 0 0 1 0 0 0 0 0 =  32 = 2^5
//  1<<4 = 0 0 0 1 0 0 0 0 =  16 = 2^4
//  1<<3 = 0 0 0 0 1 0 0 0 =   8 = 2^3
//  1<<2 = 0 0 0 0 0 1 0 0 =   4 = 2^2
//  1<<1 = 0 0 0 0 0 0 1 0 =   2 = 2^1
//  1<<0 = 0 0 0 0 0 0 0 1 =   1 = 2^0*/

/** 0 1 1 1 1 1 1 1 = 127 = 2^7 - 1
//  0 0 1 1 1 1 1 1 =  63 = 2^6 - 1
//  0 0 0 1 1 1 1 1 =  31 = 2^5 - 1
//  0 0 0 0 1 1 1 1 =  15 = 2^4 - 1
//  0 0 0 0 0 1 1 1 =   7 = 2^3 - 1
//  0 0 0 0 0 0 1 1 =   3 = 2^2 - 1
//  0 0 0 0 0 0 0 1 =   1 = 2^1 - 1
//  0 0 0 0 0 0 0 0 =   0 = 2^0 - 1*/

//256 es todo 0 para char, mientras que para los int no
/**  0 0 0 0 0 0 0 1 | 0 0 0 0 0 0 0 0 = 256 = 2^8
//   0 0 0 0 0 0 0 0 | 1 1 1 1 1 1 1 1 = 255 = 2^8 - 1*/

//alcances: signed char o char = -128 a +127
//          unsigned char = 0 a 255
//para los int vale lo mismo pero son 32 bits, mayor numero de alcance


/*int main(){*/
/*	unsigned char a=1;*/
/*	unsigned int i;*/
/*	for(i=0;i<8;i++){*/
/*		a=a&(1<<i);*/
/*	}*/
/*	printf("\n%d",a);*/
/*}*/
/*//Retorna 0 porque 1<<i cuando i es 7 es 1 0 0 0 0 0 0 0
//mientras que a es                      0 0 0 0 0 0 0 1
//con & las columnas que no tengan 1 1 devuelven 0*/


/*char f(char a){*/
/*	if (a<'c')*/
/*	f(a+1);*/
/*	else{*/
/*	if (a=='b')*/
/*	f(a+1);*/
/*	}*/
/*	return a;*/
/*}*/
/*int main()*/
/*{*/
/*	printf("%c",f('b'));*/
/*	return 0;*/
/*}*/

//devuelve b la recursiva ya que primero entra con b, luego analiza
//para el valor c, pero no cumple las condiciones de la funcion
//por lo que termina de analizar para c, luego vuelve para b
//y termina retornando ese valor*/


/*int main(){ */
/*	int* p=NULL;*/
/*	(*p)=10;*/
/*	printf("%d",*(p)+1);*/
/*	return 0;*/
/*}*/
//Hay un error ya que no se reservó nunca el espacio de memoria
//necesario para p*/

/*void f(){ */
/*	int a=9, b=13;*/
/*	int *bb, **cc;*/
/*	bb=&b;*/
/*	cc= &bb;*/
/*	printf("%d", *bb+1);*/
/*}*/
/*int main(){*/
/*	f();*/
/*}*/
//retorna 14 ya que *bb esta llamando al valor al que apunta bb
//que en este caso es b, cc=&bb no afecta ya que decimos que cc,
//apunta al puntero que apunta a b, no afecta nada*/


/*void sum (int arr[]){*/
/*	arr[0] = arr[0]+3;*/
/*}*/
/*void resta (int a){*/
/*	a= a - 4 ; //no modifica la variable del main*/
/*}*/
/*int main(){*/
/*	int a[3]={3,2,13}; int num=0;*/
/*	sum(a);*/
/*	resta(num);*/
/*	printf("%d",a[0] + num);*/
/*	return 0;*/
/*}*/
//retorna 6, el num es 0 siempre en el main*/


int Foo(int n,int m)
{
	int miFoo = 1;
	if(m>0){
	miFoo=n*Foo(n,m-1);
	}
	return miFoo;
}
int main(){
	printf("%d",Foo(3,4));
}
//esta haciendo una exponencial n a la m, en este caso 3 a la 4
//que nos da 81*/


/**int main()
{
char* s[5]; int i=0;
char c='2';
s[i]=&c;
for(i=0;i<5;i++){
s[i]=&c;
c=c+1;
}
printf("(%d, %d)", (c=='2'), !(s[0]==&c));
return 0;
}
//retorna (0,0) ya que c no vale mas '2' y s[0] sigue apuntando
//al espacio de memoria de c siempre*/


/**int main(){
char* s=NULL; int i;
//s=(char*) malloc(1*sizeof(char));
for(i=0;i<4;i++){
*(s+i)='a'+i;
}
s[i]='\0';
printf("%s",s);
return 0;
}
//No imprime, tiene un error ya que no esta tomando espacio en la
//memoria con un malloc*/


/**int foo(unsigned char n,unsigned char filter){
return n&((255&(filter<<n+n))>1);
}
void main()
{
printf("%d",foo(3,4));
}
//filter<<n+n nos da filter<<6, es decir 4 es 0 0 0 0 0 1 0 0
//si lo corremos 6 veces 1|0 0 0 0 0 0 0 0 que es 256, o 2^8
//entonces 256 & 255 es 0 0 0 0 0 0 0 0 & 1 1 1 1 1 1 1 1 que es 0*/


/**void sum (int arr[]){
*arr = *arr +3;
}
void resta (int a){
a= a - 4 ;
}
int main(){
int a[3]={3,2,13}; int num=1;
sum(a);
resta(num);
printf("%d",*a + num);
return 0;
}
//retorna 7 ya que la funcion sum si modifica el arreglo del main
//ya que esta apuntando a la primer posicion del mismo con el puntero
//pero resta no afecta a las cosas del main*/


/**void f(){
int a=9, b=13;
int* ar[2];
ar[0]=&a;
ar[1]= &b;
printf("%d", *ar[0]+*ar[1]);
}
int main(){
f();
return 0;
}
//es valido el planteo que nos da el problema, el resultado es 22*/


/**int doble(int valor)
{
int entero=16;
entero=(valor<<20)&16;
return entero;
}
void main()
{
printf("%d",doble(a));
}
//retorna 0 para todo a*/


/**int main()
{
char *ptrA = "Juan";
char *ptrB = "Pedro";
ptrA = ptrA + 4;
for(;*ptrB!='\0';ptrB++);
printf("%c", *ptrA);
}
//no imprime nada porque ptrA + 4 es \0 ya que Juan es J0 u1 a2 n3 \04*/


/**void main()
{unsigned char a;
a= ~0 << ((sizeof(unsigned char)*8)-1);
printf("%d",a);
}
//retorna 128, ya que al ser un char, solo nos interesa lo que
//ocurre en el primer Byte, ~0 es todo 1, y si lo corremos a la
//izquierda 7 veces 1 0 0 0 0 0 0 0, eso es 128*/

/**char x (char a)
{
if (a<='c')
printf("%c", x(a+1));
else
printf("b");
return 'z';
}
void main()
{ printf("%c",x('a'));
}
//por la recursividad imprime bzzzz, primero recorremos hasta a='d'
//luego se empieza a ejecutar, imprime b por el else una unica vez
//y luego todos los return z*/

/**void main(){
int a=9, b=13, c=-3, d=8;
int *bb, **cc;
bb=&a;
cc= &bb;
(*bb)++;
a= 5;
**cc = **cc + 4;
cc = &d;
printf("%d", *bb);
}
//Retorna 9 ya que el **cc sigue apuntando a *bb antes de apuntarlo
//a d*/


/**char x (char a)
{
if (a<='w')
printf("%c", x(a+1));
return 'w';
}
void main()
{ printf("%c",x('u'));
}
//Retorna wwww, el print en char solo hace que funcione la recursiva
//pero lo que se imprime es lo q se retorna*/


/**void main(){
char *b = "3456789";
char * p = b;
p += 5;
printf( "%s%s", p,b );
}
//retorna 893456789 el 89 es el que corresponde a *p, ya que
//con el p += 5 estamos corriendo 5 posiciones del arreglo dinamico*/

/**void main(){
unsigned char a;
a= ~( (~0) << (1<<2));
printf("%d",a);
}
//retorna 15 ya que 1<<2 es 4 osea 0 0 0 0 0 1 0 0
//~0 es 1 1 1 1 1 1 1 1 si lo corremos 4 veces
// ~0<<4 es 1 1 1 1 0 0 0 0
//y queda 0 0 0 0 1 1 1 1 el primer 0 luego de los unos esta
//corresponde a 2^4, y como tiene todos 1 antes, ese numero es
//2^4 - 1 osea 15*/


/**int retorno(int valor)
{
if( valor != (valor&&valor) )
{
retorno(valor&valor);
if(valor!=1)
return 144;
}
return 266;
}
void main()
{
printf("%d",retorno(0));
}
//No funciona para numeros distintos de 0 o 1, se hace un loop infinito*/


/**int main()
{
int a[]={1,3,5,7,9,0};
int *uno=NULL, dos=0;
uno = a;
dos= *(uno + *uno);
printf("dos: %d\n", dos);
return 0;
}
//retorna 3 ya que el dos= *(uno + *uno); esta coriendo el arreglo
//una posicion para la derecha y retorna ahora esa primer posicion
//nueva que es el 3*/

/**void main()
{
int a = 1, b=8;
if ( (a << b) > a )
printf("rojo");
else
printf("negro");
}
//siempre devuelve rojo, ya que a y b son enteros positivos >0
//a a los corres b posiciones para la izquiera, por lo que lo
//estamos haciendo un numero mayor que a, entonces el if es
//true y entra a la parte de rojo*/


/**char x (char a)
{
if (a<'b')
printf("%c", x(a+1));
return 'a';
if (a>='b')
return 'b';
}
void main()
{
printf("%c",x('a'));
}
//retorna aa ya que el return 'a' no esta adentro del if, esta afuera
//entonces ya está retornando a sin entrar al segundo if, y la funcion
//se recorre 2 veces nada mas ahora, si pusieramos las llaves para
//que el return 'a' este adentro del if, ahi si retornaria ba*/


/**int main()
{ char nombre[]="Fernando";
recursiva(nombre, 1);
printf("%s",nombre);
}
void recursiva(char *nombre, int i)
{ char aux;
if(*nombre!='\0' )
{ recursiva(nombre+1, i+1);
if(*nombre>'a' && *nombre<'z')
{ *nombre=65; }
else
{ *nombre=*nombre&255; }
}
}
//retorna FAAAaAAA, recordemos que como es recursiva, va transformando
//en A a todas las minusculas menos la a y la z de atras para adelante
//el else no hace nada ya que *nombre&255 devuelve la misma letra*/


/**void main()
{
char b[] = "3456789";
char * p = b+5 ;
int i=0;
while(*(b+i)!='\0')
i++;
while(i>0 && *p<'9')
{
i--;
*p=*p+1;
}
printf( "%s%s", p,b );
}
//retorna 993456799, ya que el puntero p esta apuntando al 89
//entonces si modificamos *p nos da 99 pero b tambien cambia ya
//que lo esta apuntando el puntero y queda 3456799*/


/**void main()
{
unsigned char a;
a = ( ~ ((31<<1)) & 127);
printf("%d",a);
}
//retorna 65 que es 0 1 0 0 0 0 0 1, como no está separado por parentesis
//el codigo se recorre de izquierda a derecha*/


/**void main(){
int a=9, b=13, c=-3, d=8;
int *bb, **cc;
bb=&a;
cc= &bb;
(*bb)++;
a= 5;
**cc = **cc + 4;
*cc = &d;
printf("%d", *bb);
}
//retorna 8 ya que el *cc hace que bb apunte a d que es 8*/


/**char x (char a)
{
if (a>'w')
printf("%c", x(a-1));
return 'w';
}
void main()
{ printf("%c",x('y'));
}
//devuelve www ya que el loop se repite 3 veces para y x w
//y retorna w en los 3 casos*/


/**void main(){
unsigned char a;
a= ( (1) << (1<<2));
printf("%d",a);}
//retorna 16 que es 1<<4 0 0 0 1 0 0 0 0*/


/**void main(){char a;
a= ((((1) << (1<<2)) >> 4) & 255) << 7;
printf("%d",a);}
//como no está el unsigned, la variable puede tomar valores negativos
//por eso es que da -128*/


/**void main(){char *b = "12345";
char * p = b;
int i;
for(i=0; *(p+i)!='\0';p++);
printf( "%s%s", p,b );}
//retorna 12345 ya que p despues del bucle va a estar en la posicion
//del \0 y despues es todo \0, nulo*/


/**void main(){unsigned int i=0;
for(i=1;i<10;i=i<<1)
{
printf("%d", i);
}}
//imprime 1248 ya que primero i=1, lo corremos 1 ahora i=2,
//ahora lo corremos devuelta i=4, y luego i=8  pero si lo volvemos
//a correr se pasa de 10*/


/**char x (char a)
{
if (a<='D')
printf("%c", x(a+1));
else
{
printf("%c", a);
return a-1;
}
return a;
}
void main()
{
printf("%c",x('A'));
}
//devuelve EDDCBA, notemos que el return a-1 en el else hace que
//se imprima una D de mas, siempre que pise un return en la
//recursiva, vamos a ver que pasa en el main*/


/**void main()
{
char* s[5]; int i=0;
int* x=NULL;
char c = '\0';
s[i]=&c;
for(i=0;i<5;i++){
s[i]=&c;
c=c+1;
}
printf("(%d, %d)",(c=='2'),(*s!=&c));
}
//retorna (0,0) ya que c no es igual a 2 y *s si apunta a c,
//cosa q nos estan diciendo que no es asi*/


/**void main()
{
char* s=NULL;int i;
char* x=malloc(sizeof(char));
//s=malloc(sizeof(char)); //con esto funciona
for(i=0;i<4;i++)
*(s+i)='a'+i;
s[i]='\0';
printf("%s",s);
}
//no retorna, hay un error ya que para el char* s no estamos
//asignandole memoria, al q le asignamos es a x, si estuviese
//el termino que comente, ahi si imprime abcd, o si usaramos a x
//en el codigo original tamb andaria*/


/**char foo(unsigned int w)
{
unsigned int x=0;
int i=0;
char ar[20] = "JUEVES";
x=x|(unsigned int)ar[i];

for(i=1;ar[i]!='\0';i++){
x=x<<8;
x=x|(unsigned int)ar[i];
}
//aca x seria EVES entonces al correrlo 24 veces para la
//izquierda, obtenemos la E
return (char)((x&(255<<w))>>w);
}
void main()
{
printf("%c",foo(24));
}*/


/**struct s_dato{
char c;
int n;
};typedef struct s_dato t_dato;
void main()
{
t_dato* p=malloc(sizeof(t_dato));
t_dato** p2=&p;

(*p).n=10;
(*p2)->n=10;
//(*p2)->n=a;
//((*p).n)+(*p2)->n = a + a ya que *p2 maneja a p

printf("%d",((*p).n)+(*p2)->n);
}
//imprime 20, no hay error en el proceso*/


/**void sum(int* arr)
{
*arr=*arr + 3;
}
void resta(int* a)
{
*a=*a-1;
}
void main()
{
int a[4]={3,2,13,4};
int num = 3;
sum(a);
resta(&num);
printf("%d",*(a+num));
}
//el *(a+num) toma el valor del arreglo corrido por num, que es 2
//en este caso, asi que toma el 13*/

/**void main()
{
int c,r;
FILE* archT=fopen("arch.txt","w");
fprintf(archT,"%s","Hola");
fprintf(archT,"%s"," mundo");
fclose(archT);

FILE* archB=fopen("arch.txt","rb");
r=fread(&c,1,1,archB);
while(!feof(archB)){
printf("%c",c);
r=fread(&c,1,1,archB);
}
fclose(archB);
}
//imprime bien el Hola mundo*/


/**void main()
{
printf("int: %20d", sizeof(int));
printf("\nint[10]: %17d", sizeof(int[10]));
printf("\nint*: %19d", sizeof(int*));
printf("\nchar: %19d", sizeof(char));
printf("\nchar[10]: %16d", sizeof(char[10]));
printf("\nchar*: %18d", sizeof(char*));
printf("\ndouble: %17d", sizeof(double));
printf("\ndouble[10]: %14d", sizeof(double[10]));
printf("\nunsigned int: %11d", sizeof(unsigned int));
printf("\nunsigned char: %10d", sizeof(unsigned char));
}*/


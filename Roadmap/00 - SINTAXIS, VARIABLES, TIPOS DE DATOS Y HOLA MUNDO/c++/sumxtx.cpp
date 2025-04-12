/**
 * #00 SINTAXIS, VARIABLES, TIPOS DE DATOS Y HOLA MUNDO
 * author sumxtx
 * version 1.0  language c++17
 * date 2025-04-11
 */

// Cometarios de una linea
// Referencia Oficial para C++17  https://en.cppreference.com/w/cpp/17

/*
 * Comentarios Multilinea
 * C++ tiene versiones mas avanzadas que la 17, pero utilizare esta por compatibilidad
 *
 * La Web de Referencia Oficial es bastane arcana, prefiero Geek For Geeks
 * https://www.geeksforgeeks.org/cpp-data-types/
 *
 */

/*
 C++ es bastante infame por ser inseguro en terminos de memoria
 pero a la ves es un lenguaje bastante potente y eficiente no es en vano que
 se usa en Sistemas Operativos, Game Engines, Aplicaciones que requieren poca latencia

 Rust esta siendo mas recomendado para produccion y entornos donde la seguridad
 es importante y se supone que sera un C/C++ Killer, pero es mas complejo que este
 A la ves que muchisimas aplicaciones estan hechas en C++ entonces no va a 
 ser sustituido de la noche a los proximos 30 anos

 Dicho todo eso, sumamente me gusta aprender C/C++ como lenguaje "Academico",
 Nos permite trabajar sin "muchas" Abstracciones 
 que nos quitan entendimiento de como funciona la maquina,
 Y el cometer muchos errores nos dan todavia mas entendimiento

 A la ves nos trae mas features que C, como Objectos y algunos tipos de datos
 que son mas seguros como std::string, std::vector, etc...
*/


#include <iostream>
/*
  C++ usa #include para importar.

  iostream es el responsable de input, output, y otras cosas relacionadas
  de momento veremos:

  std::cout   -> Imprimir por pantalla

  std::endl   -> Es un salto de linea on steroids
                 limpia el buffer para evitar errores y otras vainas
                 es preferible a usar '\n' 
*/

#include <limits.h>
/*
  Limites nos traes maximos y minimos que puede holdear un tipo de dato
  Lo usare con ejemplos mas adelante, se suele usar por compatibilidad entre
  diferentes arquitecturas ya que por ejemplo en 32 bits y 64 bits los valores
  MAX y MIN son diferentes de un int son diferentes
  entonces el lenguaje ya nos trae esa facilidad
*/

// Estos seran mas para demonstraciones
// A programas cortos utilizaremos mas <iostream>, <string>
#include <bitset>
#include <cfloat>
#include <stdlib.h>

int main(void)
{
  // A lo largo de los tipos de datos ya veremos tambien sus modificadores
  // unsigned, short, signed, long, etc...
  
  /****************************************************************************/
  /* char - Representa 1 byte (8 bits) se suele utilizar para characteres     */
  /****************************************************************************/
  char c = 'A'; // sera traducido en memoria a 01000001

  std::cout << "Amount of BITS used by char: " << CHAR_BIT << std::endl;
  std::cout << "Minimum value for a char type: " << CHAR_MIN << std::endl; 
  std::cout << "Minimum value for a char type: " << CHAR_MAX << std::endl;
  std::cout << "Value of c: " << c << std::endl;

  // peeero...
  char a = 65; // sera tambien traducido en memoria a 01000001
               // entonces es el mismo valor
  std::cout << "Value of a: " << a << std::endl;
  // char se trabaja mucho ASCII https://www.ascii-code.com/
  // pero si quieres holdear un numero que es bastante
  // corto de 127 a -128 o de 0 a 255 para unsigned char
  // y no quieres usar 4 bytes que es lo minimo para int, puedes usar char

  char edad = 5;
  char edadEn5yr = edad + 5;
  std::cout << edadEn5yr << std::endl;
  // Porque no aparece nada?
  // Porque como he dicho al imprimir usara el valor ascii
  // el numero 10 es un \n salto de linea
  
  // Entonces puede parecer inutil por ahora, pero es bueno saberlo
  
  /***********        Modificadores       ***********/
  
  unsigned char uc = 6;
  signed char sc = -6;

  std::cout << "Maximun value for an unsigned char type: " << UCHAR_MAX << std::endl; 
  std::cout << "Minimum value for a signed char type: " << SCHAR_MIN << std::endl; 
  std::cout << "Maximun value for a signed char type: " << SCHAR_MAX << std::endl; 
  // Usigned MIN es 0 entonces es indiferente usarlo
  // Y si no especifica nada por lo general siempre es signed
  // en que se diferencian unsigned y signed a nivel binario
  // que el primero digito ya no se usara para el signo si no para mas numero
  // entonce son capaces de guardar numeros mas largos
  
  // convertiremos a binario para demonstracion
  std::cout << "uchar 6 in binary:  " << std::bitset<8>(uc) <<std::endl;
  std::cout << "schar -6 in binary: " << std::bitset<8>(sc) << std::endl;

  //Output: uchar 89 in binary:  01011001
  //Output: schar -89 in binary: 10100111
  // como vemos en el ejemplo, no neceseriamente solo se pone un uno al principio
  // los demas tambien cambian,
  // https://www.geeksforgeeks.org/representation-of-negative-binary-numbers/
  //
  // Interesante los binarios, verdad? *_*

  /****************************************************************************/
  /* int - Representa 4 bytes (32 bits) se suele usar para numeros enteros    */
  /****************************************************************************/

  int x = 89; // == signed int
  std::cout << "Value of x: " << x << std::endl;
  std::cout << "Minimun value for int: " << INT_MIN << std::endl;
  std::cout << "Maximun value for int: " << INT_MAX << std::endl;

  /***********        Modificadores       ***********/
  short int shx;
  unsigned short int ushx;
  unsigned int ux;
  signed int sx;
  long int lx;
  unsigned long int ulx;
  long long int llx;
  unsigned long long int ullx;
  
  std::cout << "Minimun value for a short int: "<< SHRT_MIN << std::endl;
  std::cout << "Maximun value for a short int: " << SHRT_MAX << std::endl;
  std::cout << "Maximun value for an unsigned short int "<< USHRT_MAX << std::endl;
  std::cout << "Minimun value for an integer "<< INT_MIN << std::endl;
  std::cout << "Maximun value for an integer "<< INT_MAX << std::endl;
  std::cout << "Maximun value for an unsigned integer "<< UINT_MAX << std::endl;
  std::cout << "Minimun value for a long integer  "<< LONG_MIN << std::endl;
  std::cout << "Maximun value for a long integer "<< LONG_MAX << std::endl;
  std::cout << "Maximun value for an unsigned long "<< ULONG_MAX << std::endl;
  std::cout << "Minimun value for a long long integer "<< LLONG_MIN << std::endl;
  std::cout << "Maximun value for a long long integer "<< LLONG_MAX << std::endl;
  std::cout << "Maximun value for an unsigned long long integer "<< ULLONG_MAX << std::endl;

  // Que pasa si una suma me va a rebozar la capacidad maxima que tiene
  // un tipo de dato y darme otro valor completamente diferente
  // EX:
  std::cout << "Overflow by 2 of an INT_MAX: "<< INT_MAX + 2;
  std::cout << " == "<< INT_MIN + 1 << std::endl;
  // El compilador te tirar un warning
  // Si no tienes nada que diga que quieres tratar a  los warnings
  // como errores y no compilar ( g++ -Werror file.cpp ) no pasara nada 

  // Cuando se rebosa simplemente hace un ciclo y sigue
  // Output >> Overflow by 2 of an INT_MAX: -2147483647 == -2147483647
  // Como vemos rebasa y empieza otra ves por la parte de los negativos 

  //Ahora como evitar esto, otra utilidad de los LIMITES

  int num1 = 2147483627;
  int num2 = 20;
  if (!(num2 > INT_MAX - num1))
  {
    std::cout << "num1: " << num1 << " + num2: "<< num2 << " = " << num1 + num2;
    std::cout << " -> Hasta aqui todo bien" << std::endl;
  }

  // num2 estaba al limite, fue bien. Pero, y si le subimos uno mas
  num2++;
  if (num2 > INT_MAX - num1)
  {
    std::cout << "num1: " << num1 << " + num2: "<< num2 << " = " << num1 + num2;
    std::cout << " -> Aqui ya te la lia " << std::endl;
  }

  /****************************************************************************/
  /* booleans - Representa 1 byte se suele usar para true false               */
  /****************************************************************************/

  bool isTrue = true;     // representado internamente como 1
  bool isFalse = false;   // representado internamente como 0

  if(isTrue)
  {
    std::cout << "true: " << isTrue << std::endl;
  }
  if(!(isFalse)) // not is false , aqui mas que nada para que 
                 // la condicion se cumpla porque si no 0
                 // computara como que no existe, si ponemos if(isFalse) 
                 // se entendera internamente como que false no existe
  {
    std::cout << "false: " << isFalse << std::endl;
  }
  if(isFalse)
  {
    std::cout << "Eso no se imprimira" << std::endl;
  }
  
  //sizeof
  // Ya que booleans es bastante straight-forward pongo aqui sizeof para que vean
  // como checkear el size de un numero en memoria

  std::cout << "sizeof bool: " << sizeof(bool) << std::endl;
  std::cout << "sizeof true: " << sizeof(true) << std::endl;
  std::cout << "sizeof false: " << sizeof(false) << std::endl;
  // como vemos aunque bool sea false sigue ocupando espacion en memoria
  
  // Ademas sirve para los otros tipos de datos
  std::cout << "sizeof int: " << sizeof(int) << std::endl;

  /****************************************************************************/
  /* float - Representa 4 bytes se usa para decimales de corta precision      */
  /****************************************************************************/

  float fl = 36.5;
  float fln = -36.5;
  float fld = 0.05;
  float fldn = -0.05;
  //Bueno con "corta"

  std::cout << "Maximun Positive float: " << FLT_MAX << std::endl;
  std::cout << "Minimun Positive float: " << FLT_MIN << std::endl;
  std::cout << "sizeof float: " << sizeof(float) * 8 << "bits" << std::endl;


  /* No os preocupeis por este cacho, es simplemente para poder "enganar"
    el constructor de bitset para poder imprimir el numero en binario por pantalla 
    si no no da el valor que toca, y lo mas interesante de los floats 
    ocurre a como es representado en binario */
  std::cout << "Positive Float in binary:  " << std::bitset<sizeof(float)*CHAR_BIT>(*reinterpret_cast<unsigned long*>(&fl)) <<std::endl;
  // Positive Float in binary:  01000010000100100000000000000000
  std::cout << "Negative Float in binary:  " << std::bitset<sizeof(float)*CHAR_BIT>(*reinterpret_cast<unsigned long*>(&fln)) <<std::endl;
  // Negative Float in binary:  11000010000100100000000000000000
  std::cout << "Positive Decimal Float in binary:  " << std::bitset<sizeof(float)*CHAR_BIT>(*reinterpret_cast<unsigned long*>(&fld)) <<std::endl;
  // Positive Decimal Float in binary:  00111101010011001100110011001101
  std::cout << "Negative Decimal Float in binary:  " << std::bitset<sizeof(float)*CHAR_BIT>(*reinterpret_cast<unsigned long*>(&fldn)) <<std::endl;
  // Negative Decimal Float in binary:  10111101010011001100110011001101

/* Veamos esta maravilla de la Arquitectura de Ordenadores en Binario:

   Negative Float en binario:   1 10000100 00100100000000000000000  = -36.5
                                ^ ^------^ ^---------------------^
                                S    E         M
            en bits             1    8         23       = 32 bits

   S - Signo      - 0 Positivo 1 Negativo
                  - Entonces aqui tenemos (-1) x ....
   
   E - Exponente  - Aqui es al reves el  primero digito es 1 Positivo 0 Negativos
                  
                  Porque tenemos que restarle 127, eso se llamara bias 
                  - 11111111 -> El Maximo posible es 255, 255 -127 = 128 
                  - 01111111 -> El Maximo sera 127, 127 - 127 = 0
                  
                  Entrando en terreno de los exponentes negativos
                  - 01111110 -> sera 126, 126 - 127 = -1

                  por ejemplo 10000100 = 132 si lo sustraimos 127 = 5
                  es bastante confusillo, solo asume que lo que te digo es vrdd
                  no vamos a crear una CPU asi que solo entiende esto 
                  numero de binario a decimal - 127 = exponente 

                  Entonces tenemos (-1) x 2e5 ..........

   M - Mantissa   - La mantisa tiene un 1. implicito
                    y va de izquierda a derecha en negativo
                    y se veria asi el calculo:

                    2e0    2e-1  2e-2  2e-3    2e-4  2e-5  2e-6
                    1 *  . 0 *   0 *   1 *     0 *   0 *   1 *
                    ----------------------------------------------------------
                    1 +    0 +   0 +   0.125 + 0 +   0 +   0.015625 = 1.140625

  por lo tanto tenemos:
                    (-1) x 2e5 x 1.140625 = -36.5


  Floats y Doubles son toda una movida por si proprios a nivel binario
   
   Si quieres verlo en detalle te recomiendo estos videos:
   https://www.youtube.com/watch?v=yvdtwKF87Ts
   https://www.youtube.com/watch?v=PZRI1IfStY0
   https://www.youtube.com/watch?v=bbkcEiUjehk

*/

  /****************************************************************************/
  /* double - Representa 8 bytes se usa para decimales de larga precision     */
  /****************************************************************************/
  
  double pi;

  std::cout << "Maximun Positive double: " << DBL_MAX << std::endl;
  std::cout << "Maximun Positive double: " << DBL_MIN << std::endl;

  // Maximun Positive double: 1.79769e+308
  // Maximun Positive double: 2.22507e-308
  // Maximun Negative double: -1.79769e+308
  // Mininum Negative double: -2.22507e-308

  // La conversion se hara igual que de binario a float
  // Salvo que el exponente tiene  11 bits
  // y la Mantissa 52 bits

  /****************************************************************************/
  /* Modificador - const - Constantes, Valores inmutables                     */
  /****************************************************************************/
  
  // Hace que un valor de la variable no se pueda modificar

  //const double PI;          // Y si nos fijamos ya tambien distingue mayusculas
  const double PI = 3.14;     // Y tiene que ir siempre inicializada si no no compila


  /****************************************************************************/
  /* void - Representa la ausencia de valor se usa para pointer variables     */
  /****************************************************************************/

  // Aparte se usa tambien para funciones que no retornan nada


  /****************************************************************************/
  /* Typecasting - Convertir de un tipo a otro                                */
  /****************************************************************************/

  // Os acordais de aquel 10 que nos sacaba un salto de linea,
  // que tal si ahora se sacamos como 10, pero eso conllevara pasarlo a int

  std::cout << (int)edadEn5yr << std::endl; 


  // Bonus: Entrando en terreno fandagoso mallocs vamos a ver un casting con void
  // malloc se usa para alojar memoria dinamicamente y es uno de los causantes del 70%
  // de los leaks de memoria
  // malloc nos va a retornar un puntero al inicio de la direccion de memoria asignada
  // por lo tanto un void porque no es un valor realmente si no una direccion
  // void *malloc(size); luego lo para usarlo lo castearemos al tipo que queramos
 
  int *ptr = (int *) malloc(sizeof(int) * 10);
  // Ahora tenemos un bloque contiguo de memoria, o un array, que cabe 10 ints
  // Lo que se asigna manual se libera manual, por lo tanto hemos de llamar 
  // un free para cada malloc que hagamos
  free(ptr);
  // Y asignarlo ademas a NULL o su equivalente en C++ nullptr asi no tenemos
  // un pointer "suelto", que tambien es un bug
  ptr = nullptr;

  // pero lo dejaremos por aqui... Ya que C++ tiene mejores formas de asignar memoria
  // eso de malloc viene del legado de C

  
  return 0;
}

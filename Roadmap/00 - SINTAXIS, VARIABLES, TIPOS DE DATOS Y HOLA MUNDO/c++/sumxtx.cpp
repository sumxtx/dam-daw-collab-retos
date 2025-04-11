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

#include <bitset>
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

  return 0;
}

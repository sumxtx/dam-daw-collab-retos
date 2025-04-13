/******************************************************************************/
/* Declaracion de Funciones                                                   */
/****************************************************************************//*
  En ocasiones podremos ver aqui arriba la declaracion o la defincion 
  de la funciones ya que C++ al compilar va de arriba hacia abajo,
  entonces si no hay una declaracion, o bien la definicion de la funcion
  y la necesita usar en un bloque anterior a donde fue definida 
  nos va a tirar un error
  ejemplo:
  
  Sale mal                  ||    O bien pones las funciones en orden o puedes
                            ||    poner solo la declaracion de la funcion
  -----------------------------------------------------------------------------
                            ||
  int main()                ||  int func3();      // No importa el orden
  {                         ||  int func2();      // tanto en la Declaracion
    func1(...);             ||  int func1();
  }                         ||
  int func1(int x)          ||  int main()
  {                         ||  {...};
    return func3(x)         ||
  }                         ||  int func1(){...}; // Cuanto en la 
  int func3(int x)          ||  int func2(){...}; // Definicion
  {                         ||  int func3(){...};                             
    return func2(x);        ||
  }                         ||
  int func2(int x)          ||
  {                         ||
    return x;               ||
  }                         ||
  -----------------------------------------------------------------------------
   https://cplusplus.com/articles/Gw6AC542/

// HEADERS
  Tambien puedes crear headers para separar las declaraciones, definiciones
  y mantener mas organizado los codigos mas largos, y para flexibilidad si quieres
  usarlos en distintos sitios,

  por ejemplo puedes crear headers.h, libreria.h, utils.h ...
  poner alli la declaracion de las clases, funciones. 
  Luego tanto en el archivo donde se definenen esas funciones 
  cuanto donde se utilizan,
  hacer el #include del header.h

  Notese que el include creado por no nosotros, no los del sistema
  van entre comillas
  #include "header.h"

  Ejemplo:

      headers.h
+------------------------------+  #ifndef   es un header guard
| #ifndef HEADERS_H            |  lo que hace es que en programas muy largos 
| #define HEADERS_H            |  evita que un mismo se incluya varias veces
|                              |
| int func3();                 | la sintaxis sustytuye los puntos por _ 
| int func2();                 | y es en Mayusculas
| int func1();                 |  
|                              |
| #endif                       |
+------------------------------+  
                      
      utils.cpp
+----------------------+                 
| #include "headers.h" |  Aqui incluyemos el headers.h
|                      |  y definimos las funciones o las clases
| int func3()          |  
| { ... }              |  
|                      |  
| int func2()          |  
| { ... }              |  
|                      |  
|       ...            |  
+----------------------+  

      programa.cpp
+----------------------+ 
| #include "headers.h" |  Aqui incluyemos el mismo header
|                      |  y las utilizamos
|                      |
| int main()           |
| {                    |
|   func3();           |
|                      |
|   return 0;          |
| }                    |
+----------------------+

  Los nombres de los archivos si te fija  no tienen porque ser iguales pero
  mientras los headers lo sean, sin embargo por razones de claridad mejor poner
  nombres que sean iguales

  A la hora de compilar si el header esta en el mismo sitio,
  por ahora vamos a suponer que si, para no complicarlo mas,
  si hacemos:

  g++ programa.cpp utils.cpp 

  el compiler encontrar el header

*/

/******************************************************************************/
/* Retorno de las funciones                                                   */
/****************************************************************************//*
  Las funciones de arriba esperan un retorno de int, pero si no retornas nada
  no va a compilar, pues espera un retorno, si no retorna nada puedes usar void
  pero si es tipo void y retornas algo tampoco funciona

*/

/******************************************************************************/
/* La funcion main()                                                          */
/****************************************************************************//*

  main es la funcion principal de un programa en C++

  de momento le hemos ido pasando como parametro void, pero accepta dos parametro
  int main(int argc, char ** argv)
              int argc, es el counter de argumentos
              char** argv, es un doble puntero a los parametros pasados por cli
  un doble puntero es un puntero al inicio de un array de strings,
  que a su ves es un puntero al inicio de string

  argv[0] siempre sera el nombre del programa,
  argv[1] el primer parametro que le pasamos

  por ejemplo si lo compilamos como g++ sumxtx.cpp -o programa
  y lo ejecutamos como ./programa parametroX
  argv[0] = ./programa
  argv[1] = parametroX
  argc = 2
*/

// Ahora que sabemos todo esto, veamos algunos ejemplos
#include <iostream>

int multNumbers(int x, int y);

int addNumbers(int x, int y)
{
  return x + y;
}

int add_then_mult(int x, int y)
{
  x  = addNumbers(x, y);
  return multNumbers(x, y);
}

// int multNumbers(int x, int y); // Incluso si eso viniese aqui no funcionaria
                                  // Porque se la requiere antes y no esta declarad  

int main(int argc, char **argv)
{

  std::cout << argv[0] << std::endl;
  std::cout << argc << std::endl;

  std::cout << "2 + 2 = " << addNumbers(2, 2) <<std::endl;
  std::cout << "3 * 2 = " << multNumbers(3, 2) <<std::endl;
  std::cout << "(3 + 2) * 2 = " << add_then_mult(3, 2) <<std::endl;

  // Recogiendo un retorno de una funcion
  int mult = multNumbers(898, 8);
  std::cout << "898 * 8 = " << mult <<std::endl;


}

int multNumbers(int x, int y)
{
  return x * y;
}



/******************************************************************************/
/* La funcion main()                                                          */
/****************************************************************************//*


Esto seria lo basico de las funciones,
luego vienen, argumentos por defecto, scopes, paso por valor o por referencia,
overloading

Aunque que creo que es mejor irlos introduciendo a medidas que vayan saliendo otras
oportunidades, mas en contexto, porque asi es mas facil de entender y asimilar

*/

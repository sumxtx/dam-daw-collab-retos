#include <iostream>
#include <bitset>
#include <string>
#include <vector>

int main(void)
{
  /****************************************************************************/
  /* Operadores de asignacion                                                 */
  /****************************************************************************/

  int a1;       // Not initialized, garbage value
                // C++ no inicializa una variable automatica a 0, va tener basura
  std::cout << "I may contain garbage: " << a1 << std::endl;

  //auto a2;    // auto deja el compiler asignar el tipo de variable
  auto a2 = 0;  // pero para eso debe tener un valor, obviamente...
                // en codebase muy largos es considerado mala praxis
                // porque puede no dar contexto alguno del tipo de la variable
  std::cout << "I am initialized to : " << a2 << std::endl;

  int a3(5);    // Tambien se puede asignar asi, pero mehh
                // por compatibilidad mejor no hacerlo...
  std::cout << "I am initialized to : " << a3 << std::endl;

  int a4{6};    // Tambien se puede asignar asi, pero mehh
                // por compatibilidad mejor no hacerlo...
  std::cout << "I am initialized to : " << a4 << std::endl;


  int a5 = a4;  // Copy Initialization
  std::cout << "I am initialized to : " << a5 << std::endl;

  std::string s1 = "Hello"; // Modern String Type en C++ 
                            // tiene metodos, la longitud cacheada, y otras
                            // funcionalidades embutidas

                            //char d2[5] = "Hello";   // Esto seria un string, pero necesita el '\0' al final
                            // Junto con malloc, en legacy C es de lo que mas 
                            // da problemas y bugs ya que por ejemplo
                            // deberia ser de 6 la longitud y si viene como resulto
                            // de una funcion o lo que sea y no tiene el espacio
                            // para el '\0' como ahora  se lia
                            // ya paso a desuso por la opcion mas moderna y segura
  std::cout << "Correct String: " << s1 << std::endl;
  std::cout << "Correct String length: " << s1.size() << std::endl;

  // Array types 
  int array1[] = {2,4,5,6,7};                   // fixed size
  std::cout << sizeof(array1) / sizeof(int) << std::endl;

  // Vector types 
  std::vector<char> vec = {'H','e','l','l','o'};// more modern features
                                                // cached length, dynamic size, etc...
                                                // methodos como push_back, etc..
  std::cout << vec[1] << std::endl;
  std::cout << vec.size() << std::endl;

  // Hay mas, pero vamos a ir tirando con esto por ahora, hasta que se 
  // vayan dando las oportunidades

  /****************************************************************************/
  /* Operadores Aritmeticos, Logicos y bucles                                 */
  /****************************************************************************/

  /* For Loop Clasico */

  // Para la condicion inicial que suele ser una asignacion, 
  // hasta que no se cumpla la condicion intermedia que suele ser un logico
  // ejecuta la operacion que suele ser un operador aritmetico
  // y de reasignacion basado en la condicion intermedia

  // for(condicion inicial; condicion intermedia; operacion)

  for(int i = 0; i < 10; i++) 
    // para i inicial en 0, hasta que i no sea menor que 10, incrementa i, i = i + 1
    // ira de 0 a 9, ya que no estamos diciendo <= menor o igual a 10
  {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  /* While Loop */ 

  // Mientras se cumpla la condicion, haz algo
  // Es parecido al for loop, pero mas flexible,
  // ya que la condicion inicial se inicializa  fuera
  // y la operacion esta mas libre dentro del bucle

  int it = 0;
  while(it <= 10)       // comparacion menor o igual
  {
    it++;               // incrementamos it, it = it + 1
    std::cout << it << " ";
  }
  std::cout << std::endl;
  // Output > 1 2 3 4 5 6 7 8 9 10 11 

  /* Do-While */ 

  // Es como el while pero el while ya de entrada comprueba la condicion
  // el do-while realiza una primera iteracion en el bucle luego comprueba

  do
  {
    std::cout << it << " ";
    it--;               // decrementamos it, it = it -1
  } while(it >= 0);     // comparacion mayor o igual
  std::cout << std::endl;

  /* For range based */

  // Es como el for clasico pero mas moderno y suele usarse para operar 
  // en los datos colecciones como vector,string, etc..
  // aparte que no necesita un indice, ni una operacion
  // se usa cuando quieres iterar en todos miembros del objecto
  // pero hacerlo igual de flexible que el for clasico es mas complicado

  int array2[] = {2,4,5,6,7}; 
  auto res = 0;
  for(auto i : array2 ) // Aqui vemos un uso de auto, int valdria tambien
  {
    res += i;   // Suma y Asignacion += , res = res + i;
                // para cada iteracion vamos a sumarle a res
                //el valor del numero y asignar el resultado otra ves a res
    std::cout  << res << " ";
  }
  std::cout << std::endl;
  std::cout << std::endl;

  // Aqui vemos una combinacion de los dos tipos mencionados, un vector de strings
  std::vector<std::string> vs = {"Hello", "Cpp", "is", "fun"};
  for(std::string s : vs) // no usamos auto, usamos std::string,
                          // por demostrar la posibilidad...auto tambien valdria
    {
      std::cout << s;
    }
  std::cout << std::endl;

  // aprovecho y introduzco un poco mas sobre memoria
  std::cout << sizeof(std::string) << std::endl;
  // >>  32

  for(int i = 0; i < vs.size(); i++)
  {
    std::cout << &vs[i] <<std::endl; // & - en este contexto nos va printar la
                                     // direccion de memoria de vs[i]
  }
  std::cout << std::endl;
  //  Aqui si nos fijamos cada print es una direccion diferente
  //  basada en el size de std::string
  //  0x6457b054c6e0      e0 inicio
  //  0x6457b054c700      +32
  //  0x6457b054c720      +32
  //  0x6457b054c740      +32
  //  y aunque sea mas largo o mas corto el string lo que realmente esta guardando
  //  es un puntero a la memoria del string, por eso 32,

  for(const auto &st : vs)  // introducimos la posibilidad del const auto tambien
                            // mejor praxis, pues hara la variable inmutable
                            // y la protege mejor
  {
    std::cout << "Address of s: " << st << " : " << &st <<  std::endl;
  }
  std::cout << std::endl;
  //  Aqui nos da la misma direccion que la anterior
  //  porque si nos fijamos en el auto lleva un &st (address of st)
  //  Address of s: Hello : 0x654ed5fba6e0
  //  Address of s: Cpp :   0x654ed5fba700
  //  Address of s: is :    0x654ed5fba720
  //  Address of s: fun :   0x654ed5fba740

  for(auto st : vs)
  {
    std::cout << "Address of s: " << st << " : " << &st <<  std::endl;
  }
  std::cout << std::endl;
  //  Aqui ya  cambia, es la misma direccion, porque ya no estamos referenciando 
  //  con & las direcciones de cada miembro, si no que estamos haciendo una copia
  //  y siempre se guarda en la misma direccion st

  //  Address of s: Hello : 0x7ffca618c5b0
  //  Address of s: Cpp : 0x7ffca618c5b0
  //  Address of s: is : 0x7ffca618c5b0
  //  Address of s: fun : 0x7ffca618c5b0

  // Eso se puede tener en cuenta segun lo que queramos hacer, o no hacer, como
  // en ese caso no gasta muchos recursos, pero no tendriamos acceso
  // para modificar el valor original ya que es una copia


  /* Switch case */     
  // Switch, 0 drama facilito, es como un if else
  // hay que dice que es mas limpio y tal
  // pero solo admite integers o chars
  std::cout << "Resumen" << std::endl;
  std::vector<std::string> aritm = {"+", "-", "/", "%", "*"};
  std::vector<std::string> reasign = {"+=", "-=", "/=", "%=", "*="};
  std::vector<std::string> compare = {"!=", "=="};

  int a, b;   // Para valores de tipos iguales
  for(const auto &s :  aritm)
  {
    a = 11; // Este asignment esta dentro del for loop, entonces en cada vuelta
            // se reseta a estos valores
    b = 2;
    switch(s[0])    // Magia time, como solo podemos usar integers o chars
                    // vamos a pillar solo el primer char del string, por ejemplo
                    // "+" == [+,\0], "+"[0] == '+'
    {
      case 43: // es + en ascii, para poner el ejemplo
               // bajo el capo '+' == 43 ==  00101011
        std::cout << "Suma: a + b: " << a + b << std::endl;
        a += b;
        std::cout << "Suma: a += b, a: " << a << std::endl;
        break;
      case '-': // == 45 ... etc..
        std::cout << "Resta: 1 - 2: " << a - b << std::endl;
        a -= b;
        std::cout << "Resta: 1 -= 2, a: " << a << std::endl;
        break;
      case '/':
        std::cout << "Division Entera: 11 / 2: "<< a / b << std::endl;
        a /= b;
        std::cout << "Division Entera: 11 /= 2, a: "<< a << std::endl;
        break;
      case 35 + 2: // == 37 == %
        std::cout << "Resto de la division entera: 11 % 2: " << a % b << std::endl;
        a %= b;
        std::cout << "Resto de la division entera: 11 %= 2, a: " << a << std::endl;
        break;
      case 0x2a: //0x2a == 0010 1010 == 42 == *
        std::cout << "Multiplicacion: 11 * 2: " << a * b << std::endl;
        a *= b;
        std::cout << "Multiplicacion: 11 *= 2, a: " << a << std::endl;
        break;
      default:
        std::cout << "Condition no se cumple algun error";
        break;
    }
  }
  std::cout << std::endl;


  /****************************************************************************/
  /* Operadores de Binarios                                                   */
  /****************************************************************************/

  // Actuan en la representacion binaria del elemento,
  // aqui pondremos la funcion bitset otra ves para poder verlo en binario
  // pero como veremos abajo pueden ir a cualquier lado
  char uc4 = 40;
  char uc5 = 50;
  std::cout << " 40 in binary:\t\t" << std::bitset<8 /*longitud*/>(uc4) <<std::endl;
  std::cout << " 50 in binary:\t\t" << std::bitset<8>(uc5) <<std::endl;
  std::cout << std::endl;
  //      & and 
  std::cout << " 40 & 50 in binary:\t" << std::bitset<8>(uc4 & uc5) <<std::endl;
  //      ~ not
  std::cout << " ~40 in binary:\t\t" << std::bitset<8>(~uc4) <<std::endl;
  std::cout << " ~0 in binary:\t\t" << std::bitset<8>(~0) <<std::endl;
  //      ^ xor
  std::cout << " 40 ^ 50 in binary:\t" << std::bitset<8>(uc4 ^ uc5) <<std::endl;
  //      | or 
  std::cout << " 40 | 50 in binary:\t" << std::bitset<8>(uc4 | uc5) <<std::endl;
  //      << left shift
  std::cout << " 40<<1 in binary:\t" << std::bitset<8>(uc4<<1) <<std::endl;
  //      >> right shift
  std::cout << " 40>>1 in binary:\t" << std::bitset<8>(uc4>>1) <<std::endl;


  /****************************************************************************/
  // Extra
  /****************************************************************************/

  for(int i = 10; i < 55; i++)
  {
    if((i & 1) != 1 ) // & 1 ???, como los impares llevan un uno al final
                      // si hacemos un and del numero con 0001 y es true
                      // es un numero impar
    {
      if((i != 16) && (i % 3 != 0))  
        std::cout << i << " "; 
    }
  }
  std::cout << std::endl;  
  return 0;
}

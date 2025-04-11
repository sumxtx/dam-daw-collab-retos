

def saludoPersonalizado(nombre):
    """
    Esta funcion recibe un parametro de nombre y lo utiliza para saludarte

    Args:
        nombre del usuario

    Returns:
        saludo "Hola, nombre"
    """

    print("Hola " + nombre)


saludoPersonalizado("Roberto")

def sumarDosNumeros(n1, n2):
    """
    Funcion que recibe dos numeros y los sumas
    Args:
        n1: primer numero
        n2: segundo numero
    Returns:
        int: con el resultado de la suma de n1 y n2
    """
    resultado = n1 + n2 #Variable local
    return resultado

resultado = sumarDosNumeros(2,2) #Variable Global
print(f"El resultado de la suma es {resultado}")

def sumar(*args):
    """
    Función que recibe una cantidad de numeros X y los sumas
    Args:
        varios numeros para sumar
    
    Returns:
        La suma de todos los numeros
    """
    resultado = 0
    for numero in args:
        resultado += numero

    return resultado

resultado2 = sumar(2,2,2,2,2)
print(f"El resultado de la suma es {resultado2}")

# Las funciones lambda son útiles para usarse una unica vez y si son cortas.

sumaLamda = lambda x,y: x + y
print(f"El resultado de la suma usando un lambada es {sumaLamda(2,3)}")

print("\nAhora hacemos la prueba extra")
print("\n")

texto1 = input("Ingresa un primer texto: ")
texto2 = input("Ingresa un segundo texto: ")

def multiplos(texto1, texto2):
    """
    Función que recibe dos parámetros de tipo cadena de texto y retorna un número.
    La función imprime todos los números del 1 al 100. Teniendo en cuenta que:
    Si el número es múltiplo de 3, muestra la cadena de texto del primer parámetro.
    Si el número es múltiplo de 5, muestra la cadena de texto del segundo parámetro.
    Si el número es múltiplo de 3 y de 5, muestra las dos cadenas de texto concatenadas.
    Args:
        texto1 (str): dado por el usuario
        texto2 (str): dado por el usuario
    Returns: 
        int: La función retorna el número de veces que se ha impreso el número en lugar de los textos.
    """
    contador = 0
    for i in range(1,101):
        if i % 3 == 0 and i % 5 == 0:
            print(texto1+texto2)
        elif i % 3 == 0:
            print(texto1)
        elif i % 5 == 0:
            print(texto2)
        else:
            print(i)
            contador += 1
    
    return contador
        

print(f"Las veces que se muestran numeros es {multiplos(texto1, texto2)}")


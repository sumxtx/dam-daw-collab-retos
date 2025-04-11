
a = 5
b = 3
resultado = a + b  # Resultado: 8
resultado = a - b  # Resultado: 2
resultado = a * b  # Resultado: 15
resultado = a / b  # Resultado: 1.6666...
resultado = a // b  # Resultado: 1
resultado = a % b  # Resultado: 2
resultado = a ** b  # Resultado: 125 (5^3)

lista = ["Coche", "Bici", "Avion"]

for vehiculo  in lista:
    print(vehiculo)

contador = 1

while(contador <= 5):
    print(contador)
    contador += 1

if(contador == 1):
    print("Hola")
elif (contador > 1):
    print("Adios")
else:
    print("Buenas tardes")


try:
    divisionPorCero = 10/0
except ZeroDivisionError:
    print("ERROR: no se puede dividir por cero")
except TypeError:
    print("ERROR operacion de tipo no soportada")
finally:
    print("Este codigo siempre se imprime. Chao!")
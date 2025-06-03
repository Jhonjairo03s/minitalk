# Minitalk

## Resumen
Minitalk es un proyecto de la escuela 42 que consiste en crear un pequeño programa de intercambio de datos entre dos procesos (un cliente y un servidor) utilizando únicamente señales UNIX (`SIGUSR1` y `SIGUSR2`). El objetivo es transmitir una cadena de texto desde el cliente al servidor, donde el servidor la imprimirá en la pantalla.

## Objetivos del Proyecto
* Comprender y utilizar señales UNIX para la comunicación entre procesos (IPC).
* Implementar un modelo cliente-servidor simple.
* Manejar la transmisión de datos bit a bit.
* Utilizar `sigaction` para una gestión robusta de señales.
* Desarrollar la lógica para ensamblar datos recibidos bit a bit en información coherente (caracteres y cadenas).
* Cumplir con las restricciones de la Norminette de 42.

## Características Implementadas
* **Comunicación Cliente-Servidor:** Establecida mediante señales UNIX.
* **Señales Utilizadas:** Exclusivamente `SIGUSR1` y `SIGUSR2` para la transmisión de datos.
* **Visualización del PID:** El servidor muestra su PID al iniciarse para que el cliente pueda conectarse.
* **Argumentos del Cliente:** El cliente toma el PID del servidor y la cadena a enviar como parámetros.
* **Visualización del Mensaje:** El servidor, una vez recibida la cadena completa, la muestra en la consola.
* **Manejo de Múltiples Clientes:** El servidor puede recibir mensajes de diferentes clientes de forma consecutiva sin necesidad de reiniciarse.
* **BONUS: Confirmación del Servidor (ACK):** El servidor confirma la recepción de cada bit de datos enviando una señal (`SIGUSR1`) de vuelta al cliente. El cliente espera esta confirmación antes de enviar el siguiente bit, lo que mejora significativamente la fiabilidad de la transmisión y elimina la necesidad de `usleep` para la sincronización.
* **Funciones Personalizadas:** Utilización de `ft_printf` propia (incluida como librería) y `ft_atoi` para la conversión de cadenas.

## ¿Cómo Funciona?
### Transmisión de Datos
1.  El **servidor** se inicia, muestra su PID y espera señales.
2.  El **cliente** se ejecuta con el PID del servidor y el mensaje a enviar.
3.  El cliente procesa el mensaje carácter por carácter.
4.  Cada carácter se descompone en sus 8 bits.
5.  Por cada bit del carácter:
    * El cliente envía `SIGUSR1` al servidor para representar un bit '0'.
    * El cliente envía `SIGUSR2` al servidor para representar un bit '1'.
    * **(Con Bonus ACK)** El cliente espera una señal `SIGUSR1` de vuelta del servidor como confirmación antes de enviar el siguiente bit.
6.  El **servidor**, al recibir cada señal de datos:
    * Interpreta `SIGUSR1` como '0' y `SIGUSR2` como '1'.
    * Reconstruye los 8 bits para formar un carácter.
    * Almacena los caracteres en un buffer.
    * **(Con Bonus ACK)** Envía una señal `SIGUSR1` al cliente para confirmar la recepción del bit de datos.
7.  Cuando el servidor recibe el carácter nulo (`\0`) o su buffer de mensajes se llena, imprime la cadena completa acumulada.

## Cómo Compilar
El proyecto utiliza un `Makefile` para la compilación. Asegúrate de tener `make` y un compilador de C (como `gcc` o `clang`, referenciado como `cc` en el Makefile) instalados. La librería `ft_printf` (que debe estar en un subdirectorio `ft_printf/` con su propio `Makefile`) también se compilará.

1.  **Clona el repositorio (si aplica):**
    ```bash
    git clone https://github.com/Jhonjairo03s/minitalk.git
    cd minitalk
    ```
2.  **Compila el proyecto:**
    ```bash
    make
    ```
    Esto compilará la librería `ft_printf` y luego los ejecutables `client` y `server`.

### Otras Reglas del Makefile
* `make clean`: Elimina los archivos objeto (`.o`) de Minitalk y llama a `make clean` de `ft_printf`.
* `make fclean`: Ejecuta `clean` y además elimina los ejecutables `client`, `server`, y llama a `make fclean` de `ft_printf` (que debería eliminar la librería `libftprintf.a`).
* `make re`: Ejecuta `fclean` y luego `make all`.

## Cómo Ejecutar
1.  **Inicia el servidor:**
    En una terminal, ejecuta:
    ```bash
    ./server
    ```
    El servidor imprimirá su PID. Anótalo. Ejemplo: `Servidor PID: 12345`

2.  **Ejecuta el cliente:**
    En otra terminal, ejecuta (reemplaza `<PID_DEL_SERVIDOR>` con el PID real y `"Tu mensaje aquí"` con la cadena que deseas enviar):
    ```bash
    ./client <PID_DEL_SERVIDOR> "Tu mensaje aquí"
    ```
    Ejemplos:
    ```bash
    ./client 12345 "Hola desde Minitalk!"
    ./client 12345 "Probando caracteres especiales como '!@#\$%&'"
    ./client 12345 "" # Para enviar una cadena vacía
    ```
3.  **Observa la salida:**
    La terminal del servidor debería imprimir el mensaje enviado por el cliente.

## Estructura del Proyecto

## Autor
* **https://github.com/Jhonjairo03s**

---

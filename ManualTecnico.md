# Manual Técnico - Aplicación de Graficación de Figuras

## Introducción

Esta aplicación permite al usuario graficar diversas figuras geométricas en una pantalla de texto. El usuario puede acceder a un menú de opciones presionando la tecla F12, donde puede seleccionar las figuras a graficar, cambiar el carácter de representación, cambiar el color del carácter, limpiar la pantalla y grabar la pantalla activa.

## Requisitos del Sistema

- Sistema Operativo: Windows, Linux, macOS
- Compilador de C++ compatible con la biblioteca ncurses (p. ej., GCC)
- Biblioteca ncurses instalada

## Funcionalidades

### Menú de Opciones

- Presionar F12 para mostrar el menú de opciones.
- Las opciones están asociadas a las teclas F1 a F10 y Ctrl + A.

### Graficación de Figuras

- F1: Graficar un triángulo.
- F2: Graficar un cuadrado.
- F3: Graficar un rectángulo.
- F4: Graficar un círculo.
- F5: Graficar una línea (permite al usuario seleccionar la orientación).
- F6: Graficar un rombo.
- F7: Graficar un hexágono.

### Configuración

- F8: Cambiar el carácter en el cual se grafican las formas.
- F10: Cambiar el color del carácter.

### Funcionalidades Adicionales

- F9: Limpiar la pantalla.
- F12: Mostrar el menú y la opción de grabar pantalla.

### Grabación de Pantalla

- Seleccionar la opción de grabar pantalla desde el menú.
- Introducir el nombre del archivo y la dirección de guardado.
- Presionar Enter para guardar la pantalla activa.
- Ctrl + A: Abrir el archivo guardado.

## Desarrollo

La aplicación está desarrollada en C++ utilizando la biblioteca ncurses para la interfaz de usuario en modo texto.

## Compilación y Ejecución

1. Compilar el código fuente utilizando un compilador de C++ compatible con ncurses.
2. Ejecutar el programa compilado en una terminal o línea de comandos.

## Limitaciones

- La aplicación funciona en entornos de terminal o línea de comandos, y no en entornos gráficos.
- La precisión de las figuras geométricas puede verse afectada por la resolución de la pantalla y la selección del carácter de representación.
- La grabación de pantalla podría no ser compatible con todas las configuraciones de sistema.

## Licencia

Este software se distribuye bajo la Licencia de la UMG de Guatemala

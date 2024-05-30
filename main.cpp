#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <shlobj.h>
#include <string>
#include <thread>
#include <chrono>

using namespace std;
//CARACTER PARA CREAR LAS FORMAS
char caracterGlobal = 'x';
bool ctrlAPressed = false;
bool actionPerformed = false;

//FUNCION PARA SABER LAS COORDENADAS DEL EJE X y Y
void gotoxy(int x = 0, int y = 0) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

 //FUNCION PARA CAMBIAR EL COLOR DEL CARACTER GLOBAL
void cambiarColorCaracter() {
    system("cls");
    int color;
    cout << "Elige un color para el caracter (0-15): ";
    cin >> color;

    if(color >= 0 && color <= 15) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color);
        cout << "Color del caracter cambiado correctamente.\n";
        cout << "Presiona F12 para volver al menu principal...";
    } else {
        cout << "Color no valido. Debe estar entre 0 y 15.\n";
    }
}
//FUNCION PARA MOSTRAR EL MENU
void mostrarMenu(){
    // Muestra el menú
    std::cout << "F1. TRIANGULO" << std::endl;
    std::cout << "F2. CUADRADO" << std::endl;
    std::cout << "F3. RECTANGULO" << std::endl;
    std::cout << "F4. CIRCULO" << std::endl;
    std::cout << "F5. LINEA" << std::endl;
    std::cout << "F6. ROMBO" << std::endl;
    std::cout << "F7. HEXAGONO" << std::endl;
    std::cout << "F8. NUEVO CARACTER" << std::endl;
    std::cout << "F9. LIMPIAR PANTALLA" << std::endl;
    std::cout << "F10. COLOR DE CARACTER" << std::endl;
    std::cout << "F12. GRABAR PANTALLA" << std::endl;
    std::cout << "Ctrl+A. ABRIR ARCHIVO Y MOSTRAR EN PANTALLA" << std::endl;
    std::cout << "PRESIONE 0 PARA DETENER EL PROGRAMA" << std::endl;
}
//FUNCION PARA MOVER LAS FLECHAS DEL TECLADO
void moverCursor(int &x, int &y, int key) {
    switch (key) {
        case 75: // Tecla izquierda
            x--;
            break;
        case 77: // Tecla derecha
            x++;
            break;
        case 72: // Tecla arriba
            y--;
            break;
        case 80: // Tecla abajo
            y++;
            break;
        default:
            break;
    }
    gotoxy(x, y); // Mueve el cursor a la nueva posición
}
//MENU DE LA FIGURA DE LOS TRIANGULOS
void crearTriangulo(char caracterGlobal) {
    cout << "Seleccione la orientacion del triangulo: " << endl;
    cout << "1. Arriba" << endl;
    cout << "2. Abajo" << endl;
    cout << "3. Derecha" << endl;
    cout << "4. Izquierda" << endl;

    char orientacion_triangulo;
    cin >> orientacion_triangulo;

    int bas1;
    switch (orientacion_triangulo) {
        case '1': // Triángulo hacia arriba
            cout << "Ingrese la base del triangulo: ";
            cin >> bas1;
            system("cls");
            for (int i = 0; i < bas1; i++) {
                for (int j = 0; j < bas1 - i - 1; j++) {
                    cout << " ";
                }
                for (int j = 0; j < 2 * i + 1; j++) {
                    if (i == bas1 - 1 || j == 0 || j == 2 * i) {
                        cout << caracterGlobal;
                    } else {
                        cout << " ";
                    }
                }
                cout << endl;
            }
            break;

        case '2': // Triángulo hacia abajo
            cout << "Ingrese la base del triangulo: ";
            cin >> bas1;
            system("cls");
            for (int i = 0; i < bas1; i++) {
                for (int j = 0; j < i; j++) {
                    cout << " ";
                }
                for (int j = 0; j < 2 * (bas1 - i) - 1; j++) {
                    if (i == 0 || j == 0 || j == 2 * (bas1 - i) - 2) {
                        cout << caracterGlobal;
                    } else {
                        cout << " ";
                    }
                }
                cout << endl;
            }
            break;

        case '3': // Triángulo hacia derecha
            cout << "Ingrese la altura del triangulo: ";
            cin >> bas1;
            system("cls");
            for (int i = 0; i < bas1; i++) {
                for (int j = 0; j < i; j++) {
                    cout << " ";
                }
                for (int j = 0; j < bas1 - i; j++) {
                    cout << caracterGlobal;
                }
                cout << endl;
            }
            break;

        case '4': // Triángulo hacia izquierda
            cout << "Ingrese la altura del triangulo: ";
            cin >> bas1;
            system("cls");
            for (int i = 0; i < bas1; i++) {
                for (int j = 0; j < bas1 - i - 1; j++) {
                    cout << " ";
                }
                for (int j = 0; j <= i; j++) {
                    cout << caracterGlobal;
                }
                cout << endl;
            }
            break;

        default:
            cout << "Opcion no valida" << endl;
            break;
    }
}
//FUNCION DE LA FIGURA DEL CUADRADO
void CrearCuadrados(int x, int y, char caracterGlobal) {
    int lado;
    cout << "Seleccione la orientacion del cuadrado: " << endl;
    cout << "1. Arriba" << endl;
    cout << "2. Abajo" << endl;
    cout << "3. Derecha" << endl;
    cout << "4. Izquierda" << endl;
    char orientacion_cuadrado;
    cin >> orientacion_cuadrado;
    switch (orientacion_cuadrado) {
            case '1': // Cuadrado hacia arriba
                x = 0, y = 0;
                cout << "Ingrese el tamaño de un lado del cuadrado: ";
                cin >> lado;
                system("cls");
                gotoxy(x, y);
                for (int i = 0; i < lado; i++) {
                for (int j = 0; j < lado; j++) {
                if (i == 0 || i == lado - 1 || j == 0 || j == lado - 1) {
                cout << caracterGlobal;
                } else {
                cout << " ";
            }
            }
                cout << endl;
                gotoxy(x, ++y);
                }
            break;


            case '2': // Cuadrado hacia abajo
                cout << "Ingrese el tamaño de un lado del cuadrado: ";
                cin >> lado;
                system("cls");
                gotoxy(x, y);
                for (int i = 0; i < lado; i++) {
                for (int j = 0; j < lado; j++) {
                if (i == 0 || i == lado - 1 || j == 0 || j == lado - 1) {
                cout << caracterGlobal;
                } else {
                cout << " ";
            }
                }
                cout << endl;
                }
            break;

            case '3': // Cuadrado hacia derecha
                cout << "Ingrese el tamaño de un lado del cuadrado: ";
                cin >> lado;
                system("cls");
                gotoxy(x, y);
                for (int i = 0; i < lado; i++) {
                for (int j = 0; j < lado; j++) {
                if (i == 0 || i == lado - 1 || j == lado - 1) {
                cout << caracterGlobal;
                } else {
                cout << " ";
            }
        }
                cout << endl;
                gotoxy(x, ++y);
    }
            break;

            case '4': // Cuadrado hacia izquierda
                cout << "Ingrese el tamaño de un lado del cuadrado: ";
                cin >> lado;
                system("cls");
                gotoxy(x + lado - 1, y); // Empieza desde la esquina superior derecha
                for (int i = 0; i < lado; i++) {
                for (int j = 0; j < lado; j++) {
                if (i == 0 || i == lado - 1 || j == 0 || j == lado - 1) {
                cout << caracterGlobal;
            } else {
                cout << " ";
                    }
                }
                cout << endl;
                gotoxy(x + lado - 1, ++y); // Mueve el cursor hacia abajo en cada iteración
            }
            break;

        default:
            cout << "Opcion no valida" << endl;
            break;
    }
}
//FUNCION DE LA FIGURA DEL RECTANGULO
void CrearRectangulos() {
    system("cls");
    int base, altura;
    cout << "Seleccione la orientacion del rectangulo: " << endl;
    cout << "1. Arriba" << endl;
    cout << "2. Abajo" << endl;
    char orientacion_rec;
    cin >> orientacion_rec;
    int x, y;
    switch (orientacion_rec) {
        case '1': // Rectangulo hacia arriba
            x = 20, y = 20;
            cout << "Ingrese la base del rectangulo: ";
            cin >> base;
            cout << "Ingrese la altura del rectangulo: ";
            cin >> altura;
            system("cls");
            gotoxy(x, y);
            for (int i = 0; i < altura; i++) {
                for (int j = 0; j < base; j++) {
                    if (i == 0 || i == altura - 1 || j == 0 || j == base - 1) {
                        cout << '*';
                    } else {
                        cout << " ";
                    }
                }
                cout << endl;
                gotoxy(x, ++y);
            }
            break;

        case '2': // Rectangulo hacia abajo
            x = 10, y = 10;
            cout << "Ingrese la base del rectangulo: ";
            cin >> base;
            cout << "Ingrese la altura del rectangulo: ";
            cin >> altura;
            system("cls");
            gotoxy(x, y);
            for (int i = altura - 1; i >= 0; i--) {
                for (int j = 0; j < base; j++) {
                    if (i == 0 || i == altura - 1 || j == 0 || j == base - 1) {
                        cout << '*';
                    } else {
                        cout << " ";
                    }
                }
                cout << endl;
                gotoxy(x, ++y);
            }
            break;

        default:
            cout << "Opcion no valida" << endl;
            break;
    }
}
//FUNCION PARA CREAR CIRCULOS
void CrearCirculo(int x, int y) {
    int radio;
    cout << "Ingrese el radio del circulo: ";
    cin >> radio;
    system("cls");
    gotoxy(x, y);
    for (int i = -radio; i <= radio; ++i) {
        for (int j = -radio; j <= radio; ++j) {
            if (i * i + j * j <= radio * radio) {
                cout << caracterGlobal;
            } else {
                cout << " ";
            }
        }
        cout << endl;
        gotoxy(x, ++y);
    }
}
//CREAR LINEAS
void CrearLineas() {
    int x = 0, y = 0, longitud;
    cout << "Ingrese la longitud de la linea: ";
    cin >> longitud;
    system("cls");
    gotoxy(x, y);
    cout << "Seleccione la orientacion de la linea: " << endl;
    cout << "1. Arriba" << endl;
    cout << "2. Abajo" << endl;
    cout << "3. Derecha" << endl;
    cout << "4. Izquierda" << endl;
    cout << "5. Diagonal Derecha Arriba" << endl;
    cout << "6. Diagonal Derecha Abajo" << endl;
    cout << "7. Diagonal Izquierda Arriba" << endl;
    cout << "8. Diagonal Izquierda Abajo" << endl;
    char orientacion;
    cin >> orientacion;

    switch (orientacion) {
        case '1':
            x = 0, y = 0;
            system("cls");
            for (int i = 0; i < longitud; ++i) {
                gotoxy(x, y - i);
                cout << caracterGlobal;
            }
            break;

        case '2':
            x = 10, y = 10;
            system("cls");
            for (int i = 0; i < longitud; ++i) {
                gotoxy(x, y + i);
                cout << caracterGlobal;
            }
            break;

        case '3':
            system("cls");
            for (int i = 0; i < longitud; ++i) {
                gotoxy(100, i);
                cout << caracterGlobal;
            }
            break;

        case '4':
            system("cls");
            for (int i = 0; i < longitud; ++i) {
                gotoxy(1, i);
                cout << caracterGlobal;
            }
            break;

        case '5':
            x = 50, y = 12;
            system("cls");
            for (int i = 0; i < longitud; ++i) {
                gotoxy(x + i, y - i);
                cout << caracterGlobal;
            }
            break;

        case '6':
            x = 50, y = 12;
            system("cls");
            for (int i = 0; i < longitud; ++i) {
                gotoxy(x + i, y + i);
                cout << caracterGlobal;
            }
            break;

        case '7':
            x = 50, y = 12;
            system("cls");
            for (int i = 0; i < longitud; ++i) {
                gotoxy(x - i, y - i);
                cout << caracterGlobal;
            }
            break;

        case '8':
            x = 50, y = 12;
            system("cls");
            for (int i = 0; i < longitud; ++i) {
                gotoxy(x - i, y + i);
                cout << caracterGlobal;
            }
            break;

        default:
            cout << "Opcion no valida" << endl;
            break;
    }
}
//CREAR ROMBOS
void CrearRombos() {
    int x = 0, y = 0, lado_rombo;
    cout << "Ingrese la longitud de uno de los lados del rombo: ";
    cin >> lado_rombo;
    system("cls");
    gotoxy(x, y);
    cout << "Seleccione la orientacion del rombo: " << endl;
    cout << "1. Arriba" << endl;
    cout << "2. Abajo" << endl;
    char orientacion_rombo;
    cin >> orientacion_rombo;

    switch (orientacion_rombo) {
        case '1': // Arriba
            system("cls");
            x = 10, y = 10;
            gotoxy(x, y);

            for (int i = 0; i < lado_rombo; ++i) {
                for (int j = 0; j < lado_rombo - i - 1; ++j) {
                    cout << " ";
                }
                for (int j = 0; j < 2 * i + 1; ++j) {
                    cout << caracterGlobal;
                }
                cout << endl;
                gotoxy(x, ++y);
            }
            for (int i = lado_rombo - 2; i >= 0; --i) {
                for (int j = 0; j < lado_rombo - i - 1; ++j) {
                    cout << " ";
                }
                for (int j = 0; j < 2 * i + 1; ++j) {
                    cout << caracterGlobal;
                }
                cout << endl;
                gotoxy(x, ++y);
            }
            break;

        case '2': // Abajo
            system("cls");
            x = 10, y = 10;
            gotoxy(x, y);

            for (int i = 0; i < lado_rombo; ++i) {
                for (int j = 0; j < i; ++j) {
                    cout << " ";
                }
                for (int j = 0; j < 2 * (lado_rombo - i) - 1; ++j) {
                    cout << caracterGlobal;
                }
                cout << endl;
                gotoxy(x, ++y);
            }
            for (int i = lado_rombo - 2; i >= 0; --i) {
                for (int j = 0; j < i; ++j) {
                    cout << " ";
                }
                for (int j = 0; j < 2 * (lado_rombo - i) - 1; ++j) {
                    cout << caracterGlobal;
                }
                cout << endl;
                gotoxy(x, ++y);
            }
            break;

        default:
            cout << "Opcion no valida" << endl;
            break;
    }
}
//CREAR HEXAGONO
void CrearHexagonos() {
    int x = 0, y = 0, lado_hexagono;
    cout << "Ingrese la longitud de uno de los lados del hexagono: ";
    cin >> lado_hexagono;
    system("cls");
    gotoxy(x, y);
    cout << "Seleccione la orientacion del hexagono: " << endl;
    cout << "1. Vertical" << endl;
    cout << "2. Horizontal" << endl;
    char orientacion_hexagono;
    cin >> orientacion_hexagono;

    switch (orientacion_hexagono) {
        case '1': // Vertical
            system("cls");
            for (int i = 0; i < lado_hexagono; ++i) {
                for (int j = 0; j < lado_hexagono - i - 1; ++j) {
                    cout << " ";
                }
                for (int j = 0; j < lado_hexagono + 2 * i; ++j) {
                    cout << caracterGlobal;
                }
                cout << endl;
            }
            for (int i = lado_hexagono - 2; i >= 0; --i) {
                for (int j = 0; j < lado_hexagono - i - 1; ++j) {
                    cout << " ";
                }
                for (int j = 0; j < lado_hexagono + 2 * i; ++j) {
                    cout << caracterGlobal;
                }
                cout << endl;
            }
            break;

        case '2': // Horizontal
            system("cls");
            for (int i = 0; i < lado_hexagono; ++i) {
                for (int j = 0; j < 2 * lado_hexagono - 2 * i; ++j) {
                    cout << " ";
                }
                for (int j = 0; j < lado_hexagono + i; ++j) {
                    cout << caracterGlobal;
                }
                cout << endl;
            }
            for (int i = lado_hexagono - 2; i >= 0; --i) {
                for (int j = 0; j < 2 * lado_hexagono - 2 * i; ++j) {
                    cout << " ";
                }
                for (int j = 0; j < lado_hexagono + i; ++j) {
                    cout << caracterGlobal;
                }
                cout << endl;
            }
            break;

        default:
            cout << "Opcion no valida" << endl;
            break;
    }
}
//GRABAR LA PANTALLA
void grabarPantalla() {
    string nombreArchivo, rutaArchivo;
    cout << "Ingrese el nombre del archivo: ";
    cin >> nombreArchivo;
    cout << "Ingrese la ruta del archivo: ";
    cin >> rutaArchivo;

 // Cambiar las barras normales por barras invertidas en la ruta de archivo
    size_t found = rutaArchivo.find("/");
    while (found != string::npos) {
        rutaArchivo[found] = '\\';
        found = rutaArchivo.find("/", found + 1);
    }

    // Combina la ruta y el nombre del archivo
     string rutaCompleta = rutaArchivo + "\\" + nombreArchivo + ".txt";
    cout<< rutaCompleta<<endl;

    // Abre el archivo en modo de escritura
    ofstream archivoSalida(rutaCompleta.c_str());

    if (!archivoSalida) {
        cerr << "Error al abrir el archivo!" << endl;;
        return;
    }

    // Captura y guarda el contenido de la pantalla
    archivoSalida << "Contenido Actual de la Pantalla:" << endl;


    archivoSalida << "Ingrese el nombre del archivo: " << endl;
    archivoSalida << nombreArchivo << endl;
    archivoSalida << "Ingrese la ruta del archivo: " << endl;
    archivoSalida << rutaArchivo << endl;

    archivoSalida.close();
    cout << "Contenido de la pantalla grabado en: " << rutaCompleta << endl;
}
//ABRIR EL ARCHIVO GUARDADO
void abrirArchivoYMostrarContenido() {
    string rutaArchivo;
    cout << "Ingrese la ruta del archivo que desea abrir: ";
    cin >> rutaArchivo;

    ifstream archivoEntrada(rutaArchivo); // Abre el archivo en modo de lectura

    // Verifica si se pudo abrir el archivo correctamente
    if (!archivoEntrada) {
        cerr << "No se pudo abrir el archivo." << endl;
        return;
    }

    cout << "Contenido del archivo:" << endl;

    // Lee y muestra el contenido del archivo línea por línea
    string linea;
    while (getline(archivoEntrada, linea)) {
        cout << linea << endl;
    }

    // Cierra el archivo
    archivoEntrada.close();
}
//VERIFICAR QUE SE ESTA PRESIONANDO CTRL+A
bool isCtrlPressed() {
    return GetKeyState(VK_CONTROL) & 0x8000;
}
bool isCtrlAPressed() {
    return (GetAsyncKeyState(VK_CONTROL) & 0x8000) && (GetAsyncKeyState('A') & 0x8000);
}
void checkCtrlA() {
    if (isCtrlAPressed()) {
            if (!ctrlAPressed) {
                system("cls");
                abrirArchivoYMostrarContenido();
                actionPerformed = true;
            }
            ctrlAPressed = true;
        } else {
            ctrlAPressed = false;
        }

        // Verificar si se ha realizado alguna acción y esperar un poco antes de volver a verificar
        if (actionPerformed) {
            // Esperar hasta que ambas teclas sean liberadas
            while (isCtrlAPressed()) {
                std::this_thread::sleep_for(std::chrono::milliseconds(50));
            }
            // Restablecer el estado de la acción realizada
            actionPerformed = false;
        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    }


//MENU PRINCIPAL DE LA APLICACION
int main() {

    int x = 0, y = 0; //Posición del puntero en pantalla
    int longitud;
    int opcion;
    bool finalizar = true;
    int bas1;
    string nombreArchivo;
    const char IZQUIERDA = 75, DERECHA = 77, ARRIBA = 72, ABAJO = 80, ELE = 101;
    const char F1 = 59, F2 = 60, F3 = 61, F4 = 62, F5 = 63, F6 = 64, F7 = 65, F8 = 66, F9 = 67, F10 = 68, F11 = 69, F12 = 134;

    while (finalizar) {
            // Llamar a la función de verificación de Ctrl + A
        checkCtrlA();

        if (_kbhit()) {

            int key = _getch();  // Captura la tecla presionada

            // Manejo de teclas extendidas
            if (key == 0 || key == 224) {
                key = _getch();  // Captura el siguiente valor de la tecla extendida
            }

            // Mueve el cursor si se presionan las teclas de flecha
            moverCursor(x, y, key);

            switch (key) {
                case 59:  // Código para F1
                    system("cls");
                    crearTriangulo(caracterGlobal);
                    break;

                case 60:  // Código para F2
                    system("cls");
                    CrearCuadrados(x, y, caracterGlobal);
                    break;

                case 61:  // Código para F2
                    system("cls");
                    CrearRectangulos();
                break;

                case 62: // F4
                    system("cls");
                    CrearCirculo(x, y);
                break;

                case 63: // F5
                    system("cls");
                    CrearLineas();
                break;

                case 64: // F6
                    system("cls");
                    CrearRombos();
                break;

                case 65: // F7
                    system("cls");
                    CrearHexagonos();
                break;

                case 66: // F8
                    system("cls");
                    cout << "Ingrese el caracter que se utilizara para dibujar las figuras geometricas: ";
                    cin >> caracterGlobal;
                    system("cls");
                    cout << "Caracter actualizado con exito." << endl;
                    finalizar = true; // Volver al menú principal
                break;

                case 67: // F9
                    // Limpiar la pantalla
                    system("cls");
                    cout << "Presione F12 para volver al menu principal.." << endl;
                    finalizar = true; // Volver al menú principal
                    break;
                break;

                case 68: // F10
                    system("cls");
                    cambiarColorCaracter();
                break;

                case 97: // F10
                    system("cls");
                    abrirArchivoYMostrarContenido();
                break;

                 case 134:  // Código para F12
                    system("cls");
                    cout << "Seleccione una opcion para la tecla F12:\n";
                    cout << "1. Grabar pantalla\n";
                    cout << "2. Mostrar menu\n";
                    char opcion;
                    cin >> opcion;
                    if (opcion == '1') {
                        system("cls");
                        grabarPantalla();
                    } else if (opcion == '2') {
                        system("cls");
                        mostrarMenu();
                    } else {
                        cout << "Opción no válida\n";
                    }
                    break;

                case 48:  // Código para ESC
                    system("cls");
                    finalizar = false;
                    break;
                default:
                    break;
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(2)); // Pequeña pausa para evitar un uso excesivo de CPU
    }

    // Mensaje de salida después de salir del bucle
    std::cout << "SALIENDO DEL PROGRAMA" << std::endl;

    return 0;
}


#include <iostream>
#include <cstdlib> // Necesario para rand() y srand()
#include <ctime>   // Necesario para time()

using namespace std;

int main() {
    // Inicializamos la semilla para números aleatorios
    srand(time(0));

    // Generamos el número del dado (1 al 6)
    int dado = rand() % 6 + 1;
    int intento = 0;

    // Variables para los intentos
    int intentosMaximos = 0;
    int intentosUsados = 0;

    // Variable como interruptor del juego
    bool sigueIntentando = true;

    cout << "========================================" << endl;
    cout << "   ¡ADIVINA EL NÚMERO DEL DADO (1-6)!   " << endl;
    cout << "========================================" << endl;

    // Pedimos al usuario que elija el límite de intentos
    cout << "¿En cuantos intentos crees poder adivinar?: ";
    cin >> intentosMaximos;

    // Se ejecuta MIENTRAS 'sigueIntentando' sea verdadero Y los intentos usados sean menores a los máximos
    while (intentosUsados < intentosMaximos && sigueIntentando == true ) {
        cout << "Intento " << (intentosUsados + 1) << " de " << intentosMaximos << endl;
        cout << "Ingresa tu pronostico (1 al 6): ";
        cin >> intento;

        // Validamos la entrada del usuario porq no faltan esos que ponen otros numeros raros
        if (intento < 1 || intento > 6) {
            cout << "Por favor, ingresa un numero valido entre 1 y 6 (este intento no cuenta)." << endl;
        }
        else if (intento == dado) {
            // Si acierta, desactivamos la variable para salir del bucle
            sigueIntentando = false;
            intentosUsados++; // Sumamos el último intento correcto
        }
        else {
            cout << "El dado rodo y cayo en otro numero." << endl;
            intentosUsados++; // Contamos el intento fallados
        }
    }

    // Se evalua cómo terminó el juego fuera del bucle
    if (intento == dado) {
        cout << "\¡FELICIDADES! Acertaste en " << intentosUsados << " intento(s)." << endl;
        cout << "El numero del dado era: " << dado << endl;
    } else {
        cout << "\¡Agotaste tus " << intentosMaximos << " intentos! Perdiste." << endl;
        cout << "El numero del dado era: " << dado << endl;
    }

    return 0;
}

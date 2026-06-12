#include "EstacionMeteorologica.h"

vector<Sensor*> listaSensores;

EstacionMeteorologica::EstacionMeteorologica(int capacidadMax, PantallaLCD* lcd) {
    this->capacidadMax = capacidadMax;
    this->cantidadSensores = 0;
    this->listaSensores = new Sensor*[capacidadMax]; // Reserva memoria para el arreglo de punteros a sensores
    this->lcd = lcd;
    this->indiceActual = 0;
}

EstacionMeteorologica::~EstacionMeteorologica() {
    
    // Liberar memoria de cada sensor individualmente
    for (int i = 0; i < cantidadSensores; i++) {
        delete listaSensores[i];    // Elimina cada objeto sensor del heap
    }
    delete[] listaSensores;         // Elimina el arreglo de punteros
}

bool EstacionMeteorologica::agregarSensor(Sensor* nuevoSensor) {
    if (cantidadSensores < capacidadMax) {
        
        listaSensores[cantidadSensores] = nuevoSensor; // Agrega el nuevo sensor al arreglo
        cantidadSensores++;                            // Incrementa el numero de sensores registrados
        return true;                                   // Sensor agregado exitosamente

    } else {
        return false;                               // No se pudo agregar, capacidad máxima alcanzada
    }
}

void EstacionMeteorologica::actualizarMediciones() {
    Serial.println("Mediciones:");

    for (int i = 0; i < cantidadSensores; i++) {
        Serial.println("-------------------------------------");
        listaSensores[i]->leerDatos(); // Invoca el método leerDatos() de cada sensor
    }
    Serial.println("-------------------------------------");
}

void EstacionMeteorologica::mostrarEnLCD() {
    for (int i = 0; i < cantidadSensores; i++) {
        
        // Muestra el nombre del sensor y sus datos utilizando el método mostrarSensor() de la clase PantallaLCD
        lcd->mostrarSensor(listaSensores[i]->getTipoSensor(), listaSensores[i]->obtenerDatosFormateados()); 

        // Pausa 2 segundos entre cada sensor para permitir la lectura antes de mostrar el siguiente
        delay(2000);        
    }
}

void EstacionMeteorologica::siguienteSensor() {
    indiceActual = (indiceActual + 1) % cantidadSensores;
}

void EstacionMeteorologica::anteriorSensor() {
    indiceActual = (indiceActual - 1 + cantidadSensores) % cantidadSensores;
}

void EstacionMeteorologica::mostrarSensorActual() {
    lcd->mostrarSensor(listaSensores[indiceActual]->getTipoSensor(), 
                       listaSensores[indiceActual]->obtenerDatosFormateados());
}
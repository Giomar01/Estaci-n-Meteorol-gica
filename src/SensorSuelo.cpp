#include "SensorSuelo.h"

SensorSuelo::SensorSuelo(int pin) : Sensor(pin, "Sensor de Humedad del Suelo") {
    this->humedadSuelo = 0.0;
}

SensorSuelo::~SensorSuelo() {
    // Destructor vacío, no hay recursos dinámicos que liberar
}

float SensorSuelo::getHumedadSuelo() const {
    return this->humedadSuelo;
}

void SensorSuelo::setHumedadSuelo(float humedad) {
    this->humedadSuelo = humedad;
}

void SensorSuelo::leerDatos() {
    // Lectura del valor analógico del sensor de humedad del suelo
    int valorAnalogico = analogRead(this->pin);
    
    // Conversión del valor analógico a porcentaje de humedad
    // La función map() asigna los valores según el rango del sensor
    // Se está suponiendo que 0 es "agua" y 4095 es "aire seco"
    this->humedadSuelo = map(valorAnalogico, 0, 4095, 0, 100); 

    // Limita que el valor esté entre 0 y 100 por seguridad
    this->humedadSuelo = constrain(this->humedadSuelo, 0, 100); 
}

string SensorSuelo::obtenerDatosFormateados() {
    char buffer[30];
    sprintf(buffer, "H(S): %.2f%%", this->humedadSuelo);
    return string(buffer);
}
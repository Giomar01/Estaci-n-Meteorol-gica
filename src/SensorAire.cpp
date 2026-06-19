#include "SensorAire.h"

SensorAire::SensorAire(int pin) : Sensor(pin, "Sensor de Calidad del Aire") {
    this->ppmCalidad = 0.0;
}

SensorAire::~SensorAire() {
    // No se requieren acciones específicas para el destructor
}

float SensorAire::getPpmCalidad() const {
    return this->ppmCalidad;
}

void SensorAire::setPpmCalidad(float ppm) {
    this->ppmCalidad = ppm;
}

void SensorAire::leerDatos() {
    int valorAnalogico = analogRead(this->pin);

    // Se implementa una fórmula de calibración específica para el sensor de aire
    // En este caso, se toma un rango de 0-1023 que corresponde a 0-500 ppm:

    this->ppmCalidad = (valorAnalogico / 1023.0) * 5000;

    // Impresión Serial
    Serial.print("Calidad del Aire: ");
    Serial.print(getPpmCalidad());
    Serial.println(" ppm");
}

string SensorAire::obtenerDatosFormateados() {
    char buffer[30];
    sprintf(buffer, "A: %.1f ppm", this->ppmCalidad);
    return string(buffer);
}
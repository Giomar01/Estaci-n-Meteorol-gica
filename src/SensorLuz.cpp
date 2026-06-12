#include "SensorLuz.h"

SensorLuz::SensorLuz(int pin) : Sensor(pin, "Sensor de Luz") {
    this->porcentajeLuz = 0.0;
}

SensorLuz::~SensorLuz() {
    // No se requiere limpieza específica
}

float SensorLuz::getPorcentajeLuz() const {
    return this->porcentajeLuz;
}

void SensorLuz::setPorcentajeLuz(float luz) {
    
    // Condicionales para asegurar que el porcentaje esté entre 0 y 100
    if (luz < 0.0) {
        this->porcentajeLuz = 0.0;
    } else if (luz > 100.0) {
        this->porcentajeLuz = 100.0;
    } else {
        this->porcentajeLuz = luz;
    }
}

void SensorLuz::leerDatos() {
    // Lectura del valor analógico del sensor de luz
    int valorAnalogico = analogRead(this->pin);
    
    // Conversión del valor analógico a porcentaje de luz
    // La función map() asigna los valores según el rango del sensor
    // Se está suponiendo que 4095 es "muy iluminado" y 0 es "oscuridad"
    this->porcentajeLuz = map(valorAnalogico, 4095, 0, 0, 100);

    // Limita que el valor esté entre 0 y 100 por seguridad
    this->porcentajeLuz = constrain(this->porcentajeLuz, 0, 100);

    // Impresión Serial
    Serial.print("Intensidad Luminica: ");
    Serial.print(getPorcentajeLuz());
    Serial.println(" %");
}

string SensorLuz::obtenerDatosFormateados() {
    char buffer[30];
    sprintf(buffer, "L: %.1f%%", this->porcentajeLuz);
    return string(buffer);
}
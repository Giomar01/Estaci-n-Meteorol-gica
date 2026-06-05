#include "EstacionMeteorologica.h"
#include "SensorAmbiental.h"
#include "SensorSuelo.h"
#include "SensorLuz.h"
#include "SensorAire.h"
#include "PantallaLCD.h"

// 1. Declaración de objetos globales a través de punteros para permitir su inicialización en setup()
PantallaLCD* pantallaLCD = nullptr;
EstacionMeteorologica* estacionMetereologica = nullptr;

void setup() {
  Serial.begin(115200);

  // 2. Inicialización de la pantalla LCD y la estación meteorológica
    pantallaLCD = new PantallaLCD(0x27, 16, 2);
    pantallaLCD->inicializar();
    pantallaLCD->mostrarMensaje("Iniciando...", "Iniciando...");

    estacionMetereologica = new EstacionMeteorologica(4, pantallaLCD);

    // 3. Creación de los sensores en la memoria 'heap' de la estación
    estacionMetereologica->agregarSensor(new SensorAmbiental(2)); // Pin digital DHT11
    estacionMetereologica->agregarSensor(new SensorSuelo(34));    // Pin analógico
    estacionMetereologica->agregarSensor(new SensorAire(35));     // Pin analógico
    estacionMetereologica->agregarSensor(new SensorLuz(33));      // Pin analógico
    
    delay(2000);
}

void loop() {
    // 4. Actualización de las mediciones de los sensores y su visualización en la LCD
    estacionMetereologica->actualizarMediciones();
    estacionMetereologica->mostrarEnLCD();
    
    delay(5000); // Espera 5 segundos antes de la siguiente actualización
}
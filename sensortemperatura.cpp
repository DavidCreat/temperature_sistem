#include <LiquidCrystal_I2C.h> // Librería para LCD I2C

LiquidCrystal_I2C lcd(0x27, 16, 2); // Dirección I2C del LCD y tamaño de la pantalla

const int pinSensorTemperatura = A0; // Pin analógico utilizado para leer la temperatura
const float temperaturaReferencia = 20.0; // Temperatura de referencia

void setup() {
  lcd.begin(16, 2); // Inicializar el LCD
  lcd.print("Sistema de Temperatura"); // Mensaje de bienvenida en el LCD
}

void loop() {
  float temperaturaActual = obtenerTemperatura(); // Obtener la temperatura actual

  lcd.setCursor(0, 1); // Establecer la posición del cursor en la segunda línea del LCD
  lcd.print("Temp: "); // Mostrar etiqueta "Temp" en el LCD
  lcd.print(temperaturaActual); // Mostrar la temperatura actual en el LCD

  delay(1000); // Esperar un segundo antes de la siguiente lectura
}

float obtenerTemperatura() {
  int valorSensor = analogRead(pinSensorTemperatura); // Leer el valor del sensor
  float voltaje = (valorSensor / 1024.0) * 5.0; // Convertir el valor en voltaje
  float temperatura = (voltaje - 0.5) * 100.0; // Calcular la temperatura en grados Celsius

  // Mapear la temperatura a un rango de 0 a 255 para una mejor visualización en el LCD
  temperatura = map(temperatura, 0, 100, 0, 255);

  return temperatura;
}

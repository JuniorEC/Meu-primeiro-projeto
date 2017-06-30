//Programa: Conectando Sensor Ultrassonico HC-SR04 ao Arduino
//Autor: João D. Junior
 
//Carrega a biblioteca do sensor ultrassonico Junto à Comunicação 
#include <Ultrasonic.h>
#include <Wire.h>

//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);

void setup()
{
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
  Wire.begin();
}
 
void loop()
{
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  //Exibe informacoes no serial monitor
  Serial.print("Distancia em cm: ");
  Serial.print(cmMsec);
  
  Wire.beginTransmission(8); //transmite ao device #8
  Wire.write(byte(cmMsec));
  Wire.endTransmission();
  Serial.print(" - Distancia em polegadas: ");
  Serial.println(inMsec);
  delay(1000);
  
}
//Bibliotecas necessárias
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>

//definição do pino digital utilizado
#define ONE_WIRE_BUS 2

//Instacia o Objeto oneWire e Seta o pino do Sensor para iniciar as leituras
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensor(&oneWire);

//Definição dos pinos dos leds
int led_verde=8;
int led_azul=9;
int led_amarelo=10;

//Definição do lcs
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  //inicialização do lcd
  lcd.init();
  //inicialização do sensor
  sensor.begin();
  //inicialização do terminal
  Serial.begin(9600);
  pinMode(led_verde,OUTPUT);
  pinMode(led_azul,OUTPUT);
  pinMode(led_amarelo,OUTPUT);
}

void loop() {
  //inicialização das variáveis
  float temperaturac=0;
  float temperaturaK= 0;
  float temperaturaF= 0;
  sensor.requestTemperatures();
  // A temperatura em Celsius para o dispositivo 1 no índice 0 (é possivel ligar varios sensores usando a mesma porta do arduino)
  float leitura = sensor.getTempCByIndex(0);
  temperaturac = leitura;
  temperaturaK = leitura + 273.15; // Converte Celsius para Kelvin
  temperaturaF = (temperaturac * 1.8) + 32.0; // Converte Celsius para Fahrenheit

  lcd.clear(); // Limpa o display
  lcd.setCursor(3, 0); // Coluna | Linha
  lcd.print("Celsius(C):");
  lcd.setCursor(5, 1);
  lcd.print(temperaturac, 3); //Exibe com 3 casas descimais 
  digitalWrite(led_verde, HIGH); //Liga led
  Serial.println("Temperatura em Celsius (C):" + String(temperaturac,3)); //Exibe no terminal
  delay(3000); 
  digitalWrite(led_verde, LOW); //Desliga led

  lcd.clear();
  lcd.setCursor(4, 0); 
  lcd.print("Kelvin(K):");
  lcd.setCursor(5, 1);
  digitalWrite(led_azul, HIGH);
  lcd.print(temperaturaK, 3); 
  Serial.println("Temperatura em Kelvin (K):" + String(temperaturaK, 3));
  delay(3000); 
  digitalWrite(led_azul, LOW);
  
  lcd.clear(); 
  lcd.setCursor(2, 0);
  lcd.print("Fahrenheit(F):");
  lcd.setCursor(5, 1);
  lcd.print(temperaturaF, 3); 
  digitalWrite(led_amarelo,HIGH);
  Serial.println("Temperatura em Fahrenheit (F): " + String (temperaturaF, 3));
  delay(3000);
  digitalWrite(led_amarelo,LOW);
}
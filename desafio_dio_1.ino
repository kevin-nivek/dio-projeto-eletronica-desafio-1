// C++ code
//
/*#include <OneWire.h>
#include <DallasTemperature.h>
*/
int pinLed = 8;
int  pinBuzzer = 13;
int pinMotor = 3;
int pinSensorTemp = 0;
int valorTMP = 0;

/*
OneWire oneWire(pinSensorTemp);
DallasTemperature sensors(&oneWire);
*/
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pinLed, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);
  pinMode(pinMotor,OUTPUT);
  
  Serial.begin(9600);
  digitalWrite(pinLed, HIGH);
  digitalWrite(pinBuzzer,LOW);
  digitalWrite(pinMotor,LOW);
  //sensors.begin();
}

void loop()
{
  
  valorTMP = analogRead(pinSensorTemp);
  Serial.print("Valor Temp: ");
  Serial.println(valorTMP);
  // Converte a leitura ADC para tensao em volts 
  float tensao = (valorTMP *5.0) /1023.0;
  // Formula do TMP36 para temperatura
  float tempC = (tensao -0.5)* 100;
  Serial.print("Valor Tensao: ");
  Serial.println(tensao);
  Serial.print("Valor TempC: ");
  Serial.println(tempC);
 /* 
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);
  Serial.print("Valor Temp: ");
  Serial.println(tempC);
 */
  if(tempC < 29.5){
  	digitalWrite(pinLed, LOW);
  	digitalWrite(pinBuzzer,LOW);
    digitalWrite(pinMotor,LOW);

  }
  else if(tempC >=29.5){
  	digitalWrite(pinLed, LOW);
  	digitalWrite(pinBuzzer,LOW);
    digitalWrite(pinMotor,HIGH);
    if(tempC >= 49.5){
   	 digitalWrite(pinLed, HIGH);
     digitalWrite(pinBuzzer,HIGH);
    }
      
  }
}
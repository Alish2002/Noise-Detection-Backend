#include <WiFi.h>
#include <IOXhop_FirebaseESP32.h>

#define sensorOnePin 13
#define sensorTwoPin 12
char ssid[] = "sushant";
char password[] = "098123098";
char firebaseHost[] = "firebase_host";
char firebaseKey[] = "firebase_key";

void setup(){
    pinMode(sensorOnePin, INPUT);
    pinMode(sensorTwoPin, INPUT);
    Serial.begin(9600);
    WiFi.begin(ssid, password);
    while(WiFi.status() != WL_CONNECTED){
        Serial.println("*");
        delay(500);
    }
    Serial.println("WiFi Connected");
    Firebase.begin(firebaseHost,firebaseKey);
}

void loop(){
  int sensorOneValue = digitalRead(sensorOnePin);
  int sensorTwoValue = digitalRead(sensorTwoPin);
  if(sensorOneValue == 1){
      Firebase.setInt("sensorOne", 1);
    }
   if(sensorTwoValue == 1){
    Firebase.setInt("sensorTwo", 1);
   }
}

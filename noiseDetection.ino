#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

const char ssid[] = "sushant";
const char password[] = "098123098";

#define FIREBASE_HOST "noisedetectionsystem-default-rtdb.asia-southeast1.firebasedatabase.app"
#define FIREBASE_AUTH "fQPwVQKfZUzG7VSiTTlL0nqIH7hUVhp8216tqOhk"

void setup()
{ 
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
     delay(500);
     Serial.print("*");
  }
  
  Serial.println("");
  Serial.println("WiFi connection Successful");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop(){
  
}

#include <ESP8266WiFi.h>

#define LED_PIN 13

unsigned int localPort = 8888;       // local port to listen for UDP packets

const char* timeServer = "time.nist.gov"; // time.nist.gov NTP server

const int NTP_PACKET_SIZE = 48; // NTP time stamp is in the first 48 bytes of the message

byte packetBuffer[NTP_PACKET_SIZE]; //buffer to hold incoming and outgoing packets

void setup() {
  pinMode(LED_PIN, OUTPUT);     // Initialize the LED_PIN pin as an output

  Serial.begin(115200);
  Serial.println();

  WiFi.begin("Pixel_4403", "minions-rule");

  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());

}

/**
 * WiFi
 */
void loop() {

    WiFiClient client;
    if (!client.connect(timeServer, localPort)) {
      Serial.println("connection failed");
      return;
    }

    for(int i=0; i<1203; i++){
        analogWrite(LED_PIN, i);
        delay(10);
    }
}

/**
 * Sweep
 */
// void loop() {
//     for(int i=0; i<1203; i++){
//         analogWrite(LED_PIN, i);
//         delay(10);
//     }
// }

/**
 * blink
 */

//
// // the loop function runs over and over again forever
// void loop() {
//   digitalWrite(LED_PIN, LOW);   // Turn the LED on (Note that LOW is the voltage level
//   // but actually the LED is on; this is because
//   // it is active low on the ESP-01)
//   delay(1000);                      // Wait for a second
//   digitalWrite(LED_PIN, HIGH);  // Turn the LED off by making the voltage HIGH
//   delay(2000);                      // Wait for two seconds (to demonstrate the active low LED)
// }

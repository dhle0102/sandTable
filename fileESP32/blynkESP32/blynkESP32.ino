#define BLYNK_USE_DIRECT_CONNECT

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */


#include <BlynkSimpleEsp32_BLE.h>
#include <BLEDevice.h>
#include <BLEServer.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "HgxrrxKUrgDcHAhEUqcgtArDY2xIzBqS";

BLYNK_CONNECTED() { // checks if there is a connection to Blynk.Cloud  
  Blynk.syncVirtual(V1); // get the latest value
}

BLYNK_WRITE(V1) // this command is listening when something is written to V1
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  if (pinValue == 1){
  digitalWrite(2,HIGH);
  Serial.println("ledon");
  } else if   (pinValue == 0){
  digitalWrite(2,LOW);
  Serial.println("ledoff");
  }
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Serial.println("Waiting for connections...");

  Blynk.setDeviceName("Blynk");

  Blynk.begin(auth);
}

void loop()
{
  Blynk.run();
}

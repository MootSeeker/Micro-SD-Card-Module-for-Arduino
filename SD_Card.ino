// SD Karte ansteuern

#include <SPI.h>
#include <SD.h>


File sdFile; 

const uint8_t csPin = 10;
 
void setup() 
{
  Serial.println(115200); 

  pinMode(csPin, OUTPUT); 

  if(SD.begin())
  {
    Serial.print("SD is ready"); 
  }
  else
  {
    Serial.println("SD card not found!"); 
  }

  sdFile = SD.open("test.csv", FILE_WRITE); 

  if(sdFile)
  {
    Serial.println("Write to SD card"); 

    sdFile.println("Dies ist ein Test String. "); 
    sdFile.close(); 

    Serial.println("Done!"); 
  }
}

void loop() 
{
  // Nothing
}

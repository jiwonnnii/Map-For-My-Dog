#include <SoftwareSerial.h>
#include <TinyGPS.h>
 
#define RXPIN 3
#define TXPIN 2

#define GPSBAUD 9600
 

TinyGPS gps;
SoftwareSerial uart_gps(RXPIN, TXPIN);
//SoftwareSerial BTSerial(0, 1);

void getgps(TinyGPS &gps);
 

void setup()
{

  Serial.begin(9600);
  //Sets baud rate of your GPS
  uart_gps.begin(GPSBAUD);
 // BTSerial.begin(9600);

}
 
void loop()
{
  while(uart_gps.available())     // While there is data on the RX pin...
  {
      int c = uart_gps.read();    // load the data into a variable...
      if(gps.encode(c))      // if there is a new valid sentence...
      {
        getgps(gps);         // then grab the data.
      }   
  }
}
 
// The getgps function will get and print the values we want.
void getgps(TinyGPS &gps)
{
  float latitude, longitude;
  gps.f_get_position(&latitude, &longitude);
  Serial.print(latitude,5); 
  Serial.print(", "); 
  Serial.println(longitude,5);

  //BTSerial.write(latitude);
  //BTSerial.write(longitude);

//  unsigned long chars;
 // unsigned short sentences, failed_checksum;
//  gps.stats(&chars, &sentences, &failed_checksum);

  delay(10000);
}


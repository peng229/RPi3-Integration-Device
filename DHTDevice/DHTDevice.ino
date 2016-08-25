#include </DHT/dht.h>
#define dht_dpin A0
dht DHT;

String serialNumber = "11:11:11:11:11:11";

void setup()
{
	Serial.begin(9600);
	delay(1000);
}

void loop()
{
	DHT.read11(dht_dpin);
 
  Serial.print("ID:");
  Serial.print(serialNumber);
	Serial.print(";");  
	Serial.print("TEMP:");
	Serial.print(DHT.temperature);
  Serial.println(";");  
  
  Serial.flush();  

  Serial.print("ID:");
  Serial.print(serialNumber);
  Serial.print(";");    
	Serial.print("HUM:");
	Serial.print(DHT.humidity);
  Serial.println(";");
  
  Serial.flush();  
	delay(1000);
}

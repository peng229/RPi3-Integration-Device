# AppIoT-RPi3-Integration-Device
This is just a simple device using a DHT11 sensor that measures temperature and humidity.
The measurements are communicated on the serial port and written line by line.
Each Device have a hard coded serial number as a mac address e.g. 11:11:11:11:11:11. this needs to be unique within the device network.
In order to change serial number download Arduino IDE at https://www.arduino.cc/en/Main/Software

The sensor data is communicated over serial communication line by line with the following format

ID:11:11:11:11:11:11;TEMP:13.0;

ID:11:11:11:11:11:11;HUM:42;

# Wiring
Connecting the DHT-11 sensor with the Arduino Nano is done as described below:

Wiring details: https://github.com/ApplicationPlatformForIoT/RPi3-Integration-Device/blob/master/Wiring.PNG

# Registration in AppIoT

# Device Type
Create a device type in AppIoT Settings -> Hardware Types -> Device Types -> Create
- Name: Arduino Device
- Type ID: 10001
- Sensor types: Temperature, Humidity

# Device template
Find the default template for the Arduino device Settings -> Hardware templates -> Device Templates. Scroll the list to find a Template named Default and has the type Arduino Device. Or just use the search filter and type arduino and you should find it easy.
Edit the template by clicking the name Default. Add a calculation:
- Name: Steam density
- Sensor Type: Steam density
- Report interval: 1

Use the following formula in the console
 
<code>
double t = input[1];            
double x = 4.7815706 + 0.34597292 * t + 0.0099365776 * Math.Pow(t,2) + 0.00015612096 * Math.Pow(t,3) + 1.9830825 * Math.Pow(10,-6) * Math.Pow(t,4) + 1.5773396 * Math.Pow(10,-8) * Math.Pow(t,5);
answer = x * input[2]/100d;
</code>

Klick OK and then save the device template.

# Create a device QR-Code
Use the MAC Address you coded into the device to generate a QR-Code for the Deployment Application to use when registering the device.
There are several websites to use when generating a QR-Code, here is one http://www.qr-code-generator.com/ 

Enter the following as content of the QR-Code: M;MAC ADDRESS;10001
- M = Device
- MAC ADDRESS = The Mac Address you got assigned the device.
- 10001 = Hardware Type Id of the device type registered in AppIoT.
Valid content would be M;11:11:11:11:11:11;10001

Once generated, you could print the QR-Code and put it on the outside of the Arduino Nano to easily scan when registering using the Deployment Application.

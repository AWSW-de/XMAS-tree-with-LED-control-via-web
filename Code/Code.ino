// ###############################################################################################################################
// #
// # Code for the printables "XMAS tree with LED control via web" project: https://www.printables.com/de/model/320339-xmas-tree-with-led-control-via-web
// #
// # Code by https://github.com/AWSW-de
// #
// # Released under license: GNU General Public License v3.0: https://github.com/AWSW-de/XMAS-tree-with-LED-control-via-web/blob/main/LICENSE
// #
// # Compatible with code version: V1.0.1
// #
// ###############################################################################################################################
/*
      ___           ___           ___           ___                    ___           ___           ___           ___                    ___                       ___           ___              
     |\__\         /\__\         /\  \         /\  \                  /\  \         /\  \         /\  \         /\  \                  /\__\          ___        /\  \         /\__\             
     |:|  |       /::|  |       /::\  \       /::\  \                 \:\  \       /::\  \       /::\  \       /::\  \                /:/ _/_        /\  \       \:\  \       /:/  /             
     |:|  |      /:|:|  |      /:/\:\  \     /:/\ \  \                 \:\  \     /:/\:\  \     /:/\:\  \     /:/\:\  \              /:/ /\__\       \:\  \       \:\  \     /:/__/              
     |:|__|__   /:/|:|__|__   /::\~\:\  \   _\:\~\ \  \                /::\  \   /::\~\:\  \   /::\~\:\  \   /::\~\:\  \            /:/ /:/ _/_      /::\__\      /::\  \   /::\  \ ___          
 ____/::::\__\ /:/ |::::\__\ /:/\:\ \:\__\ /\ \:\ \ \__\              /:/\:\__\ /:/\:\ \:\__\ /:/\:\ \:\__\ /:/\:\ \:\__\          /:/_/:/ /\__\  __/:/\/__/     /:/\:\__\ /:/\:\  /\__\         
 \::::/~~/~    \/__/~~/:/  / \/__\:\/:/  / \:\ \:\ \/__/             /:/  \/__/ \/_|::\/:/  / \:\~\:\ \/__/ \:\~\:\ \/__/          \:\/:/ /:/  / /\/:/  /       /:/  \/__/ \/__\:\/:/  /         
  ~~|:|~~|           /:/  /       \::/  /   \:\ \:\__\              /:/  /         |:|::/  /   \:\ \:\__\    \:\ \:\__\             \::/_/:/  /  \::/__/       /:/  /           \::/  /          
    |:|  |          /:/  /        /:/  /     \:\/:/  /              \/__/          |:|\/__/     \:\ \/__/     \:\ \/__/              \:\/:/  /    \:\__\       \/__/            /:/  /           
    |:|  |         /:/  /        /:/  /       \::/  /                              |:|  |        \:\__\        \:\__\                 \::/  /      \/__/                       /:/  /            
     \|__|         \/__/         \/__/         \/__/                                \|__|         \/__/         \/__/                  \/__/                                   \/__/             
      ___       ___           ___                    ___           ___           ___           ___           ___           ___           ___                                                     
     /\__\     /\  \         /\  \                  /\  \         /\  \         /\__\         /\  \         /\  \         /\  \         /\__\                                                    
    /:/  /    /::\  \       /::\  \                /::\  \       /::\  \       /::|  |        \:\  \       /::\  \       /::\  \       /:/  /                                                    
   /:/  /    /:/\:\  \     /:/\:\  \              /:/\:\  \     /:/\:\  \     /:|:|  |         \:\  \     /:/\:\  \     /:/\:\  \     /:/  /                                                     
  /:/  /    /::\~\:\  \   /:/  \:\__\            /:/  \:\  \   /:/  \:\  \   /:/|:|  |__       /::\  \   /::\~\:\  \   /:/  \:\  \   /:/  /                                                      
 /:/__/    /:/\:\ \:\__\ /:/__/ \:|__|          /:/__/ \:\__\ /:/__/ \:\__\ /:/ |:| /\__\     /:/\:\__\ /:/\:\ \:\__\ /:/__/ \:\__\ /:/__/                                                       
 \:\  \    \:\~\:\ \/__/ \:\  \ /:/  /          \:\  \  \/__/ \:\  \ /:/  / \/__|:|/:/  /    /:/  \/__/ \/_|::\/:/  / \:\  \ /:/  / \:\  \                                                       
  \:\  \    \:\ \:\__\    \:\  /:/  /            \:\  \        \:\  /:/  /      |:/:/  /    /:/  /         |:|::/  /   \:\  /:/  /   \:\  \                                                      
   \:\  \    \:\ \/__/     \:\/:/  /              \:\  \        \:\/:/  /       |::/  /     \/__/          |:|\/__/     \:\/:/  /     \:\  \                                                     
    \:\__\    \:\__\        \::/__/                \:\__\        \::/  /        /:/  /                     |:|  |        \::/  /       \:\__\                                                    
     \/__/     \/__/         ~~                     \/__/         \/__/         \/__/                       \|__|         \/__/         \/__/                                                    
*/


// ###############################################################################################################################
// #
// # Code version:
// #
// ###############################################################################################################################
String code_version = "V1.0.0";


// ###############################################################################################################################
// # Includes:
// #
// # You will need to add the following libraries to your Arduino IDE to use the project:
// # - Adafruit NeoPixel              // by Adafruit:                     https://github.com/adafruit/Adafruit_NeoPixel
// # - WiFiManager                    // by tablatronix / tzapu:          https://github.com/tzapu/WiFiManager
// #
// ###############################################################################################################################
#include <ESP8266WiFi.h>              // Used to connect the ESP8266 NODE MCU to your WiFi
#include <DNSServer.h>                // Used for name resolution for the internal webserver
#include <ESP8266WebServer.h>         // Used for the internal webserver
#include <WiFiManager.h>              // Used for the WiFi Manager option to be able to connect the ESP to your WiFi without code changes
#include <EEPROM.h>                   // Used to store the in the internal configuration page set configuration on the ESP internal storage
#include <Adafruit_NeoPixel.h>        // Used to drive the NeoPixel LEDs
#include <ESP8266mDNS.h>              // Used for the internal update function
#include <ESP8266HTTPUpdateServer.h>  // Used for the internal update function
#include "languages.h"                // Language translations


// ###############################################################################################################################
// # Hardware settings:
// ###############################################################################################################################
#define N_PIXELS 12  // Number of pixels in strand
#define BAT_PIN A0   // Battery level monitor via analog pin
#define LED_PIN D2   // NeoPixel LED strand is connected to this pin

// ###############################################################################################################################
// # LED default settings:
// ###############################################################################################################################
int redVal = 0;      // Default color RED
int greenVal = 255;  // Default color GREEN
int blueVal = 0;     // Default color BLUE
int intensity = 42;  // Default LED intensity (0..255)


// ###############################################################################################################################
// # Function select settings:
// ###############################################################################################################################
String header;          // Variable to store the HTTP request
int switchLangWeb = 0;  // Language default setting (0 = german, 1 = english, 2...x = for future use)

int ModeLED = 1;
  
  Adafruit_NeoPixel LEDs = Adafruit_NeoPixel(N_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);


// ###############################################################################################################################
// # WiFi and http server settings:
// ###############################################################################################################################
ESP8266HTTPUpdateServer httpUpdater;        // Update server
ESP8266WebServer httpServer(2022);          // Update server port
WiFiServer server(80);                      // Set web server port number to 80
String UpdatePath = "-";                    // Update via Hostname
String UpdatePathIP = "-";                  // Update via IP-address
#define DEFAULT_AP_NAME "XMASTREELED"       // WiFi access point name of the ESP8266
#define AP_TIMEOUT 240                      // Timeout in seconds for AP / WLAN config
std::unique_ptr<ESP8266WebServer> server1;  // REST function web server


// ###########################################################################################################################################
// # Parameter record to store to the EEPROM of the ESP:
// ###########################################################################################################################################
struct parmRec {
  int pRed;
  int pGreen;
  int pBlue;
  int pIntensity;
  int pModeLED;
  int pswitchLangWeb;
  int pCheckSum;
} parameter;


// ###############################################################################################################################
// # Setup function to run at startup:
// ###############################################################################################################################
void setup() {
  Serial.begin(115200);
  delay(1000);
  readEEPROM();  // get persistent data from EEPROM
  LEDs.begin();
  Serial.println("#######################################");
  Serial.print("# XMAS tree with LED control via web: ");
  Serial.print(code_version);
  Serial.println(" #");
  Serial.println("#######################################");

  // WiFiManager:
  show_wifi(LEDs.Color(0, 0, 255));
  delay(1500);
  bool WiFires;
  WiFiManager wifiManager;
  wifiManager.setConfigPortalTimeout(AP_TIMEOUT);  // Max wait for 3 minutes
  WiFires = wifiManager.autoConnect(DEFAULT_AP_NAME);
  if (!WiFires) {
    Serial.println("Failed to connect to WiFi");
    show_wifi(LEDs.Color(255, 0, 0));
    delay(1500);
  } else {
    Serial.println("Connected to WiFi.");
    show_wifi(LEDs.Color(0, 255, 0));
    delay(1500);
  }
  colorWipe(LEDs.Color(0, 0, 0), 0);  // LEDs off

  // Web update function setup:
  MDNS.begin(WiFi.getHostname());
  httpUpdater.setup(&httpServer);
  httpServer.begin();
  MDNS.addService("http", "tcp", 2022);
  MDNS.addService("http", "tcp", 80);
  Serial.println("##################################################################################");
  Serial.print("Hostname: ");
  Serial.println(WiFi.getHostname());
  Serial.print("IP-address: ");
  Serial.println(WiFi.localIP().toString());
  UpdatePath = "http://" + String(WiFi.getHostname()) + ".local:2022/update";
  UpdatePathIP = "http://" + WiFi.localIP().toString() + ":2022/update";
  Serial.print("Web Update Link: ");
  Serial.println(UpdatePath);
  Serial.print("Web Update Link: ");
  Serial.println(UpdatePathIP);
  Serial.print("Web Config Link: ");
  Serial.println("http://" + String(WiFi.getHostname()));
  Serial.print("Web Config Link: ");
  Serial.println("http://" + WiFi.localIP().toString());
  Serial.println("Web server for configuration and update online...");
  Serial.println("##################################################################################");
  server.begin();

  // REST URL server:
  server1.reset(new ESP8266WebServer(WiFi.localIP(), 55555));
  server1->on("/", handleRoot);
  server1->on("/espwifireset", ESPWifiReset);
  server1->begin();

  // Load set language:
  setLanguage(switchLangWeb);

  // LED Test:
  rainbow(10);
}


// ###############################################################################################################################
// # Loop funtion to run all the time:
// ###############################################################################################################################
void loop() {
  ESP.wdtFeed();  // Reset watchdog timer

  LEDs.setBrightness(intensity);


 /* case 1:
    buttonCount = 1;
    if (ModeLED) {
      vu_meter7();  // VU meter 7 - Lines Coloured
    break;*/
 
 /*  case 10:
    buttonCount = 10;
    if (ModeLED7) {
      theaterChase(LEDs.Color(127, 127, 127), 50);  // White flickering LED function (Adafruit NeoPixel demo)
    } else {
      buttonCount = buttonCount + 1;
    }
    break;
  case 11:
    buttonCount = 11;
    if (ModeLED8) {
      rainbow(10);  // Rainbow LED function (Adafruit NeoPixel demo)
    } else {
      buttonCount = buttonCount + 1;
    }
    break;
  case 12:
    buttonCount = 12;
    if (ModeLED9) {
      theaterChaseRainbow(50);  // Flickering rainbow LED function (Adafruit NeoPixel demo)
    } else {
      buttonCount = buttonCount + 1;
    }
    break;
}*/

// Check, whether something has been entered on Config Page
checkClient();

// Web update start:
httpServer.handleClient();
MDNS.update();

// REST function web server:
server1->handleClient();
}


// ###########################################################################################################################################
// # Try to read settings from FLASH - initialize if WLAN ID read from flash is invalid:
// ###########################################################################################################################################
void readEEPROM() {
  Serial.print("Copy ");
  Serial.print(sizeof(parameter));
  Serial.println(" bytes from flash memory to EPROM buffer: ");

  // initialize space to read parameter
  EEPROM.begin(sizeof(parameter));
  delay(10);

  // Copy bytes from EEPROM
  byte* p = (byte*)(void*)&parameter;

  int check = 0;
  for (int L = 0; L < sizeof(parameter); ++L) {
    byte b = EEPROM.read(L);

    // Don't take the checkSum itself into account
    if (L < sizeof(parameter) - sizeof(parameter.pCheckSum))
      check = check + b;

    *p++ = b;
    /* Serial.print("Read FLASH Byte ");
      Serial.print(L);
      Serial.print(" = ");
      Serial.println(b); */
  }

  // Check checksum
  Serial.print("Compare checksums: ");
  Serial.print(check);
  Serial.print("/");
  Serial.println(parameter.pCheckSum);

  if (check == parameter.pCheckSum) {
    Serial.println("Checksum match! set parameter from EEPROM");
    redVal = parameter.pRed;
    greenVal = parameter.pGreen;
    blueVal = parameter.pBlue;
    ModeLED = parameter.pModeLED;
    switchLangWeb = parameter.pswitchLangWeb;
    intensity = parameter.pIntensity;
  }
}


// ###########################################################################################################################################
// # Write current parameter settings to flash:
// ###########################################################################################################################################
void writeEEPROM() {
  Serial.println("Write parameter into EEPRom");
  parameter.pRed = redVal;
  parameter.pGreen = greenVal;
  parameter.pBlue = blueVal;
  parameter.pIntensity = intensity;
  parameter.pModeLED = ModeLED;
  parameter.pswitchLangWeb = switchLangWeb;

  // calculate checksum
  byte* p = (byte*)(void*)&parameter;
  parameter.pCheckSum = 0;
  for (int L = 0; L < sizeof(parameter) - sizeof(parameter.pCheckSum); ++L) {
    byte b = *p++;
    parameter.pCheckSum = parameter.pCheckSum + b;
  }
  // Write data to EEPROM
  p = (byte*)(void*)&parameter;
  for (int L = 0; L < sizeof(parameter); ++L) {
    byte b = *p++;
    EEPROM.write(L, b);
    // Serial.print("Write FLASH Byte ");
    // Serial.print(L);
    // Serial.print(" = ");
    // Serial.println(b);
  }
  EEPROM.commit();
}


// ###############################################################################################################################
// # HTTP server configuration:
// ###############################################################################################################################
void checkClient() {
  //Serial.println("check for client");
  WiFiClient client = server.available();  // Listen for incoming clients // @suppress("Abstract class cannot be instantiated")

  if (client) {                     // If a new client connects,
    Serial.println("New Client.");  // print a message out in the serial port
    String currentLine = "";        // make a String to hold incoming data from the client
    while (client.connected()) {    // loop while the client's connected
      if (client.available()) {     // if there's bytes to read from the client,
        char c = client.read();     // read a byte, then
        Serial.write(c);            // print it out the serial monitor
        header += c;
        if (c == '\n') {  // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            // Display the HTML web page:
            // ##########################
            client.println("<!DOCTYPE html><html>");
            client.println("<head><title>" + ProjectName + " - " + String(WiFi.getHostname()) + "</title><meta charset=\"utf-8\" name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #77878A;}</style></head>");


            // Web Page Heading:
            // #################
            String title = "<body><h1>" + ProjectNameLong + " - " + txtSettings + ": ";
            title = title + code_version;
            title = title + "</h1>";
            client.println(title);
            client.println("<form action=\"/setWC.php\">");


            // Convert color into hex settings:
            // ################################
            char hex_main[7] = { 0 };
            sprintf(hex_main, "#%02X%02X%02X", redVal, greenVal, blueVal);
            // Main color select:
            client.println("<hr><h2>" + txtLEDsettings + ":</h2><br>");
            client.println("<label for=\"favcolor\">" + txtLEDcolor + ": </label>");
            client.print("<input type=\"color\" id=\"favcolor\" name=\"favcolor\" value=\"");
            client.print(hex_main);
            client.print("\"><br><br>");


            // Intensity:
            // ##############
            client.print("<label for=\"intensity\">" + txtIntensity + ": </label>");
            client.print("<input type='range' min='1' max='128' name='intensity' value=");         // Limited to 128 to avoid to much power usage of the power supply
            client.print(intensity);                                                               // set the value of the slider based upon the previous page load value
            client.println(" style='height:30px; width:200px' oninput='showValue(this.value)'>");  // was onchange event
            client.print("<span id='valrange'>");
            client.print(intensity);  // set the javascript initial value
            client.println("</span>");
            client.println("<script type='text/javascript'>\r\nfunction showValue(newValue)\r\n{\r\ndocument.getElementById('valrange').innerHTML=newValue;\r\n}\r\n</script>\r\n");
            client.println("</label><br><hr>");


            // VU meter and animations:
            // ########################
            client.println("<h2>" + txtVUandAnm + ":</h2>");
            client.println("<label for=\"ModeLED\">" + txtVU1 + ": </label>");
            client.print("<input type=\"checkbox\" id=\"ModeLED\" name=\"ModeLED\"");
            if (ModeLED) {
              client.print(" checked");
              client.print("> " + txtVU1lbl + "<br><br>");
            } else {
              client.print("> " + txtVU1lbl + "<br><br>");
            }

            client.println("<label for=\"ModeLED7\">" + txtAnm1 + ": </label>");
            client.print("<input type=\"checkbox\" id=\"ModeLED7\" name=\"ModeLED7\"");
            if (ModeLED7) {
              client.print(" checked");
              client.print("> " + txtAnm1lbl + "<br><br>");
            } else {
              client.print("> " + txtAnm1lbl + "<br><br>");
            }

            client.println("<label for=\"ModeLED8\">" + txtAnm2 + ": </label>");
            client.print("<input type=\"checkbox\" id=\"ModeLED8\" name=\"ModeLED8\"");
            if (ModeLED8) {
              client.print(" checked");
              client.print("> " + txtAnm2lbl + "<br><br>");
            } else {
              client.print("> " + txtAnm2lbl + "<br><br>");
            }

            client.println("<label for=\"ModeLED9\">" + txtAnm3 + ": </label>");
            client.print("<input type=\"checkbox\" id=\"ModeLED9\" name=\"ModeLED9\"");
            if (ModeLED9) {
              client.print(" checked");
              client.print("> " + txtAnm3lbl + "<br><br>");
            } else {
              client.print("> " + txtAnm3lbl + "<br><br>");
            }
            client.print("<hr>");

            // Update function:
            // ################
            client.println("<h2>" + txtUpdate0 + ":</h2>");
            client.println("<label>" + txtUpdate2 + ":</label><br><br>");
            client.println("<a href=" + UpdatePath + " target='_blank'>" + UpdatePath + "</a><br><br>");
            client.println("<a href=" + UpdatePathIP + " target='_blank'>" + UpdatePathIP + "</a><br><br>");
            client.println("<label>" + txtUpdate3 + "</label><br>");
            client.println("<br><br><label>" + txtUpdate4 + ":</label>");
            client.println("<a href='https://github.com/AWSW-de/Music-reactive-LEDs-LED-cube' target='_blank'>" + txtUpdate5 + "</a><br><hr>");

            // Language selection:
            // ###################
            client.println("<br><label for=\"switchLangWeb\"><h2>" + languageSelect + ":</h2></label>");
            client.println("<fieldset>");
            client.println("<div>");
            client.println("<input type='radio' id='idlang0' name='switchLangWeb' value='0'");
            if (switchLangWeb == 0) {
              client.print(" checked");
              client.print(">");
            } else {
              client.print(">");
            }
            client.println("<label for='idlang0'>" + languageInt0 + "</label>");
            client.println("</div>");
            client.println("<div>");
            client.println("<input type='radio' id='idlang1' name='switchLangWeb' value='1'");
            if (switchLangWeb == 1) {
              client.print(" checked");
              client.print(">");
            } else {
              client.print(">");
            }
            client.println("<label for='idlang1'>" + languageInt1 + "</label>");
            client.println("</div>");
            client.println("</fieldset>");
            client.println("<br><br><hr>");

            // Reset WiFi configuration:
            // #########################
            client.println("<h2>" + txtWiFi0 + ":</h2><br>");
            client.println("<label>" + txtWiFi1 + "</label><br>");
            client.println("<br><a href= http://" + WiFi.localIP().toString() + ":55555/espwifireset target='_blank'>" + txtWiFi0 + "</a><br><br><hr>");

            // Save settings button:
            // #####################
            client.println("<br><br><input type='submit' value='" + txtSaveSettings + "'>");
            client.print("<br><br><br><hr><br>");
            client.println("</form>");
            client.println("</body></html>");
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else {  // if you got a newline, then clear currentLine
            if (currentLine.startsWith("GET /setWC.php?")) {
              Serial.print("Current request: ");
              Serial.println(currentLine);

              colorWipe(LEDs.Color(0, 0, 0), 0);  // LEDs off

              // Check for color settings:
              // #########################
              int pos = currentLine.indexOf("favcolor=%23");
              if (pos >= 0) {
                char* succ;
                String newColStr = currentLine.substring(pos + 12, pos + 18);
                String newRed = newColStr.substring(0, 2);
                redVal = strtol(newRed.begin(), &succ, 16);
                String newGreen = newColStr.substring(2, 4);
                greenVal = strtol(newGreen.begin(), &succ, 16);
                String newBlue = newColStr.substring(4, 6);
                blueVal = strtol(newBlue.begin(), &succ, 16);
              }

              // Check for ModeLED:
              // ##################
              if (currentLine.indexOf("&ModeLED=on") >= 0) {
                ModeLED = 1;
              } else {
                ModeLED = 0;
              }

              // Check for language setting:
              // ###########################
              pos = currentLine.indexOf("&switchLangWeb=");
              if (pos >= 0) {
                String LangWebStr = currentLine.substring(pos + 15);
                pos = LangWebStr.indexOf("&");
                if (pos > 0)
                  LangWebStr = LangWebStr.substring(0, pos);
                switchLangWeb = LangWebStr.toInt();
                setLanguage(switchLangWeb);
              }


              // Get intensity:
              // ##############
              pos = currentLine.indexOf("&intensity=");
              if (pos >= 0) {
                String intStr = currentLine.substring(pos + 11, pos + 14);
                pos = intStr.indexOf(" ");  // " " instead of "&" !!!
                if (pos > 0)
                  intStr = intStr.substring(0, pos);
                intensity = intStr.toInt();
              }


              // Save data to EEPROM:
              // ####################
              writeEEPROM();  // save DATA to EEPROM
            }
            currentLine = "";  // Clear the current command line
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    header = "";    // Clear the header variable
    client.stop();  // Close the connection
    Serial.println("Web client disconnected.");
    Serial.println("######################################################################################################");
  }
}


// ###############################################################################################################################
// # User selected color
// ###############################################################################################################################
void UserColor() {
for (int i = 0; i = N_PIXELS; i++) {
    LEDs.setPixelColor(i, LEDs.Color(redVal, greenVal, blueVal);
  }
  LEDs.show();
}


// ###############################################################################################################################
// # Theater-marquee-style chasing lights:
// ###############################################################################################################################
void theaterChase(uint32_t color, int wait) {
  for (int a = 0; a < 10; a++) {   // Repeat 10 times...
    for (int b = 0; b < 3; b++) {  //  'b' counts from 0 to 2...
      LEDs.clear();                //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of LEDs in steps of 3...
      for (int c = b; c < LEDs.numPixels(); c += 3) {
        LEDs.setPixelColor(c, color);  // Set pixel 'c' to value 'color'
      }
      LEDs.show();  // Update LEDs with new contents
      delay(wait);  // Pause for a moment
    }
  }
}


// ###############################################################################################################################
// # Rainbow cycle along whole LEDs. Pass delay time (in ms) between frames:
// ###############################################################################################################################
void rainbow(int wait) {
  // Hue of first pixel runs 3 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 3*65536. Adding 256 to firstPixelHue each time
  // means we'll make 3*65536/256 = 768 passes through this outer loop:
  for (long firstPixelHue = 0; firstPixelHue < 3 * 65536; firstPixelHue += 256) {
    for (int i = 0; i < LEDs.numPixels(); i++) {  // For each pixel in LEDs...
      // Offset pixel hue by an amount to make one full revolution of the
      // color wheel (range of 65536) along the length of the LEDs
      // (LEDs.numPixels() steps):
      int pixelHue = firstPixelHue + (i * 65536L / LEDs.numPixels());
      // LEDs.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
      // optionally add saturation and value (brightness) (each 0 to 255).
      // Here we're using just the single-argument hue variant. The result
      // is passed through LEDs.gamma32() to provide 'truer' colors
      // before assigning to each pixel:
      LEDs.setPixelColor(i, LEDs.gamma32(LEDs.ColorHSV(pixelHue)));
    }
    LEDs.show();  // Update LEDs with new contents
    delay(wait);  // Pause for a moment
  }
}


// ###############################################################################################################################
// # Rainbow-enhanced theater marquee. Pass delay time (in ms) between frames
// ###############################################################################################################################
void theaterChaseRainbow(int wait) {
  int firstPixelHue = 0;           // First pixel starts at red (hue 0)
  for (int a = 0; a < 30; a++) {   // Repeat 30 times...
    for (int b = 0; b < 3; b++) {  //  'b' counts from 0 to 2...
      LEDs.clear();                //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of LEDs in increments of 3...
      for (int c = b; c < LEDs.numPixels(); c += 3) {
        // hue of pixel 'c' is offset by an amount to make one full
        // revolution of the color wheel (range 65536) along the length
        // of the LEDs (LEDs.numPixels() steps):
        int hue = firstPixelHue + c * 65536L / LEDs.numPixels();
        uint32_t color = LEDs.gamma32(LEDs.ColorHSV(hue));  // hue -> RGB
        LEDs.setPixelColor(c, color);                       // Set pixel 'c' to value 'color'
      }
      LEDs.show();                  // Update LEDs with new contents
      delay(wait);                  // Pause for a moment
      firstPixelHue += 65536 / 90;  // One cycle of color wheel over 90 frames
    }
  }
}


// ###############################################################################################################################
// # Show WiFi status icon:
// ###############################################################################################################################
void show_wifi(uint32_t color) {
  LEDs.setBrightness(15);
  int myArray[] = { 0, 7, 56, 63, 64, 71, 120, 127 };
  for (int element : myArray) {
    LEDs.setPixelColor(element, color);
  }
  LEDs.show();
}


// ###############################################################################################################################
// # Color wheel function:
// ###############################################################################################################################
// Input a value 0 to 255 to get a color value.
// The colors are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if (WheelPos < 85) {
    return LEDs.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if (WheelPos < 170) {
    WheelPos -= 85;
    return LEDs.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
    WheelPos -= 170;
    return LEDs.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}


// ###############################################################################################################################
// # Color Wipe function:
// ###############################################################################################################################
void colorWipe(uint32_t color, uint8_t wait) {
  for (uint16_t i = 0; i < LEDs.numPixels(); i++) {
    LEDs.setPixelColor(i, color);
  }
  LEDs.show();
}


// ###########################################################################################################################################
// # REST command function: ROOT
// ###########################################################################################################################################
void handleRoot() {
  WiFiClient client = server.available();
  server1->send(200, "text/plain", "REST web server active");
  Serial.print("REST web server active on port: ");
  Serial.println(55555);
  client.stop();
}


// ###########################################################################################################################################
// # Reset the WiFi configuration:
// ###########################################################################################################################################
void ESPWifiReset() {
  WiFiClient client = server.available();
  server1->send(200, "text/plain", "WIFI SETTING WERE SET TO DEFAULT... ESP WILL NOW RESTART... PLEASE CONFIGURE WIFI AGAIN...");
  delay(5000);
  client.stop();
  WiFi.disconnect(true);
  delay(1500);
  WiFiManager wifiManager;
  delay(1500);
  wifiManager.resetSettings();
  delay(1500);
  Serial.println("################################################################################################");
  Serial.println("# WIFI SETTING WERE SET TO DEFAULT... ESP WILL NOW RESTART... PLEASE CONFIGURE WIFI AGAIN...   #");
  Serial.println("################################################################################################");
  delay(3000);
  ESP.restart();
}


// ###############################################################################################################################
// # EOF - You have successfully reached the end of the code - well done ;-)
// ###############################################################################################################################
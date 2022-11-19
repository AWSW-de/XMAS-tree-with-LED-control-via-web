// ###############################################################################################################################
// #
// # Code for the printables "XMAS tree with LED control via web" project: https://www.printables.com/de/model/320339-xmas-tree-with-led-control-via-web
// #
// # Code by https://github.com/AWSW-de 
// #
// # Released under license: GNU General Public License v3.0: https://github.com/AWSW-de/XMAS-tree-with-LED-control-via-web/blob/main/LICENSE
// #
// # Compatible with code version: V1.0.2
// #
// ###############################################################################################################################


// ###############################################################################################################################
// # Default texts in german language:
// ###############################################################################################################################
// General texts:
String ProjectName, ProjectNameLong, languageSelect, languageInt0, languageInt1, txtSaveSettings;
// LED settings:
String txtSettings, txtLEDsettings, txtLEDcolor, txtIntensity;
// Update function:
String txtUpdate0, txtUpdate2, txtUpdate3, txtUpdate4, txtUpdate5;
// WiFi:
String txtWiFi0, txtWiFi1;
// Restart
String txtRestart0, txtRestart1;
// Colors and animations:
String txtVU1, txtAnm1, txtAnm2, txtAnm3, txtVUandAnm;
String txtVU1lbl, txtAnm1lbl, txtAnm2lbl, txtAnm3lbl;


void setLanguage(int lang) {
  // ###############################################################################################################################
  // # Translations for: DE
  // ###############################################################################################################################
  if (lang == 0) {  // DEUTSCH
    // Allgemeine Texte:
    ProjectName = "XMASTREELED";
    ProjectNameLong = "LED Weihnachtsbaum";
    languageSelect = "Sprache";
    languageInt0 = "Deutsch";
    languageInt1 = "Englisch";
    txtSaveSettings = "Einstellungen speichern";

    // LED Einstellungen:
    txtSettings = "Einstellungen";
    txtLEDsettings = "LED Einstellungen";
    txtLEDcolor = "Farbe";
    txtIntensity = "Helligkeit";

    // Update Funktion:
    txtUpdate0 = "Update";
    txtUpdate2 = "Über einen der folgenden Links kann die LEDCUBE über den Browser ohne Arduino IDE aktualisiert werden";
    txtUpdate3 = "Hinweis: Es wird eine in der Arduino IDE mit Strg+Alt+S zuvor erstellte .BIN Datei des Sketches benötigt, die über die Option 'Update Firmware' hochgeladen werden kann.";
    txtUpdate4 = "Die notwendige Update-Datei kann hier heruntergeladen werden";
    txtUpdate5 = "Repository auf GitHub";

    // WLAN:
    txtWiFi0 = "WLAN Einstellungen zurücksetzen";
    txtWiFi1 = "WLAN Einstellungen zurücksetzen und neu starten?";

    // VU-meters and animations:
    txtVUandAnm = "Auswahl Farbe und Animationen";
    txtVU1 = "Benutzer definierte Farbe";
    txtAnm1 = "Animation 1";
    txtAnm2 = "Animation 2";
    txtAnm3 = "Animation 3";
    txtVU1lbl = "Benutzerdefinierte Farbe";
    txtAnm1lbl = "Weißes Flackern";
    txtAnm2lbl = "Regenbogen";
    txtAnm3lbl = "Regenbogen Flackern";
  }


  // ###############################################################################################################################
  // # Translations for: EN
  // ###############################################################################################################################
  if (lang == 1) {  // ENGLISH
    // General texts:
    ProjectName = "XMASTREELED";
    ProjectNameLong = "LED XMAS tree";
    languageSelect = "Language";
    languageInt0 = "German";
    languageInt1 = "English";
    txtSaveSettings = "Save settings";

    // LED settings:
    txtSettings = "settings";
    txtLEDsettings = "LED settings";
    txtLEDcolor = "Color";
    txtIntensity = "Intensity";

    // Update function:
    txtUpdate0 = "Update";
    txtUpdate2 = "Using one of the links below, the LEDCUBE can be updated via the browser without the Arduino IDE";
    txtUpdate3 = "Note: A .BIN file of the sketch previously created in the Arduino IDE with Ctrl+Alt+S is required, which can be uploaded via the 'Update Firmware' option.";
    txtUpdate4 = "The necessary update file can be downloaded here";
    txtUpdate5 = "Repository on GitHub";

    // WiFi:
    txtWiFi0 = "Reset WiFi settings";
    txtWiFi1 = "Reset wifi settings and restart?";

    // VU-meters and animations:
    txtVUandAnm = "Color selection and animations";
    txtVU1 = "User selected color";
    txtAnm1 = "Animation 1";
    txtAnm2 = "Animation 2";
    txtAnm3 = "Animation 3";
    txtVU1lbl = "User selected color";
    txtAnm1lbl = "White flicker";
    txtAnm2lbl = "Rainbow";
    txtAnm3lbl = "Rainbow flicker";
  }
}
// ###############################################################################################################################
// # EOF - You have successfully reached the end of the code - well done ;-)
// ###############################################################################################################################
 
////////////////////////////////////////////////////////////
//                                                        //
//    HomeSpan: A HomeKit implementation for the ESP32    //
//    ------------------------------------------------    //
//                    Relais connecté                     //
//                          Ged                           //
////////////////////////////////////////////////////////////

// Programme développé sur la base de l'exemple 5 de la 
// Librarie HomeSpan

#include "HomeSpan.h" 
#include "DEV_LED.h"

void setup() {

  //W dans le moniteur série pour configurer le nom du réseau 
  // Wi-Fi et son mot de passe baud rate à 115200
  // Code dans Apple Home : 466-37-726

  Serial.begin(115200);

  homeSpan.begin(Category::Lighting,"HomeSpan LEDs");
  
  new SpanAccessory(); 
  
    new Service::AccessoryInformation(); 
      new Characteristic::Name("Relais Sallon"); 
      new Characteristic::Manufacturer("Jay&Co"); 
      new Characteristic::SerialNumber("Jeje la Fripouille"); 
      new Characteristic::Model("Relais 15A-125VAC"); 
      new Characteristic::FirmwareRevision("1.0"); 
      new Characteristic::Identify();            
      
    new Service::HAPProtocolInformation();      
      new Characteristic::Version("1.1.0");     

    new DEV_LED(2); //Pin de la commande du relais entre parenthèse

} // end of setup()


void loop(){
  
  homeSpan.poll();
  
} // end of loop()

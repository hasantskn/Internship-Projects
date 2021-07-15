#include <HX711_ADC.h>
#if defined(ESP8266)|| defined(ESP32) || defined(AVR)
#include <EEPROM.h>
#endif

//pins:
const int HX711_dout = 3; //mcu > HX711 dout pin
const int HX711_sck = 2; //mcu > HX711 sck pin

const int HX711_dout_2 = 5;
const int HX711_sck_2 =4;

const int HX711_dout_3 = 7;
const int HX711_sck_3 =6;

const int HX711_dout_4 = 9;  /////  Bu pinlere bakılacak!!
const int HX711_sck_4 =8;    /////

//HX711 constructor:
HX711_ADC LoadCell(HX711_dout, HX711_sck);
HX711_ADC LoadCell_2(HX711_dout_2, HX711_sck_2);
HX711_ADC LoadCell_3(HX711_dout_3, HX711_sck_3);
HX711_ADC LoadCell_4(HX711_dout_4, HX711_sck_4);

const int calVal_eepromAdress = 0;


unsigned long t = 0;
int cycleCount = 0;

int delay_cycle_weight = 100;
uint8_t readCycle = 5;
int sum = 0;

void setup() {
  Serial.begin(57600); delay(10);

  LoadCell.begin();
  LoadCell_2.begin();
  LoadCell_3.begin();
  LoadCell_4.begin();
  
  restartWeight();
HX711_ADC deger_listesi = {LoadCell};

}

void restartWeight(){

float calibrationValue; // calibration value (see example file "Calibration.ino")
  calibrationValue = 696.0; // uncomment this if you want to set the calibration value in the sketch
#if defined(ESP8266)|| defined(ESP32)
  //EEPROM.begin(512); // uncomment this if you use ESP8266/ESP32 and want to fetch the calibration value from eeprom
#endif
  EEPROM.get(calVal_eepromAdress, calibrationValue); // uncomment this if you want to fetch the calibration value from eeprom

  float calib_val= EEPROM.get(calVal_eepromAdress, calibrationValue);
  unsigned long stabilizingtime =10; // preciscion right after power-up can be improved by adding a few seconds of stabilizing time
  boolean _tare = true; //set this to false if you don't want tare to be performed in the next step
  LoadCell.start(stabilizingtime, _tare);
  LoadCell_2.start(stabilizingtime, _tare);
  LoadCell_3.start(stabilizingtime, _tare);
  LoadCell_4.start(stabilizingtime, _tare);
  //Serial.print("calib_val = ");
  //Serial.println(calib_val);
  
  if (LoadCell.getTareTimeoutFlag()) {
    //Serial.println("Timeout, check MCU>HX711 wiring and pin designations");
    while (1);
  }
  else {
    LoadCell.setCalFactor(calibrationValue); // set calibration value (float)
    //Serial.println("Startup is complete  1");
  }
  if (LoadCell_2.getTareTimeoutFlag()) {
    Serial.println("Timeout, check MCU>HX711 wiring and pin designations");
    while (1);
  }
  else {
    LoadCell_2.setCalFactor(calibrationValue); // set calibration value (float)
    //Serial.println("Startup is complete  2");
  }
  if (LoadCell_3.getTareTimeoutFlag()) {
    Serial.println("Timeout, check MCU>HX711 wiring and pin designations");
    while (1);
  }
  else {
    LoadCell_3.setCalFactor(calibrationValue); // set calibration value (float)
    //Serial.println("Startup is complete  3");
  }  

  if (LoadCell_4.getTareTimeoutFlag()) {
    Serial.println("Timeout, check MCU>HX711 wiring and pin designations");
    while (1);
  }
  else {
    LoadCell_4.setCalFactor(calibrationValue); // set calibration value (float)
    //Serial.println("Startup is complete  4");
  }  
}

void loop() {

cycleCount++;
if(cycleCount>10){
  restartWeight();
cycleCount = 0 ;
Serial.println("***********************yeniden kalibre ediliyor...****************************");
}
getWeight1();
getWeight2();
getWeight3();
getWeight4();

}



void getWeight1(){
  //uint8_t readCycle = 8;
  for( int k=0 ; k < readCycle ; k++){
static boolean newDataReady = 0;
  const int serialPrintInterval = 0; //increase value to slow down serial print activity

  // check for new data/start next conversion:
  if (LoadCell.update()) newDataReady = true;

  // get smoothed value from the dataset:
  
  if (newDataReady) {
    if (millis() > t + serialPrintInterval) {
      float i = LoadCell.getData();
      if(k == readCycle-1){
      //Serial.print("Load_cell output val: ");
      //Serial.println(-i);
      sum += i;
      }
      
      newDataReady = 0;
      t = millis();
    }
  }
  
  // receive command from serial terminal, send 't' to initiate tare operation:
  if (Serial.available() > 0) {
    char inByte = Serial.read();
    if (inByte == 't') LoadCell.tareNoDelay();
  }

  // check if last tare operation is complete:
  if (LoadCell.getTareStatus() == true) {
    Serial.println("Tare complete");
  }
    delay(delay_cycle_weight);
  }  
}


void getWeight2(){
  //uint8_t readCycle = 8;
  for( int k=0 ; k < readCycle ; k++){
static boolean newDataReady = 0;
  const int serialPrintInterval = 0; //increase value to slow down serial print activity

  // check for new data/start next conversion:
  if (LoadCell_2.update()) newDataReady = true;

  // get smoothed value from the dataset:
  
  if (newDataReady) {
    if (millis() > t + serialPrintInterval) {
      float i = LoadCell_2.getData();
      if(k == readCycle-1){
      //Serial.print("Load_cell output val_22: ");
      //Serial.println(-i);
      sum += i;
      }
      
      newDataReady = 0;
      t = millis();
    }
  }
  
  // receive command from serial terminal, send 't' to initiate tare operation:
  if (Serial.available() > 0) {
    char inByte = Serial.read();
    if (inByte == 't') LoadCell_2.tareNoDelay();
  }

  // check if last tare operation is complete:
  if (LoadCell_2.getTareStatus() == true) {
    Serial.println("Tare complete");
  }
    delay(delay_cycle_weight);
  }  
}


void getWeight3(){
  //uint8_t readCycle = 8;
  for( int k=0 ; k < readCycle ; k++){
static boolean newDataReady = 0;
  const int serialPrintInterval = 0; //increase value to slow down serial print activity

  // check for new data/start next conversion:
  if (LoadCell_3.update()) newDataReady = true;

  // get smoothed value from the dataset:
  
  if (newDataReady) {
    if (millis() > t + serialPrintInterval) {
      float i = LoadCell_3.getData();
      if(k == readCycle-1){
      //Serial.print("Load_cell output val_33: ");
      //Serial.println(i);
      }
      
      newDataReady = 0;
      t = millis();
    }
  }
  
  // receive command from serial terminal, send 't' to initiate tare operation:
  if (Serial.available() > 0) {
    char inByte = Serial.read();
    if (inByte == 't') LoadCell_3.tareNoDelay();
  }

  // check if last tare operation is complete:
  if (LoadCell_3.getTareStatus() == true) {
    Serial.println("Tare complete");
  }
    delay(delay_cycle_weight);
  }  
}


void getWeight4(){
  //uint8_t readCycle = 8;
  for( int k=0 ; k < readCycle ; k++){
static boolean newDataReady = 0;
  const int serialPrintInterval = 0; //increase value to slow down serial print activity

  // check for new data/start next conversion:
  if (LoadCell_4.update()) newDataReady = true;

  // get smoothed value from the dataset:
  
  if (newDataReady) {
    if (millis() > t + serialPrintInterval) {
      float i = LoadCell_4.getData();
      if(k == readCycle-1){
      //Serial.print("Load_cell output val_44: ");
      sum += i;
      Serial.println(sum);
      sum = 0;
      }
      
      newDataReady = 0;
      t = millis();
    }
  }
  
  // receive command from serial terminal, send 't' to initiate tare operation:
  if (Serial.available() > 0) {
    char inByte = Serial.read();
    if (inByte == 't') LoadCell_4.tareNoDelay();
  }

  // check if last tare operation is complete:
  if (LoadCell_4.getTareStatus() == true) {
    Serial.println("Tare complete");
  }
    delay(delay_cycle_weight);
  }  
}

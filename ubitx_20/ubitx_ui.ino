

/**
 * The user interface of the ubitx consists of the encoder, the push-button on top of it
 * and the 16x2 LCD display.
 * The upper line of the display is constantly used to display frequency and status
 * of the radio. Occasionally, it is used to provide a two-line information that is 
 * quickly cleared up.
 */


/*
const PROGMEM uint8_t meters_bitmap[] = {
  B10000,  B10000,  B10000,  B10000,  B10000,  B10000,  B10000,  B10000 ,   //custom 1
  B11000,  B11000,  B11000,  B11000,  B11000,  B11000,  B11000,  B11000 ,   //custom 2
  B11100,  B11100,  B11100,  B11100,  B11100,  B11100,  B11100,  B11100 ,   //custom 3
  B11110,  B11110,  B11110,  B11110,  B11110,  B11110,  B11110,  B11110 ,   //custom 4
  B11111,  B11111,  B11111,  B11111,  B11111,  B11111,  B11111,  B11111 ,   //custom 5
  B01000,  B11100,  B01000,  B00000,  B10111,  B10101,  B10101,  B10111     //custom 6
};
*/

//SWR GRAPH,  DrawMeter and drawingMeter Logic function by VK2ETA 

#ifdef OPTION_SKINNYBARS //We want skninny bars with more text
//VK2ETA modded "Skinny" bitmaps
const PROGMEM uint8_t meters_bitmap[] = {
  //  B01110, B10001, B10001, B11111, B11011, B11011, B11111, B00000, //Padlock Symbol, for merging. Not working, see below
  0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b10000, //shortest bar
  0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00100, 0b10100,
  0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00001, 0b00101, 0b10101,
  0b00000, 0b00000, 0b00000, 0b00000, 0b10000, 0b10000, 0b10000, 0b10000,
  0b00000, 0b00000, 0b00000, 0b00100, 0b10100, 0b10100, 0b10100, 0b10100,
  0b00000, 0b00000, 0b00001, 0b00101, 0b10101, 0b10101, 0b10101, 0b10101, //tallest bar
  0b00000, 0b00010, 0b00111, 0b00010, 0b01000, 0b11100, 0b01000, 0b00000, // ++ sign
};
#else
//VK2ETA "Fat" bars, easy to read, with less text
const PROGMEM uint8_t meters_bitmap[] = {
  //  B01110, B10001, B10001, B11111, B11011, B11011, B11111, B00000, //Padlock Symbol, for merging. Not working, see below
  0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b11111, //shortest bar
  0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b11111, 0b11111,
  0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b11111, 0b11111, 0b11111,
  0b00000, 0b00000, 0b00000, 0b00000, 0b11111, 0b11111, 0b11111, 0b11111,
  0b00000, 0b00000, 0b00000, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111,
  0b00000, 0b00000, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, //tallest bar
  0b00000, 0b00010, 0b00111, 0b00010, 0b01000, 0b11100, 0b01000, 0b00000, // ++ sign
};
#endif //OPTION_SKINNYBARS
PGM_P p_metes_bitmap = reinterpret_cast<PGM_P>(meters_bitmap);

const PROGMEM uint8_t lock_bitmap[8] = {
  0b01110,
  0b10001,
  0b10001,
  0b11111,
  0b11011,
  0b11011,
  0b11111,
  0b00000};
PGM_P plock_bitmap = reinterpret_cast<PGM_P>(lock_bitmap);


// initializes the custom characters
// we start from char 1 as char 0 terminates the string!
void initMeter(){
  uint8_t tmpbytes[8];
  byte i;

  for (i = 0; i < 8; i++)
    tmpbytes[i] = pgm_read_byte(plock_bitmap + i);
  LCD_CreateChar(0, tmpbytes);
  
  for (i = 0; i < 8; i++)
    tmpbytes[i] = pgm_read_byte(p_metes_bitmap + i);
  LCD_CreateChar(1, tmpbytes);

  for (i = 0; i < 8; i++)
    tmpbytes[i] = pgm_read_byte(p_metes_bitmap + i + 8);
  LCD_CreateChar(2, tmpbytes);
  
  for (i = 0; i < 8; i++)
    tmpbytes[i] = pgm_read_byte(p_metes_bitmap + i + 16);
  LCD_CreateChar(3, tmpbytes);
  
  for (i = 0; i < 8; i++)
    tmpbytes[i] = pgm_read_byte(p_metes_bitmap + i + 24);
  LCD_CreateChar(4, tmpbytes);
  
  for (i = 0; i < 8; i++)
    tmpbytes[i] = pgm_read_byte(p_metes_bitmap + i + 32);
  LCD_CreateChar(5, tmpbytes);
  
  for (i = 0; i < 8; i++)
    tmpbytes[i] = pgm_read_byte(p_metes_bitmap + i + 40);
  LCD_CreateChar(6, tmpbytes);

  for (i = 0; i < 8; i++)
    tmpbytes[i] = pgm_read_byte(p_metes_bitmap + i + 48);
  LCD_CreateChar(7, tmpbytes);
}


//by KD8CEC
//0 ~ 25 : 30 over : + 10
/*
void drawMeter(int needle) {
  //5Char + O over
  int i;

  for (i = 0; i < 5; i++) {
    if (needle >= 5)
      lcdMeter[i] = 5; //full
    else if (needle > 0)
      lcdMeter[i] = needle; //full
    else  //0
      lcdMeter[i] = 0x20;
    
    needle -= 5;
  }

  if (needle > 0)
    lcdMeter[5] = 6;
  else
    lcdMeter[5] = 0x20;
}
*/
//VK2ETA meter for S.Meter, power and SWR
void drawMeter(int needle) 
{
#ifdef OPTION_SKINNYBARS
  //Fill buffer with growing set of bars, up to needle value
  lcdMeter[0] = 0x20;
  lcdMeter[1] = 0x20;
  for (int i = 0; i < 6; i++) {
    if (needle > i)
      lcdMeter[i / 3] = byte(i + 1); //Custom characters above
    //else if (i == 1 || i == 4) {
    //  lcdMeter[i / 3] = 0x20; //blank
    //}
  }

  if (needle > 7) {
    lcdMeter[2] = byte(7); //Custom character "++"
  } else if (needle > 6) {
    lcdMeter[2] = '+'; //"+"
  } else lcdMeter[2] = 0x20;
  
  
#else //Must be "fat" bars
  //Fill buffer with growing set of bars, up to needle value
  for (int i = 0; i < 6; i++) {
    if (needle > i)
      lcdMeter[i] = byte(i + 1); //Custom characters above
    else
      lcdMeter[i] = 0x20; //blank
  }

  if (needle > 7) {
    lcdMeter[6] = byte(7); //Custom character "++"
  } else if (needle > 6) {
    lcdMeter[6] = '+'; //"+"
  } else lcdMeter[6] = 0x20;
  
#endif //OPTION_FATBARS
}



 char byteToChar(byte srcByte){
  if (srcByte < 10)
    return 0x30 + srcByte;
 else
    return 'A' + srcByte - 10;
}

//returns true if the button is pressed
int btnDown(void){
#ifdef EXTEND_KEY_GROUP1
  #ifndef USE_DIGITAL_ENCODER
    if (analogRead(FBUTTON) > FUNCTION_KEY_ADC) {
      pinMode(FBUTTON,INPUT_PULLUP);                //mjh pullups are disabled with analogRead on IOT and RP connect, need to reset here
      return 0;
    }
    else
      return 1;
  #endif
#endif

if (digitalRead(FBUTTON) == HIGH)                //mjh executed if not extended group or when using digital encoder
  return 0;
else
//  Serial.println("button down detected") ;  //mjh 
  return 1;
}

#ifdef EXTEND_KEY_GROUP1     //mjh have to change this for digital use of function button. maybe this goes away?
int getBtnStatus(void){
  #ifndef USE_DIGITAL_ENCODER         //Analog function key is not possible with digital encoder lines and switch
    int readButtonValue = analogRead(FBUTTON);
    pinMode(FBUTTON,INPUT_PULLUP);                //mjh pullups are disabled with analogRead on IOT and RP connect, need to reset here

    if (analogRead(FBUTTON) < FUNCTION_KEY_ADC) {
      pinMode(FBUTTON,INPUT_PULLUP);            //mjh pullups are disabled with analogRead on IOT and RP connect, need to reset here
      return FKEY_PRESS;
    }
    else
    {
      readButtonValue = readButtonValue / 4;
      //return FKEY_VFOCHANGE;
      for (int i = 0; i < 16; i++)
        if (KeyValues[i][2] != 0 && KeyValues[i][0] <= readButtonValue && KeyValues[i][1] >= readButtonValue)
          return KeyValues[i][2];
          //return i;
    }
    return -1;
  #else       //We have a digital encoder and just need to read the state of the button
    if (digitalRead(FBUTTON) == HIGH)                 //mjh executed with digital pins on encoder and FBUTTON
      return -1;                                        
    else  
      return FKEY_PRESS;                              //mjh Button still pressed. Announce it.
  #endif  
  
}
 
#endif  //EXTEND_GROUP_1

#ifndef USE_DIGITAL_ENCODER    //MJH This is the original rotary code
byte enc_prev_state = 3;

/**
 * The A7 And A6 are purely analog lines on the Arduino Nano
 * These need to be pulled up externally using two 10 K resistors
 * 
 * There are excellent pages on the Internet about how these encoders work
 * and how they should be used. We have elected to use the simplest way
 * to use these encoders without the complexity of interrupts etc to 
 * keep it understandable.
 * 
 * The enc_state returns a two-bit number such that each bit reflects the current
 * value of each of the two phases of the encoder
 * 
 * The enc_read returns the number of net pulses counted over 50 msecs. 
 * If the puluses are -ve, they were anti-clockwise, if they are +ve, the
 * were in the clockwise directions. Higher the pulses, greater the speed
 * at which the enccoder was spun
 */
byte enc_state (void) {
  int encoderA, encoderB;
  encoderA=analogRead(ENC_A);
  encoderB=analogRead(ENC_B);

  // reset pullups because some MCU's turn them off after analogRead
  pinMode(ENC_A,INPUT_PULLUP);
  pinMode(ENC_B,INPUT_PULLUP);

  #ifdef DEBUGENCODER
    Serial.print("ENC_A="); Serial.print(encoderA); Serial.print(" ENC_B="); Serial.println(encoderB);
  #endif
  
#if defined(NANO)  || defined(NANOEVERY)  || defined(NANOBLE)
    return (encoderA > 500 ? 1 : 0) + (encoderB > 500 ? 2: 0);
#else
    return (encoderA > 200 ? 1 : 0) + (encoderB > 200 ? 2: 0);
#endif
}

int enc_read(void) {
  int result = 0; 
  byte newState;
  int enc_speed = 0;

  
  unsigned long start_at = millis();
  

 while (millis() - start_at < 50) { // check if the previous state was stable
    newState = enc_state(); // Get current state  
    
    if (newState != enc_prev_state)
      delay (1);
    
    if (enc_state() != newState || newState == enc_prev_state)
      continue; 
    //these transitions point to the encoder being rotated anti-clockwise
    if ((enc_prev_state == 0 && newState == 2) || 
      (enc_prev_state == 2 && newState == 3) || 
      (enc_prev_state == 3 && newState == 1) || 
      (enc_prev_state == 1 && newState == 0)){
        result--;
      }
    //these transitions point o the enccoder being rotated clockwise
    if ((enc_prev_state == 0 && newState == 1) || 
      (enc_prev_state == 1 && newState == 3) || 
      (enc_prev_state == 3 && newState == 2) || 
      (enc_prev_state == 2 && newState == 0)){
        result++;
      }
    enc_prev_state = newState; // Record state for next pulse interpretation
    enc_speed++;
    delay(1);
  }
  return(result);
}

#else       // MJH new rotary code for rotary encoder on Digital Lines
//  MJH  Added Rotary Encoder for Raspberry Pi Pico

#include <RotaryEncoder.h>          //https://github.com/mathertel/RotaryEncoder
extern RotaryEncoder encoder;


static int enc_prev_state = 0;

int enc_read(void) {
  int newState;
  int enc_speed = 0;
  int startPos;
  
  unsigned long start_at = millis();
  
  startPos = enc_prev_state;
  newState = encoder.getPosition(); // Get current positi0n  //mjh added here to eliminate warning of newState could be unitialzized

  while (millis() - start_at < 50) { // check if the previous state was stable
    encoder.tick();                 // check encoder state
    newState = encoder.getPosition(); // Get current positin
    
    if (newState != enc_prev_state)
      delay (1);
    
    enc_prev_state = newState; // Record state for next pulse interpretation
    enc_speed++;
    delay(1); 
  }
  return(newState - startPos);
}
#endif

//===================================================================
//I2C Signal Meter, Version 1.097
//===================================================================

// 0xA0 ~ 0xCF : CW Decode Mode + 100Hz ~
// 0xD0 ~ 0xF3 : RTTY Decode Mode + 100Hz ~
// 0x10 ~ 0x30 : Spectrum Mode
int GetI2CSmeterValue(int valueType)
{
  if (valueType > 0)
  {
    Wire.beginTransmission(I2CMETER_ADDR);  //j : S-Meter
    Wire.write(valueType);                  //Y : Get Value Type
    Wire.endTransmission();
  }
  
  Wire.requestFrom(I2CMETER_ADDR, 1);

  if (Wire.available() > 0)
  {
    return Wire.read();
  }
  else
  {
    return 0;
  }
}

// Ported to ILI9341_due by GHLawrence2000
//
// https://github.com/ghlawrence2000/ILI9341_due_Buttons
//
// http://forum.arduino.cc/index.php?action=profile;u=164638
//
// UTFT_Buttons_Demo_320x240
// Copyright (C)2015 Rinky-Dink Electronics, Henning Karlsen. All right reserved
// web: http://www.RinkyDinkElectronics.com/
//
// A small demo to demonstrate the use of some of the
// functions of the UTFT_Buttons add-on library.
//
// This demo was made for modules with a screen resolution
// of 320x240 pixels, but should work on larger screens as
// well.
//
// This program requires both the ILI9341_due and UTouch libraries
// in addition to the ILI9341_due_Buttons add-on library.
//
#include <SPI.h>
#include <ILI9341_due_config.h>
#include <ILI9341_due.h>
#include "SmallFont.h"
#include "BigFont.h"
#include "Dingbats1_XL.h"

#include <UTouch.h>
#include <ILI9341_due_Buttons.h>

// For the Adafruit shield, these are the default.
#define TFT_RST 8
#define TFT_DC 9
#define TFT_CS 10

// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
ILI9341_due tft = ILI9341_due(TFT_CS, TFT_DC, TFT_RST);

// Set up UTouch...
// Set the pins to the correct ones for your development board
// -----------------------------------------------------------
// Standard Arduino 2009/Uno/Leonardo shield   : 15,10,14,9,8
// Standard Arduino Mega/Due shield            : 6,5,4,3,2
// CTE TFT LCD/SD Shield for Arduino Due       : 6,5,4,3,2
// Standard chipKit Uno32/uC32                 : 20,21,22,23,24
// Standard chipKit Max32                      : 62,63,64,65,66
// AquaLEDSource All in One Super Screw Shield : 62,63,64,65,66
// CC3200 LaunchPad (pins used in the examples): 31,13,19,28,17
//
UTouch        myTouch(6, 5, 4, 3, 2);

// Finally we set up ILI9341_due_Buttons :)
ILI9341_due_Buttons  myButtons(&tft, &myTouch);

void setup()
{
  Serial.begin(115200);
  // Initial setup
  tft.begin();
  tft.setRotation(iliRotation270);  // landscape
  tft.fillScreen(ILI9341_BLACK);

  tft.setFont(SmallFont);

  myTouch.InitTouch();
  myTouch.setPrecision(PREC_MEDIUM);

  myButtons.setTextFont(BigFont);
  myButtons.setSymbolFont(Dingbats1_XL);
}

void loop()
{
  int but1, but2, but3, but4, butX, butY, pressed_button;
  boolean default_colors = true;

  but1 = myButtons.addButton( 10,  20, 300,  30, "Button 1");
  but2 = myButtons.addButton( 10,  60, 300,  30, "Button 2");
  but3 = myButtons.addButton( 10, 100, 300,  30, "Button 3");
  but4 = myButtons.addButton( 10, 140, 300,  30, "Button 4", BUTTON_DISABLED);
  butX = myButtons.addButton(279, 199,  40,  40, "a", BUTTON_SYMBOL);
  butY = myButtons.addButton(  0, 199, 100,  40, "I", BUTTON_SYMBOL | BUTTON_SYMBOL_REP_3X);
  myButtons.drawButtons();

  tft.printAt("You pressed:", 110, 205);
  tft.setTextColor(ILI9341_BLACK, ILI9341_WHITE);
  tft.printAt("None    ", 110, 220);

  while (1)
  {
    if (myTouch.dataAvailable() == true)
    {
      pressed_button = myButtons.checkButtons();

      if (pressed_button == butX)
      {
        if (myButtons.buttonEnabled(but4))
          myButtons.disableButton(but4, true);
        else
          myButtons.enableButton(but4, true);
      }
      else if (pressed_button == butY)
      {
        if (default_colors)
        {
          myButtons.setButtonColors(ILI9341_YELLOW, ILI9341_RED, ILI9341_YELLOW, ILI9341_BLUE, ILI9341_GRAY);
          myButtons.relabelButton(butY, "_");
          myButtons.drawButtons();
          default_colors = false;
        }
        else
        {
          myButtons.setButtonColors(ILI9341_WHITE, ILI9341_GRAY, ILI9341_WHITE, ILI9341_RED, ILI9341_BLUE);
          myButtons.relabelButton(butY, "I");
          myButtons.drawButtons();
          default_colors = true;
        }
      }
      if (pressed_button == but1)
      {
        tft.printAt("Button 1", 110, 220);
        //Serial.println("Button 1");
      }

      if (pressed_button == but2)
      {
        tft.printAt("Button 2", 110, 220);
        //Serial.println("Button 2");
      }
      if (pressed_button == but3)
      {
        tft.printAt("Button 3", 110, 220);
        //Serial.println("Button 3");
      }
      if (pressed_button == but4)
      {
        tft.printAt("Button 4", 110, 220);
        //Serial.println("Button 4");
      }
      if (pressed_button == -1)
      {
        tft.printAt("None    ", 110, 220);
      }
    }
  }
}


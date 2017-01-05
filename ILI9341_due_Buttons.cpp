// Ported to ILI9341_due by GHLawrence2000 (perfected by David Prentice)
//
// https://github.com/ghlawrence2000/ILI9341_due_Buttons
//
// http://forum.arduino.cc/index.php?action=profile;u=164638
//
/*
  ILI9341_due_Buttons.cpp - Add-on Library for UTFT: Buttons
  Copyright (C)2015 Rinky-Dink Electronics, Henning Karlsen. All right reserved

  This library adds simple but easy to use buttons to extend the use
  of the UTFT and URTouch libraries.

  You can find the latest version of the library at
  http://www.RinkyDinkElectronics.com/

  This library is free software; you can redistribute it and/or
  modify it under the terms of the CC BY-NC-SA 3.0 license.
  Please see the included documents for further information.

  Commercial use of this library requires you to buy a license that
  will allow commercial use. This includes using the library,
  modified or not, as a tool to sell products.

  The license applies to all part of the library including the
  examples and tools supplied with the library.
*/

#include "ILI9341_due_Buttons.h"    //.kbv defines URTouch_SPI
#include <ILI9341_due.h>
#include <URTouch.h>

ILI9341_due_Buttons::ILI9341_due_Buttons(ILI9341_due *ptrILI9341, URTouch *ptrURTouch)
{
  _ILI9341 = ptrILI9341;
  _URTouch = ptrURTouch;
  deleteAllButtons();
  _color_text       = ILI9341_WHITE;
  _color_text_inactive  = ILI9341_GRAY;
  _color_background   = ILI9341_BLUE;
  _color_border     = ILI9341_WHITE;
  _color_hilite     = ILI9341_RED;
  _font_text        = NULL;
  _font_symbol      = NULL;
}

int ILI9341_due_Buttons::addButton(uint16_t x, uint16_t y, uint16_t width, uint16_t height, char *label, uint16_t flags)
{
  int btcnt = 0;

  while (((buttons[btcnt].flags & BUTTON_UNUSED) == 0) and (btcnt < MAX_BUTTONS))
    btcnt++;

  if (btcnt == MAX_BUTTONS)
    return -1;
  else
  {
    buttons[btcnt].pos_x  = x;
    buttons[btcnt].pos_y  = y;
    buttons[btcnt].width  = width;
    buttons[btcnt].height = height;
    buttons[btcnt].flags  = flags;
    buttons[btcnt].label  = label;
    buttons[btcnt].data   = NULL;
    return btcnt;
  }
}

int ILI9341_due_Buttons::addButton(uint16_t x, uint16_t y, uint16_t width, uint16_t height, bitmapdatatype data, uint16_t flags)
{
  int btcnt = 0;

  while (((buttons[btcnt].flags & BUTTON_UNUSED) == 0) and (btcnt < MAX_BUTTONS))
    btcnt++;

  if (btcnt == MAX_BUTTONS)
    return -1;
  else
  {
    buttons[btcnt].pos_x  = x;
    buttons[btcnt].pos_y  = y;
    buttons[btcnt].width  = width;
    buttons[btcnt].height = height;
    buttons[btcnt].flags  = flags | BUTTON_BITMAP;
    buttons[btcnt].label  = NULL;
    buttons[btcnt].data   = data;
    return btcnt;
  }
}


void ILI9341_due_Buttons::drawButtons()
{
  for (int i = 0; i < MAX_BUTTONS; i++)
  {
    if ((buttons[i].flags & BUTTON_UNUSED) == 0)
      drawButton(i);
  }
}

void ILI9341_due_Buttons::drawButton(int buttonID)  //.kbv use wid, ht for Rect
{
  int   text_x, text_y;
  const unsigned char *_font_current = _ILI9341->getFont();
  word  _current_color = _ILI9341->getTextColor();
  word  _current_back  = _ILI9341->getTextBackgroundColor();

  if (buttons[buttonID].flags & BUTTON_BITMAP)
  {
    _ILI9341->drawImage(buttons[buttonID].data, buttons[buttonID].pos_x, buttons[buttonID].pos_y, buttons[buttonID].width, buttons[buttonID].height);
    if (!(buttons[buttonID].flags & BUTTON_NO_BORDER))
    {
      if ((buttons[buttonID].flags & BUTTON_DISABLED))
        _ILI9341->drawRect(buttons[buttonID].pos_x, buttons[buttonID].pos_y, buttons[buttonID].width, buttons[buttonID].height, _color_text_inactive);
      else
        _ILI9341->drawRect(buttons[buttonID].pos_x, buttons[buttonID].pos_y, buttons[buttonID].width, buttons[buttonID].height, _color_border);
    }
  }
  else
  {
    //_UTFT->setColor(_color_background);
    _ILI9341->fillRoundRect(buttons[buttonID].pos_x, buttons[buttonID].pos_y, buttons[buttonID].width, buttons[buttonID].height, 5, _color_background);
    //_UTFT->setColor(_color_border);
    _ILI9341->drawRoundRect(buttons[buttonID].pos_x, buttons[buttonID].pos_y, buttons[buttonID].width, buttons[buttonID].height, 5, _color_border);
    if (buttons[buttonID].flags & BUTTON_DISABLED)
      _ILI9341->setTextColor(_color_text_inactive, _color_background);
    else
      _ILI9341->setTextColor(_color_text, _color_background);
    if (buttons[buttonID].flags & BUTTON_SYMBOL)
    {
      _ILI9341->setFont(_font_symbol);
      text_x = (buttons[buttonID].width / 2) - (_ILI9341->getStringWidth(buttons[buttonID].label) / 2) + buttons[buttonID].pos_x;
      text_y = (buttons[buttonID].height / 2) - (_ILI9341->getFontHeight() / 2) + buttons[buttonID].pos_y;
    }
    else
    {
      _ILI9341->setFont(_font_text);
      text_x = (buttons[buttonID].width / 2) - (_ILI9341->getStringWidth(buttons[buttonID].label) / 2) + buttons[buttonID].pos_x; //.kbv
      text_y = (buttons[buttonID].height / 2) - (_ILI9341->getFontHeight() / 2) + buttons[buttonID].pos_y;
    }
    //_UTFT->setBackColor(_color_background);
    _ILI9341->printAt(buttons[buttonID].label, text_x, text_y);
    if ((buttons[buttonID].flags & BUTTON_SYMBOL) and (buttons[buttonID].flags & BUTTON_SYMBOL_REP_3X))
    {
      _ILI9341->printAt(buttons[buttonID].label, text_x - _ILI9341->getStringWidth(buttons[buttonID].label), text_y);
      _ILI9341->printAt(buttons[buttonID].label, text_x + _ILI9341->getStringWidth(buttons[buttonID].label), text_y);
    }
  }
  _ILI9341->setFont(_font_current);       //???????????????
  _ILI9341->setTextColor(_current_color, _current_back);     //???????????????
  //_ILI9341->setBackColor(_current_back);  //???????????????
}

void ILI9341_due_Buttons::enableButton(int buttonID, boolean redraw)
{
  if (!(buttons[buttonID].flags & BUTTON_UNUSED))
  {
    buttons[buttonID].flags = buttons[buttonID].flags & ~BUTTON_DISABLED;
    if (redraw)
      drawButton(buttonID);
  }
}

void ILI9341_due_Buttons::disableButton(int buttonID, boolean redraw)
{
  if (!(buttons[buttonID].flags & BUTTON_UNUSED))
  {
    buttons[buttonID].flags = buttons[buttonID].flags | BUTTON_DISABLED;
    if (redraw)
      drawButton(buttonID);
  }
}

void ILI9341_due_Buttons::relabelButton(int buttonID, char *label, boolean redraw)
{
  if (!(buttons[buttonID].flags & BUTTON_UNUSED))
  {
    buttons[buttonID].label = label;
    if (redraw)
      drawButton(buttonID);
  }
}

boolean ILI9341_due_Buttons::buttonEnabled(int buttonID)
{
  return !(buttons[buttonID].flags & BUTTON_DISABLED);
}

void ILI9341_due_Buttons::deleteButton(int buttonID)
{
  if (!(buttons[buttonID].flags & BUTTON_UNUSED))
    buttons[buttonID].flags = BUTTON_UNUSED;
}

void ILI9341_due_Buttons::deleteAllButtons()
{
  for (int i = 0; i < MAX_BUTTONS; i++)
  {
    buttons[i].pos_x = 0;
    buttons[i].pos_y = 0;
    buttons[i].width = 0;
    buttons[i].height = 0;
    buttons[i].flags = BUTTON_UNUSED;
    buttons[i].label = "";
  }
}

int ILI9341_due_Buttons::checkButtons()
{
  if (_URTouch->dataAvailable() == true)
  {
    _URTouch->read();
    int   result = -1;
    int   touch_x = _URTouch->getX();
    int   touch_y = _URTouch->getY();
    //word  _current_color = _UTFT->getColor(); ???????????????????????

    for (int i = 0; i < MAX_BUTTONS; i++)
    {
      if (((buttons[i].flags & BUTTON_UNUSED) == 0) and ((buttons[i].flags & BUTTON_DISABLED) == 0) and (result == -1))
      {
        if ((touch_x >= buttons[i].pos_x) and (touch_x <= (buttons[i].pos_x + buttons[i].width)) and (touch_y >= buttons[i].pos_y) and (touch_y <= (buttons[i].pos_y + buttons[i].height)))
          result = i;
      }
    }
    if (result != -1)
    {
      if (!(buttons[result].flags & BUTTON_NO_BORDER))
      {
        //_UTFT->setColor(_color_hilite);
        if (buttons[result].flags & BUTTON_BITMAP)
          _ILI9341->drawRect(buttons[result].pos_x, buttons[result].pos_y, buttons[result].width, buttons[result].height, _color_hilite);
        else
          _ILI9341->drawRoundRect(buttons[result].pos_x, buttons[result].pos_y, buttons[result].width, buttons[result].height, 5, _color_hilite);
      }
    }

    while (_URTouch->dataAvailable() == true) {};

    if (result != -1)
    {
      if (!(buttons[result].flags & BUTTON_NO_BORDER))
      {
        //_UTFT->setColor(_color_border);
        if (buttons[result].flags & BUTTON_BITMAP)
          _ILI9341->drawRect(buttons[result].pos_x, buttons[result].pos_y, buttons[result].width, buttons[result].height, _color_border);
        else
          _ILI9341->drawRoundRect(buttons[result].pos_x, buttons[result].pos_y, buttons[result].width, buttons[result].height, 5, _color_border);
      }
    }

    //_UTFT->setColor(_current_color); ???????????
    return result;
  }
  else
    return -1;
}

void ILI9341_due_Buttons::setTextFont(gTextFont font)
{
  _font_text = font;
}

void ILI9341_due_Buttons::setSymbolFont(gTextFont font)
{
  _font_symbol = font;
}

void ILI9341_due_Buttons::setButtonColors(word atxt, word iatxt, word brd, word brdhi, word back)
{
  _color_text       = atxt;
  _color_text_inactive  = iatxt;
  _color_background   = back;
  _color_border     = brd;
  _color_hilite     = brdhi;
}

# ILI9341_due_Buttons

A request was made via the forums to have an easy to use 'buttons' API that would work with Marek Buriak's wonderful ILI9341_due library :- https://github.com/marekburiak/ILI9341_due

Since UTFT and UTouch were 'emulated'/supported, it was a relatively simple task to convert UTFT_Buttons.

Based on UTFT_Buttons (V1.02) by Henning Karlsen http://www.rinkydinkelectronics.com/library.php?id=61.

Converted by GHLawrence2000 with assistance and debugging kindly supplied by David_Prentice & TFTLCDCyg. BIG Thanks to you both!

This is the first commit to Git, but is already something like V1.02.04 since some early errors have already been corrected. However, this is not yet a completely 'true and accurate' translation of UTFT_Buttons. There are some setting of colors which have not yet been dealt with.
What this means, is that it is possible to be writing to screen using a particular color, call some button functions, but on exit from those button functions, the color you are now using on screen is different to before the button functions... I aim to rectify this in future efforts.

ArthurD has much to answer for, since I had to buy a display I neither knew I wanted or needed to do this for him.... You are welcome! I think?

Speaking of display, had time not have been an issue I would have ordered from Aliexpress :- http://www.aliexpress.com/item/A96-Free-Shipping-2-4-240x320-SPI-TFT-LCD-Touch-Panel-Serial-Port-Module-with-PBC/32447469595.html?spm=2114.031010208.3.114.XdaaZq&ws_ab_test=searchweb201556_6,searchweb201527_1_71_72_73_74_75,searchweb201560_3

Since time DID appear to be an issue, I ordered from everyone's 'friend' :- http://www.ebay.co.uk/itm/301713255980?_trksid=p2060353.m2749.l2649&ssPageName=STRK%3AMEBIDX%3AIT

All that remains for me to say, is there is an issue I am aware of. This is outside my control until/if Marek is prepared to make changes to ILI9341_due.h?
Please be aware the included ILI9341_due.h is a copy dated 29th September 2015. The changes involve removing three variable from Protected: and making then Public:

Lines 457-459 :-

	uint16_t _fontColor;
	uint16_t _fontBgColor;
	gTextFont _font;

Need inserting at around line 754.

The .h file in folder ILI9341_due_mod should be posted directly over the same file name in the Arduino\Libraries\ILI9341_due(-master) folder. 



/*
   file:		prg355_lab1.ino
   author:		Rafael Santos
   student #:	127 414 241
   email-id:	rsantos47@myseneca.ca
   date:		01/21/2026
   purpose:		Solution created in class to PRG355 lab #1 using C++ structs, and ESP32-S3 and an LCD1602.
				It runs in WOKWI.

*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <cstring>

#define ROWS 2
#define COLS 16

// C++ struct encapsulating the LCD1602
struct LCD1602 {
	LiquidCrystal_I2C *lcd;  // pointer to LiquidCrystal_I2C object

	// member functions
	void init_LCD(LiquidCrystal_I2C *ptr_lcd); // initialize LCD & buffer
	void backlight(bool state);
	void set_cursor(int row, int col);
	void print_char(char letter);
	void print_string(const char *s, int col, int row);
	void refresh(void);

	// lab functions

	void decrypt(char *s, int salt[ ]);
	// This function increases (adds to) the value of every character (except the null byte)
	// in the string 's' by the amount stored in the integer at the corresponding position
	// in the 'salt' array. You may assume that the string's length matches the integer array's length.
	// For example if s = "abcde" and salt = {1,1,1,1,1}, then s becomes "bcdef".

	void print_reverse(const char *s, int col, int row);
	// This function accepts the constant string 's' and displays it on the
	// LCD screen in reverse starting at coordinates (col, row).
	// NOTE: You will need to use functions already supplied to display
	//       a character or a string on the LCD screen.

};

/*
This function accepts a pointer to an LCD1602 object and initializes it
by calling its own internal init() and backlight() functions.
In addition, this function sets the struct's row and column members
to default values of (0,0) and then proceeds to assign space (' ')
characters to every element of the 2D buffer[2][16] array.
Finally, the function calls the internal member function refresh()
which writes spaces to every position on the LCD1602 object.
*/
void LCD1602::init_LCD(LiquidCrystal_I2C *ptr_lcd) {
	lcd = ptr_lcd;      // assign pointer to actual LCD object
	lcd->init( );
	lcd->backlight( );

	refresh( ); // initializes all blocks in the LCD1602 to spaces
}

// This function simply toggles the LCD1602 backlight to on or off.
void LCD1602::backlight(bool state) {
	if (state) lcd->backlight();
	else lcd->noBacklight();
}

/*
This function sets the LCD1602's cursor position to c and r respectivelut only after first validating that r is either a 0 or 1 and c is within the range
of 0 to 15 inclusive.
*/
void LCD1602::set_cursor(int row, int col) {
	if(row >= 0 && row < ROWS && col >= 0 && col < COLS) {
	lcd->setCursor(col, row); // NOTE: the LCD1602 internal function accepts columns first!
	}
}

/* This function accepts a charcter to output on the LCD at the current
   cursor position.
*/
void LCD1602::print_char(char letter) {
	lcd->write(letter);
}

// This function accepts a constant string and displays it on the LCD
// starting at coordinates col and row.
void LCD1602::print_string(const char *s, int col, int row) {
	int i;
	set_cursor(row, col);
	for(i=0; s[i] != '\0' && col + i < COLS; i++) {
	print_char(s[i]);
	}
}

// This function writes spaces to all LCD1602 blocks (0,0) to (1,15).
void LCD1602::refresh(void) {
	int i;
	for(i = 0; i < COLS; i++) {
	lcd->setCursor(i, 0); // row 1
	lcd->write(' ');
	lcd->setCursor(i, 1); // row 2
	lcd->write(' ');
	}
}

// ---- arduino setup ----
LiquidCrystal_I2C lcdObj(0x27, 16, 2); // LCD I2C object
LCD1602 myLCD;

// Alphabet: ABCDEFGHIJKLMNOPQRSTUVWXYZ

void setup() {
	char str[12] = "!fumJ pbbbN";
	int offsets[11] = { 0, -1, -2, 2, 2, 0, 3, 4, -1, 3, -2 };
	Wire.begin(8, 9);       // SDA=GPIO8, SCL=GPIO9 for ESP32-S3-DevKitC-1
	myLCD.init_LCD(&lcdObj); // send address of lcd object

	myLCD.print_string("Hello ESP32-S3!arfarafarafa", 0, 0);
	myLCD.print_string("LCD1602 Struct", 0, 1);

	delay(1000);

	myLCD.refresh();
	myLCD.decrypt(str, offsets);
	myLCD.print_reverse(str, 0, 0);
}

void loop() {
	delay(500);
}

void LCD1602::decrypt(char *s, int salt[ ])
{
  // This function increases (adds to) the value of every character (except the null byte)
  // in the string 's' by the amount stored in the integer at the corresponding position
  // in the 'salt' array. You may assume that the string's length matches the integer array's length.
  // For example if s = "abcde" and salt = {1,1,1,1,1}, then s becomes "bcdef".
  int count = 0;

  while(s[count] != '\0')
  {
	s[count] += salt[count];
	count++;
  }
  return;
}

void LCD1602::print_reverse(const char *s, int col, int row)
{
  // This function accepts the constant string 's' and displays it on the
  // LCD screen in reverse starting at coordinates (col, row).
  // NOTE: You will need to use functions already supplied to display
  //       a character or a string on the LCD screen.
  int count, strSize;
  char reverseString[33];

  strSize = strlen(s);

  for (count = 0; count < strSize; count++)
  {
	reverseString[count] = s[strSize - count - 1];
  }
  print_string(reverseString, col, row);
  return;
}

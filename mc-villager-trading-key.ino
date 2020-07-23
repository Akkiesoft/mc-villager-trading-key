// mc-villager-trading-key

#include <HID-Project.h>
#include <HID-Settings.h>
#include <MsTimer2.h>

// -----------------------------------
// define keys switch pin
// default: 4-pack( http://www.40percent.club/2017/07/4-pack.html )
const byte key[4] = { 4, 5, 6, 7 };

// define the amount of movement in x direction
const int x[4] = { 170, 720, 0, 0 };

// define the amount of movement in y direction
const int y[4] = { 20, 95, 0, 0 };
// -----------------------------------


// key status : push(key index + 1), release(0)
char s = 0;
// mouse cursor status: move(1), back(0)
boolean e = 0;

void setup() {
  Mouse.begin();
  Keyboard.begin();
  Consumer.begin();
  // init keys
  for (char i = 0; i < 4; i++) {
    pinMode(key[i], INPUT);
    digitalWrite(key[i], 1);
  }
  MsTimer2::set(200, getEmerald);
}

void moveMouse(int mx, int my, char dx, char dy) {
  // mx,my: the amount of movement
  // dx,dy: direction. -1 == minus(left or up), 1 == plus(right or down)

  // we need divide the value
  // if move value is larger then 127.
  // because Mouse.move value type is defined as char.
  int l;
  l = mx / 120;
  for (int i = 0; i < l; i++) {
    Mouse.move(120 * dx, 0, 0);
  }
  l = my / 120;
  for (int i = 0; i < l; i++) {
    Mouse.move(0, 120 * dy, 0);
  }
  Mouse.move((mx % 120) * dx, (my % 120) * dy, 0);
}

void getEmerald() {
  if (e == 0) {
    // select emerald from trade menu
    e = 1;
    moveMouse(x[s-1], y[s-1], -1, -1);
  } else {
    // get emerald
    e = 0;
    moveMouse(x[s-1], y[s-1], 1, 1);
  }
  Mouse.click();
}

void loop() {
  for (int i = 0; i < 4; i++) {
    // prevent keys from being pressed at the same time.
    if (s == 0 && digitalRead(key[i]) == 0) {
      // ensure defined the amount of movement for pressed key
      if (0 < x[i] + y[i]) {
        s = i + 1;
        MsTimer2::start();
      }
      break;
    }
  }
  if (s && digitalRead(key[s-1])) {
    MsTimer2::stop();
    // if the cursor is point the trade menu when release the key, do the get emerald.
    if (e) {
      getEmerald();
    }
    s = 0;
  }
}

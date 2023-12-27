# mc-villager-trading-key for CircuitPython

import board
import digitalio
from time import sleep
import usb_hid
from adafruit_hid.keyboard import Keyboard
from adafruit_hid.mouse import Mouse
from adafruit_hid.keycode import Keycode

# 取引アイテム受け取りの枠から、取引アイテム選択リストまでの移動について数値を入れる
# 右から左上に移動と想定されるので基本的にマイナス値
mx = -500
my = -50

keyboard = Keyboard(usb_hid.devices)
mouse = Mouse(usb_hid.devices)

button0 = digitalio.DigitalInOut(board.GP0)
button0.switch_to_input(pull=digitalio.Pull.UP)

led = digitalio.DigitalInOut(board.LED)

trading = 0

while True:
  if not button0.value:
    led.value = 1
    if not trading:
      # 取引開始。取引中はShift押しっぱなし
      trading = 1
      keyboard.press(Keycode.LEFT_SHIFT)
    # 取引アイテム受け取り枠<->取引アイテムリストを反復しながらクリック
    mouse.move(x = mx * trading, y = my * trading)
    mouse.click(Mouse.LEFT_BUTTON)
    trading = trading * -1
    sleep(0.15)
  else:
    led.value = 0
    keyboard.release_all()
    if trading < 0:
      # 取引アイテム受け取り枠に戻す
      mouse.move(x = mx * -1, y = my * -1)
    trading = 0
  sleep(0.02)
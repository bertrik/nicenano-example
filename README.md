# nicenano-example
Working platformio example project for the nicenano NRF52840 board

This is mostly based on the board definition and variant file from
https://github.com/ICantMakeThings/Nicenano-NRF52-Supermini-PlatformIO-Support

In your platformio project, you need the boards/ and variants/ file.

## Setting things up
First, set things up, create a python venv and install platformio:
* Clone the source code using git:
```sh
git clone https://github.com/bertrik/nicenano-example
  ```
* enter the arduino source tree:
```sh
cd nicenano-example
cd supermini
```
* create python virtual env and activate it:
```sh
python3 -m venv .venv
source .venv/bin/activate
```
* install platformio:
```sh
pip3 install platformio
```

## Running the example
Once platformio is installed in the virtual env, you can compile and upload the example program:
* Connect the supermini to USB and upload the program using
```sh
pio run -t upload
```
* You should now be able to see the simple command shell on it
```sh
pio device monitor
```


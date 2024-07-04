# Project Discription
MCU1:

Components:
Push Button - Temperature sensor - DC motor (as a
fan).
Description:
1. MCU1 reads the state from E2PROM before
reading temperature to act according to it as an
abnormal state or not.
2. MCU1 reads temperature and store state as
normal initially in E2PROM then moves the fan (DC
motor) with acceptable speed according to states
and send temperature to MCU2 using UART.
3. If the user presses the push button and the
temperature is between 40◦C and 50◦C, MCU1 sends
to MCU2 code as shutting down the machine using
UART.

MCU2:

Components:
Servo motor - 3 Leds - potentiometer - Dc motor (as
machine) - Buzzer.
Description:
1. MCU2 receives massages using UART from MCU1
and acts according it.
2. The potentiometer controls the speed of the
machine (DC motor).
States:
1) Normal state
- If the temperature is lower than 20◦C, MCU1 will stop fan and MCU2 will
lighten green led.
- Between 20◦C and 40◦C, the Fan in MCU1 is moved with speed increasing
according to increasing temperature which has max speed at 40◦C and
MCU2 lightens yellow led.
- Between 40◦C and 50◦C, MCU1 moves the fan with max speed and MCU2
lights a red LED and stops the machine by pressing the push button.
- Greater than 50◦C, MCU1 and MCU2 enter in emergency state.
2) Emergency state:
- Begin counting time.
- MCU1 moves the fan with max speed.
- MCU2 lightens red LED and runs buzzer.
3) Abnormal state:
- MCU1 moves the fan with max speed.
- MCU2 lighten red LED, open servo with 90 degrees, stop the machine and
run the buzzer.

[![CC BY-NC 4.0][cc-by-nc-shield]][cc-by-nc]

![logo_inverted](https://github.com/jmotp/lince/assets/12650512/22e1eef5-df80-4261-b1af-a147acbc27b6)

Firmware for the Linked Industrial Controller platform

Repository to track firmware development of the Lince Platform. 

Lince is a development board designed around the TM4C129E microcontroller. It contains interfaces that enable it to connect, read, and control industrial sensors and actuators according to IEC61131-2.

List of Interfaces: 

- 8 Isolated Digital Outputs (Divided by two logic levels, defined by the user, up to 48V)
- 8 Isolated Digital Inputs 12/24V
- 4 Analog Inputs which can be calibrated for up to 24V.
- 4 Analog Outputs via PWM
- 2 Independent CAN Interfaces (DB9 and screw terminals)
- 1 USB-C Connector for flashing, powering, and communication
- 1 10/100 RJ45 Ethernet Connector 
- 1 RS-485 interface via screw terminals
- 1 SPI interface for up to 3 devices
- 1 I2C interface

Power and Development:

Lince can be powered via:
- Barrel Jack ( 5 to 48V)
- Screw Terminals (5 to 48V)
- USB-C (5V)
- CAN Screw Terminals and Connectors (12 to 24V)

The firmware is built around TI-RTOS (https://www.ti.com/tool/TI-RTOS-MCU).

![image](https://github.com/jmotp/lince/assets/12650512/bff662b7-57d5-4c93-8be2-32acbcfdbf82)


This work is licensed under a
[Creative Commons Attribution-NonCommercial 4.0 International License][cc-by-nc].

[![CC BY-NC 4.0][cc-by-nc-image]][cc-by-nc]

[cc-by-nc]: https://creativecommons.org/licenses/by-nc/4.0/
[cc-by-nc-image]: https://licensebuttons.net/l/by-nc/4.0/88x31.png
[cc-by-nc-shield]: https://img.shields.io/badge/License-CC%20BY--NC%204.0-lightgrey.svg


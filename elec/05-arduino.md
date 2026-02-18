<link href="../style.css" rel="stylesheet"></link>

**[ [Home](../index.html) | [Elec](00-elec.html) | Arduino | [Counter](10-counter.html) | [Oscillator](15-oscillator.html) | [Temp](20-temperature.html) | [Meter](25-meter.html) | [Transistor](30-transistor.html) | [Other](35-other.html) ]**

## Arduino

---

#### Reference docs

* Uno Rev 3
    
    [https://www.microcontrollertips.com/wp-content/...](https://www.microcontrollertips.com/wp-content/uploads/2019/02/Figure1_Arduino_UNO_R3_Pin_Mapping.png)  
    [https://forums.futura-sciences.com/pinout](https://forums.futura-sciences.com/attachments/electronique/385612d1553182399-utilisation-spi-arduino-controler-un-generateur-arduino-pin.png)  
    [https://www.arduino.cc/schematic](https://www.arduino.cc/en/uploads/Main/Arduino_Uno_Rev3-schematic.pdf)

* Pro Mini
    
    [https://cdn.compacttool.ru/pinout](https://cdn.compacttool.ru/images/docs/5bc057bb257ea.jpg)  
    [https://www.arduino.cc/schematic](https://www.arduino.cc/en/uploads/Main/Arduino-Pro-Mini-schematic.pdf)

* ATmega328P Datasheet
    
    [https://ww1.microchip.com/.../ATmega328P_Datasheet.pdf](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf)  

* Install Arduino Cli

    docs : https://arduino.github.io/arduino-cli/  
    
    x86-64 :
    
    ```
    wget -O /tmp/arduino_cli.tar.gz \
    https://downloads.arduino.cc/arduino-cli/arduino-cli_latest_Linux_64bit.tar.gz
    ```
    
    arm64 :
    
    ```
    wget -O /tmp/arduino_cli.tar.gz \
    https://downloads.arduino.cc/arduino-cli/arduino-cli_latest_Linux_ARM64.tar.gz
    ```
    
    `sudo tar -C /usr/local/bin/ -zxvf /tmp/arduino_cli.tar.gz arduino-cli`
    
    https://arduino.github.io/arduino-cli/0.32/getting-started/  
    
    ```
    arduino-cli config init
    arduino-cli core update-index
    arduino-cli core install arduino:avr
    ```
    
    Set user dir in `nano $HOME/.arduino15/arduino-cli.yaml` :  
    
    ```
    directories:
        user: /home/hotnuma/DevFiles/libarduino/
    ```
    
    Create a sketch : `arduino-cli sketch new MyFirstSketch`  
    
    Plug the board and list devices :
    
    ```
    arduino-cli board list
    Port         Protocol Type              Board Name  FQBN            Core
    /dev/ttyACM0 serial   Serial Port (USB) Arduino Uno arduino:avr:uno arduino:avr
    /dev/ttyAMA0 serial   Serial Port       Unknown
    ```
    
    Upload to UNO :
    
    ```
    arduino-cli compile -b arduino:avr:uno MyFirstSketch
    arduino-cli upload -p /dev/ttyACM0 -b arduino:avr:uno MyFirstSketch
    sudo minicom -D /dev/ttyACM0 -b 9600
    ```

    Upload to Pro Mini 16 MHz :
    
    ```
    arduino-cli compile -b arduino:avr:pro:cpu=16MHzatmega328 MyFirstSketch
    arduino-cli upload -p /dev/ttyUSB0 -b arduino:avr:pro:cpu=16MHzatmega328 MyFirstSketch
    sudo minicom -D /dev/ttyUSB0 -b 9600
    ```
    
    Read serial output :
    
    https://arduino.stackexchange.com/questions/79058/  
    
    List cores and libraries :
    
    ```
    arduino-cli core list
    arduino-cli lib list
    ```
    
    Upgrade libraries : `arduino-cli lib upgrade`

<!--
* Installing Libraries
    
    [https://docs.arduino.cc/software/ide-v1/tutorials/installing](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries)  
    [https://create.arduino.cc/projecthub/akshayjoseph666/adding-](https://create.arduino.cc/projecthub/akshayjoseph666/adding-library-in-arduino-ide-7deb01)  
-->


#### Display

* OLED SSD1306

    https://www.arduino.cc/reference/en/libraries/ssd1306/  

* LCD I2C
    
    https://www.makerguides.com/character-i2c-lcd-arduino-tutorial/  


#### Registers

* Port Register Control (Electronoobs)
    
    https://www.youtube.com/watch?v=UhTRrjYXqPU  
    https://electronoobs.com/eng_arduino_tut12.php  


#### Interrupts

* Pin Change Interrupts

    [https://thewanderingengineer.com/2014/08/11/arduino-pin-chan](https://thewanderingengineer.com/2014/08/11/arduino-pin-change-interrupts/)  
    https://www.youtube.com/watch?v=ZDtRWmBMCmw (Electronoobs)  

* External Interrupts (SparkFun)
    
    https://www.youtube.com/watch?v=J61_PKyWjxU  

* Timer Interrupts (SparkFun)
    
    https://www.youtube.com/watch?v=2kr5A350H7E  


#### Button

* Debounce
    
    https://skillbank.co.uk/arduino/switchbounce.htm  
    https://www.youtube.com/watch?v=jYOYgU2vlSE (educ8s.tv)  

* Toggle button library
    
    https://github.com/petslane/PBtnToggle

* Librairies

    https://www.arduino.cc/reference/en/libraries/button/  
    http://thomasfredericks.github.io/Bounce2/files/index.html  
    https://www.arduino.cc/reference/en/libraries/ezbutton/  
    https://www.arduino.cc/reference/en/libraries/button-arduino/  
    https://www.arduino.cc/reference/en/libraries/jc_button/  
    https://github.com/JChristensen/JC_Button  


#### ADC
    
* Arduino

    [https://www.arduino.cc/reference/...](https://www.arduino.cc/reference/en/language/functions/analog-io/analogreference/)  
    https://skillbank.co.uk/arduino/adc.htm  
    https://skillbank.co.uk/arduino/measure.htm  
    https://www.gammon.com.au/adc  
    [http://riton-duino.blogspot.com/2018/11/arduino-les-performa](http://riton-duino.blogspot.com/2018/11/arduino-les-performances-de-ladc.html)  

* ADS1115
    
    https://passionelectronique.fr/tutorial-ads1115/  
    https://www.best-microcontroller-projects.com/ads1115.html  


#### Filtering

* Moving average filter
    
    [https://maker.pro/arduino/tutorial/...](https://maker.pro/arduino/tutorial/how-to-clean-up-noisy-sensor-data-with-a-moving-average-filter)  
    [https://docs.arduino.cc/built-in-examples/...](https://docs.arduino.cc/built-in-examples/analog/Smoothing)  
    [https://www.megunolink.com/articles/...](https://www.megunolink.com/articles/coding/3-methods-filter-noisy-arduino-measurements/)  


#### PID Controler

* Slow Response PID
    
    [https://electronics.stackexchange.com/questions/334457/](https://electronics.stackexchange.com/questions/334457/suggestions-for-tuning-slow-response-pid-fire-box-control)  
    [https://stackoverflow.com/questions/26508261/](https://stackoverflow.com/questions/26508261/tuning-pid-in-systems-with-delay)  

* Libraries
    
    https://playground.arduino.cc/Code/PIDLibrary/  
    https://github.com/br3ttb/Arduino-PID-Library/  
    https://github.com/PowerBroker2/ArduPID  


#### Other

*  Arduino digital input protection
    
    [https://forum.arduino.cc/t/protection-for-12v-signal-into-ar](https://forum.arduino.cc/t/protection-for-12v-signal-into-arduino-digital-input/563113)  

* Inline Functions
    
    https://www.youtube.com/watch?v=kmHyRaiJLpQ (Indrek)  

<br/>


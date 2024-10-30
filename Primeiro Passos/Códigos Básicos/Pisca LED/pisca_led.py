from pyfirmata import Arduino

#defina a porta usb que o arduino está conectada
PORTA="COM8"

#definição da porta do arduino 
arduino=Arduino(PORTA)

#definição do led e a porta conectada
led = arduino.get_pin('d:13:o')


while True:
    led.write(1)
    arduino.pass_time(100)
    led.write(0)
    arduino.pass_time(100)
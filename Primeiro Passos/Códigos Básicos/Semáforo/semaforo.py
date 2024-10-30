from pyfirmata import Arduino

#identifica qual porta usb o arduino está conectado
PORTA = 'COM8'

arduino=Arduino(PORTA)

#definindo os pinos
led_vermelho = arduino.get_pin('d:11:o')
led_amarelo = arduino.get_pin('d:12:o')
led_verde = arduino.get_pin('d:13:o')

while True:
    #Acender Led Verde
    led_verde.write(1)
    arduino.pass_time(5)
    led_verde.write(0)
    
    #Acender Led Amarelo
    led_amarelo.write(1)
    arduino.pass_time(2)
    led_amarelo.write(0)

    #Acender Led Vermelho
    led_vermelho.write(1)
    arduino.pass_time(5)
    led_vermelho.write(0)


    
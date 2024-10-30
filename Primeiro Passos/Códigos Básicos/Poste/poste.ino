int ldr = A0;//Atribui A0 a variável ldr
int valorldr = 0;//Declara a variável valorldr como inteiro
int led=12;

void setup() {
  pinMode(ldr, INPUT);//Define ldr (pino analógico A0) como saída
  Serial.begin(9600);//Inicialização da comunicação serial, com taxa de transferência em bits por segundo de 9600
    pinMode(led,OUTPUT);
}
void loop() {
   valorldr=analogRead(ldr);//Lê o valor do sensor ldr e armazena na variável valorldr
  if ( valorldr <= 500){
    digitalWrite(led, HIGH);
  }else{
    digitalWrite(led, LOW);
  }
  Serial.println(valorldr);
}
    
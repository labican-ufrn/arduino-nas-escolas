
//Defina a porta que o led se encontra conectado
int led=12;

void setup()
{
  pinMode(led, OUTPUT);
}

void loop()
{
  digitalWrite(led, HIGH);
  delay(100); // Wait for 100 millisecond(s)
  digitalWrite(led, LOW);
  delay(100); // Wait for 100 millisecond(s)
}
#include <Servo.h>

int distancia = 0; // Variavel distancia setada a zero

long readUltrasonicDistance(int triggerPin, int echoPin) // configuração do sensor de distancia
{
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10); // coloca o triggerPin no estado HIGH por 10 microsegundos
    digitalWrite(triggerPin, LOW);
    pinMode(echoPin, INPUT);
  
    return pulseIn(echoPin, HIGH);// "Lê" o echoPin, e retorna o tempo percorrido pela onda em microsegundos
}

int pos =(0); // Variavel posição setada a zero

Servo myservo1; // identificação do primeiro servo
Servo myservo2; // identificação do segundo servo

void setup () // é a função utilizada pra iniciar as variaveis. usada somente uma vez. quando a placa é energizada ou quando é resetada
{ 
    myservo1.attach(9); // alocação do primeiro servo à porta nove
    myservo2.attach(10); // alocação do segundo servo à porta dez
  pinMode(9, OUTPUT); // configuração da porta 9 como output
    pinMode(10, OUTPUT); // configuração da porta 10 como output
}

void loop() // é a função que executa comandos infinitamente, em um looping eterno.
{
  digitalWrite(9, LOW); // "escreve" o valor LOW na porta digital nove
    digitalWrite(10, LOW); // "escreve o valor LOW na porta digital dez
    distancia = 0.01723 * readUltrasonicDistance(7, 6); // mede a distancia atraves das portas sete e seis
  
    if (distancia > 5 && distancia <= 30) // seta um parametro de ação (caso a distancia esteja entre 40cm e 200cm)
    {
    digitalWrite(9, HIGH); // "escreve" o valor HIGH na porta digital nove
        digitalWrite(10, HIGH); // "escreve" o valor HIGH na porta digital dez
      for (pos = 0; pos <= 90; pos += 1) { // diz que a posição deve ir de 0 a 90
  myservo1.write(pos); // "escreve" essa nova posição no primeiro servo
    myservo2.write(pos); // "escreve" essa nova posição no segundo servo
  delay(10); // diz o tempo que essa ação vai levar (ir de 0 a 90 em um delay de 10)
  }
  delay(5000);
  for (pos = 90; pos>=0; pos -=1) { // diz que a posição deve ir de 90 a 0
  myservo1.write(pos); // "escreve" essa nova posição no primeiro servo
    myservo2.write(pos); // "escreve" essa nova posição no segundo servo
  delay(15); // diz o tempo que essa ação vai levar (ir de 90 a 0 em um delay de 30)
  }
      delay(2500); // o tempo que o codigo vai levar pra ler a proxima instrução (dois segundos e meio)
        
    }
    else
    { digitalWrite(9, LOW); // "escreve" o valor LOW na porta digital nove
      digitalWrite(10, LOW); // "escreve" o valor LOW na porta digital dez
        delay(10);
    }
    delay(10);  //Espera por 10 milisegundos(s) recomeçar o loop
}

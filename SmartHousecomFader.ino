#include <Servo.h> 


Servo PotPq; // variável do servo portão pequeno
Servo PotGd; // variável do servo portão grande
int LuzFundos = 2; // variável da varanda dos fundos
int LuzSala = 3; // variável da sala
int LuzQt1  = 4; // variável do quarto 1 com sacada
int LuzQt2  = 5; // variável do quarto 2
int LuzQt3 = 6; // variável do quarto 3
int LuzQt4 = 13; // variável do quarto 4
const int Jardim = 7; // variável do jardim
int Cozinha = 8; // variável da cozinha 
int LuzGaragem = 11; // variável da garagem
int Banheiro = 12; // variável do banheiro
int pinopot = 9;
int valorpot = 0;
float luminosidade = 0;

//Controladores do efeito de fader
int brilho = 0;
int fader = 3;
boolean acende = true;


void setup() 
// tornando as portas como saída em nível 1 ( 5V )
{
  PotPq.attach(9); 
  PotGd.attach(10); 
  Serial.begin(9600); 
  pinMode(LuzFundos, OUTPUT); 
  pinMode(LuzSala, OUTPUT); 
  pinMode(LuzQt1, OUTPUT);
  pinMode(LuzQt2, OUTPUT);
  pinMode(LuzQt3, OUTPUT);
  pinMode(LuzQt4, OUTPUT);
  pinMode(Jardim, OUTPUT);
  pinMode(Cozinha, OUTPUT);
  pinMode(LuzGaragem, OUTPUT);
  pinMode(Banheiro, OUTPUT);

  PotPq.write(120); // valores em parentes são as frequências de trabalho dos motores e programação
  PotGd.write(10);
  Serial.begin(9600);  

  pinMode(pinopot, INPUT);
}
 
void loop()
{
 
    

  //Garagem e Portão São os servomotores
  if (Serial.available()){
  char v;

  // início da programação para o reconhecimento do aplicativo
  for (;;){
  inicio:
  v = 0;
  v = Serial.read();
  
  // este trecho liga e desliga pelos botoes
 
  while (v == 'a')
  {
  digitalWrite(LuzQt1, LOW);
  Serial.println("Valor Recebido: a");
  goto inicio;
  delay(750);
  }
  
  while (v == 'A')
  {
  digitalWrite(LuzQt1, HIGH);
  Serial.println("Valor Recebido: A");
  goto inicio;
  delay(750);
  }
  
  while (v == 'b')
  {
  digitalWrite(LuzQt2, LOW);
  Serial.println("Valor Recebido: b");
  goto inicio;
  delay(750);
  }
  
  while (v == 'B')
  {
  digitalWrite(LuzQt2, HIGH);
  Serial.println("Valor Recebido: B");
  goto inicio;
  delay(750);
  }

  while (v == 'c')
  {
  digitalWrite(LuzQt3, LOW);
  Serial.println("Valor Recebido: c");
  goto inicio;
  delay(750);
  }
  
  while (v == 'C')
  {
  digitalWrite(LuzQt3, HIGH);
  Serial.println("Valor Recebido: C");
  goto inicio;
  delay(750);
  }

  while (v == 'd')
  {
  digitalWrite(LuzSala, LOW);
  Serial.println("Valor Recebido: d");
  goto inicio;
  delay(750);
  }
  
  while (v == 'D')
  {
  digitalWrite(LuzSala, HIGH);
  Serial.println("Valor Recebido: D");
  goto inicio;
  delay(750);
  }


  if (v == '2')
  {
  digitalWrite(Cozinha, LOW);
  Serial.println("Valor Recebido: 2");
  goto inicio;
  delay(750);
  }
  
  if (v == '5')
  {
  digitalWrite(Cozinha, HIGH);
  Serial.println("Valor Recebido: 5");
  goto inicio;
  delay(750);
  }

if (v == 'f')
  {
  digitalWrite(Jardim, LOW);
  Serial.println("Valor Recebido: f");
  goto inicio;
  delay(750);
  }
  
  if (v == 'F')
  {
  Serial.println("Valor Recebido: F");
  analogWrite(Jardim,brilho); 
   //Processo de acendimento do led usando o efeito fader.
  if (acende == true) {
    if (brilho < 255) {
      brilho = brilho + fader; //aumentando o brilho do led.
    } else {     
      acende = false;
        }
  }
  
  goto inicio;
  delay(750);
  }

  
 while (v == 'h')
  {
  digitalWrite(LuzFundos, LOW);
  Serial.println("Valor Recebido: h");
  goto inicio;
  delay(750);
  }
  
  while (v == 'H')
  {
  digitalWrite(LuzFundos, HIGH);
  Serial.println("Valor Recebido: H");
  goto inicio;
  delay(750);
  }
     

  while (v == 'n')
  {
  digitalWrite(Banheiro, LOW);
  Serial.println("Valor Recebido: n");
  goto inicio;
  delay(750);
  }
  
  while (v == 'N')
  {
  digitalWrite(Banheiro, HIGH);
  Serial.println("Valor Recebido: N");
  goto inicio;
  delay(750);
  }
     
  while (v == 'g')
  {
  digitalWrite(LuzQt4, LOW);
  Serial.println("Valor Recebido: g");
  goto inicio;
  delay(750);
  }
  
  while (v == 'G')
  {
  digitalWrite(LuzQt4, HIGH);
  Serial.println("Valor Recebido: G");
  goto inicio;
  delay(750);
  }
     

//este trecho liga os motores

  while (v == 'p')
  {
  PotGd.write(20);
  Serial.println("Valor Recebido: p");
  goto inicio;
  delay(750);
  }
  
  while (v == 'P')
  {
   PotGd.write(140);
   Serial.println("Valor Recebido: P");
   goto inicio;
   delay(750);
  }    


//Este trecho liga as luzes do jardim conforme a luminosidade
 // Le o valor - analogico - do LDR  
  valorpot = analogRead(pinopot);  

  // Converte o valor lido do LDR
  luminosidade = map(valorpot, 0, 1023, 0, 255); 
  Serial.print("Valor lido do LDR : ");   

  // Mostra o valor lido do LDR no monitor serial  
  Serial.print(valorpot);  
  Serial.print(" = Luminosidade : ");  

  // Mostra o valor da luminosidade no monitor serial  
  Serial.println(luminosidade); 
  
  // Acende o led com luminosidade variável
  analogWrite(Jardim, luminosidade); 
  
   
  } 
  } 
}

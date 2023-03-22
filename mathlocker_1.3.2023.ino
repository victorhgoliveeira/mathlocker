#include <IRremote.h>

int RECV_PIN = 11;    
int pinoledvermelho = 5;  
int pinoledverde = 7;
float eq[2][3];
String leitura="";
long x=0;
long y=0;
long a=0;
long b=0;

void setup()  
{  
  pinMode(pinoledvermelho, OUTPUT);   
  pinMode(pinoledverde, OUTPUT);  
  Serial.begin(9600);  
  IrReceiver.begin(RECV_PIN);
  randomSeed(analogRead(0));
}



//Função 1: para leitura dos numeros IR
int lerNumeros(){
  int saida=0;
  if(IrReceiver.decode()){
    auto dado= IrReceiver.decodedIRData.decodedRawData;
      switch(dado){
        case 3860463360:
        leitura+= "0";
        Serial.println(leitura);
        break;
        case 31255149440:
        leitura+="1";
        Serial.println(leitura);
        break;
        case 3108437760:
        leitura+="2";
        Serial.println(leitura);
        break;
        case 3091726080:
        leitura+="3";
        Serial.print(leitura);
        break;
        case 3141861120:
        leitura+="4";
        Serial.println(leitura);
        break;
        case 3208707840:
        leitura+="5";
        Serial.println(leitura);
        break;
        case 3158572800:
        leitura+="6";
        Serial.println(leitura);
        break;
        case 4161273600:
        leitura+="7";
        Serial.println(leitura);
        break;
        case 3927310080 :
        leitura+="8";
        Serial.println(leitura);
        break;
        case 4127850240:
        leitura+="9";
        Serial.println(leitura);
        case 3810328320:
        saida = converteNumero(leitura);
        leitura="";
        break;
    }
    IrReceiver.resume();
  }
  delay(500);
  return saida;
}
//Função 2: de converter em numero
int converteNumero(String teclado){
  return teclado.toInt();
}
//Função 3: Irá ler os números da Matriz
void lerMatriz(float numero){
  for(int i=0; i<2; i++){
    for(int j=0; j<3; j++){
      eq[i][j]=numero;
    }
  }
}
void exibirMatriz(){
  Serial.print(eq[0][0]);
  Serial.print("x");
  Serial.print(" + ");
  Serial.print(eq[0][1]);
  Serial.print("y");
  Serial.print(" = ");
  Serial.println(eq[0][2]);
  Serial.print(eq[1][0]);
  Serial.print("x");
  Serial.print(" + ");
  Serial.print(eq[1][1]);
  Serial.print("y");
  Serial.print(" = ");
  Serial.println(eq[1][2]);
}
void resolveEquacao(){
  eq[0][1]=((eq[1][0]*eq[0][2])-eq[1][2])/((eq[1][0]*eq[0][0])-eq[1][1]);
  eq[0][0]=(eq[0][2]-eq[0][1]);
  exibirMatriz();
}

void faseUm(long x, long y){
  a=random(1,10);
  b=random(1,10);
  eq[0][0]=1;
  eq[0][1]=1;
  eq[0][2]=(x+y);
  eq[1][0]=(a);
  eq[1][1]=(b);
  eq[1][2]=((a*x)+(b*y));
  exibirMatriz();
}


void loop(){
 x=random(1,10);
 y=random(1,10);
 faseUm(x, y);
  delay(5000);
}

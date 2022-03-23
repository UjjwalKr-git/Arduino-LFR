const int IRS_R = 3;
const int IRS_L = 4;
const int motorA1= 8;
const int motorA2= 9;
const int motorB1=10;
const int motorB2=11;

int IRSinp_R;
int IRSinp_L;

void setup()
{
  pinMode(IRS_R, INPUT);
  pinMode(IRS_L, INPUT);
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  Serial.begin(9600);
  IRSinp_R = digitalRead(IRS_R);
  IRSinp_L = digitalRead(IRS_L);
  PRINTvalues();
}

void loop()
{
  IRSinp_R = digitalRead(IRS_R);
  IRSinp_L = digitalRead(IRS_L);
  EXE();
  delay(1000);
  BKWD();
  delay((IRSinp_R == 1) && (IRSinp_L == 1));
  revEXE();
}

void EXE()
{
  IRSinp_R = digitalRead(IRS_R);
  IRSinp_L = digitalRead(IRS_L);
  
  if((IRSinp_R == 1) && (IRSinp_L == 1))
  {
    FWD();
    //PRINTvalues();
  }
  else if((IRSinp_R == 0) && (IRSinp_L == 0))
  {
    STOP();
    //PRINTvalues();
    delay(1000);
  }
  else if((IRSinp_R == 0) && (IRSinp_L == 1))
  {
    RIGHT();
    PRINTvalues();
    delay(IRSinp_R == 1);
  }
  else if((IRSinp_R == 1) && (IRSinp_L == 0))
  {
    LEFT();
    PRINTvalues();
    delay(IRSinp_L == 1);
  }
  /*else
  {
    STOP();
    //PRINTvalues();
    delay((IRSinp_R == 1) && (IRSinp_R == 1));
  }*/
}

void revEXE()
{
  IRSinp_R = digitalRead(IRS_R);
  IRSinp_L = digitalRead(IRS_L);
  
  if((IRSinp_R == 1) && (IRSinp_L == 1))
  {
    BKWD();
    //PRINTvalues();
  }
  else if((IRSinp_R == 0) && (IRSinp_L == 0))
  {
    STOP();
    //PRINTvalues();
    delay(1000);
  }
  else if((IRSinp_R == 0) && (IRSinp_L == 1))
  {
    LEFT();
    PRINTvalues();
    delay(IRSinp_R == 1);
  }
  else if((IRSinp_R == 1) && (IRSinp_L == 0))
  {
    RIGHT();
    PRINTvalues();
    delay(IRSinp_L == 1);
  }
  /*else
  {
    STOP();
    //PRINTvalues();
    delay((IRSinp_R == 1) && (IRSinp_R == 1));
  }*/
}

void PRINTvalues()
{
  Serial.print("IRS_R : ");
  Serial.print(IRSinp_R);
  Serial.print("\t IRS_L : ");
  Serial.println(IRSinp_L);
}

void FWD()
{
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}

void BKWD()
{
  Serial.println("\tGoing Back...!");
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
}

void LEFT()
{
  Serial.println("\t\tTurning Left...!");
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW); 
}

void RIGHT()
{
  Serial.println("\t\tTurning Right...!");
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
}

void STOP()
{
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
}

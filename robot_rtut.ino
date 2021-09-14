#define LEFT_MOTOR_DIRECTION  NORM    //направления мотора
#define RIGHT_MOTOR_DIRECTION NORM
#define RIGHT_MOTOR_MODE HIGH         //если что - меняй HIGH на LOW 
#define LEFT_MOTOR_MODE HIGH          //если что - меняй HIGH на LOW 

#define MOTOR_MAX 255
#define minDuty 0

#define RIGHT_MOTOR_PWM 7            // обязательно должен быть ШИМ
#define LEFT_MOTOR_PWM 3              // обязательно должен быть ШИМ
#define LEFT_MOTOR_D 2
#define RIGHT_MOTOR_D 6
#define RGB_1 4
#define RGB_2 8
#define VAC_CLEANER 25
//#define rxPin 10
//#define txPin 11
 

char _bluetoothValue;
byte _value;


void setup()
{
 /* #if (LEFT_MOTOR_PWM == 3 || LEFT_MOTOR_PWM == 11 || RIGHT_MOTOR_PWM == 3 || RIGHT_MOTOR_PWM == 11)
    //D3 и D11 62.5 kHz PWM 
    TCCR2B = 0b00000001;
    TCCR2A = 0b00000011;
  #elif (LEFT_MOTOR_PWM == 9 || LEFT_MOTOR_PWM == 10 || RIGHT_MOTOR_PWM == 9 || RIGHT_MOTOR_PWM == 10)
    //D9 и D10 62.5 kHz PWM 
    TCCR1A = 0b00000001;
    TCCR1B = 0b00001001;
  #endif*/

  Serial.begin(9600);

  pinMode(RIGHT_MOTOR_PWM, OUTPUT);
  pinMode(LEFT_MOTOR_PWM, OUTPUT);
  pinMode(RIGHT_MOTOR_D, OUTPUT);
  pinMode(LEFT_MOTOR_D, OUTPUT);

  pinMode(VAC_CLEANER, OUTPUT);
}

void loop()
{
  if(Serial.available()){
    _bluetoothValue = Serial.read();
    switch(_bluetoothValue)
    {
      case '1': 
  
      Forward();
      break;
  
      case '2':
      Left();
      break;

      case '3':
      Right();
      break;
  
      case '4':
      Backward();
      break;
  
      case '5':
      CleaningOn();
      break;
  
      case '6':
      CleaningOff();
      break;
  
      case '7':
      Stop();
      break;
    }
  }
}

void CleaningOn() {digitalWrite(VAC_CLEANER, HIGH);}

void CleaningOff() {digitalWrite(VAC_CLEANER, LOW);}

void Forward() {
analogWrite(RIGHT_MOTOR_PWM, 90);
digitalWrite(RIGHT_MOTOR_D, HIGH);
analogWrite(LEFT_MOTOR_PWM, 150);
digitalWrite(LEFT_MOTOR_D, LOW);
}
  
void Backward() {
analogWrite(RIGHT_MOTOR_PWM, 90);
digitalWrite(RIGHT_MOTOR_D, LOW);
digitalWrite(LEFT_MOTOR_D, HIGH);
analogWrite(LEFT_MOTOR_PWM, 150);
}

void Right() {
analogWrite(RIGHT_MOTOR_PWM, 140);
digitalWrite(RIGHT_MOTOR_D, HIGH);
digitalWrite(LEFT_MOTOR_D, LOW);
analogWrite(LEFT_MOTOR_PWM, 0);
}

void Left() {
analogWrite(RIGHT_MOTOR_PWM, 0);
digitalWrite(RIGHT_MOTOR_D, LOW);
digitalWrite(LEFT_MOTOR_D, LOW);
analogWrite(LEFT_MOTOR_PWM, 150);
}

void Stop(){
analogWrite(RIGHT_MOTOR_PWM, 0);
digitalWrite(RIGHT_MOTOR_D, LOW);
digitalWrite(LEFT_MOTOR_D, LOW);
analogWrite(LEFT_MOTOR_PWM, 0);
}

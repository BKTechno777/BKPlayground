#include <avr/wdt.h>


#define PIN_Voltage A3
//TB6612
#define PIN_Motor_PWMA 5
#define PIN_Motor_PWMB 6
#define PIN_Motor_BIN_1 8
#define PIN_Motor_AIN_1 7
#define PIN_Motor_STBY 3

volatile float VoltageData_V;
bool VoltageDetectionStatus;
const float VoltageDetection = 7.00;

void setup() {
  // // put your setup code here, to run once:
   Serial.begin(9600);
  // pinMode(PIN_Voltage, INPUT);
   DeviceDriverSet_Motor_Init();
   wdt_enable(WDTO_2S);
}

void loop() {
   wdt_reset();
  // ApplicationFunctionSet_SensorDataUpdate();

   digitalWrite(PIN_Motor_STBY, HIGH);
   digitalWrite(PIN_Motor_AIN_1, HIGH);
   analogWrite(PIN_Motor_PWMA, 2);
}

void ApplicationFunctionSet_SensorDataUpdate(void)
{

  // AppMotor.DeviceDriverSet_Motor_Test();
  {
    static unsigned long VoltageData_time = 0;
    static int VoltageData_number = 1;
    if (millis() - VoltageData_time > 100) //10ms
    {
      VoltageData_time = millis();
      float Voltage = (analogRead(PIN_Voltage) * 0.0375);
      VoltageData_V = Voltage + (Voltage * 0.08);
      if (VoltageData_V < VoltageDetection)
      {
        VoltageData_number++;
        if (VoltageData_number == 50)
        {
          VoltageDetectionStatus = true;
          VoltageData_number = 0;
        }
      }
      else
      {
        VoltageDetectionStatus = false;
      }
    }
  }
}


/*Motor control*/
void DeviceDriverSet_Motor_Init(void)
{
  pinMode(PIN_Motor_PWMA, OUTPUT);
  pinMode(PIN_Motor_PWMB, OUTPUT);
  pinMode(PIN_Motor_AIN_1, OUTPUT);
  pinMode(PIN_Motor_BIN_1, OUTPUT);
  pinMode(PIN_Motor_STBY, OUTPUT);
}

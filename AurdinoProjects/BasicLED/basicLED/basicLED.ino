const int ledPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  countDown(5);
}

void loop() {
  static int delayPeriod = 100;
  static int countDir = 1;
  digitalWrite(ledPin, HIGH);
  delay(delayPeriod);
  digitalWrite(ledPin, LOW);
  delay(delayPeriod);

  countDir = checkDirChange(delayPeriod, countDir);

  delayPeriod += 100*countDir;
  Serial.print("New Wait time: ");
  Serial.println(delayPeriod);
}


int checkDirChange(int delayPeriod, int countDir)
{
  if (delayPeriod == 1000 || delayPeriod == 0)
  {
    countDir *= -1;

    if(countDir < 0)
    {
      Serial.println("Going Down");
    }
    else
    {
      Serial.println("Going Up");
    }
  }
  return countDir;
}

void countDown(int max)
{
  for(int i = max;i>0;i--)
  {
    Serial.print(i);
    Serial.print(" ");
  }
  Serial.println("Go");
}
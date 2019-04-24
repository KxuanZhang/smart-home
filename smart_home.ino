#include<LiquidCrystal.h>
#include <dht11.h>

LiquidCrystal lcd(13,12,2,3,4,5);
dht11 DHT11;
#define DHT11PIN 8
#define Sensor  7
#define fengming 10 
char c = '0';

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Welcome!");

  Serial.begin(9600);
  Serial.println("DHT11 TEST PROGRAM");
  Serial.print("LIBRARY");
  // 输出 DHT 库的版本号
  Serial.println(DHT11LIB_VERSION);
  Serial.println();
  pinMode(Sensor, INPUT);
  pinMode( fengming  , INPUT);
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,INPUT);
}

void loop() {
  int i = 0;
  
  while(Serial.available())
   {
    i += 1;
      c=Serial.read();
     if( 1 > 1000)
         break;
   }
//      Serial.println("while\n");
   if(c=='1')
     { 
           Serial.println("IN 1\n");
            Serial.println("\n");

            int chk = DHT11.read(DHT11PIN);

              // 测试 DHT 是否正确连接
            Serial.print("Read sensor: ");
  switch (chk)
  {
    case DHTLIB_OK: 
    Serial.println("OK"); 
    break;
    case DHTLIB_ERROR_CHECKSUM: 
    Serial.println("Checksum error"); 
    break;
    case DHTLIB_ERROR_TIMEOUT: 
    Serial.println("Time out error"); 
    break;
    default: 
    Serial.println("Unknown error"); 
    break;
  }
  // 获取测量数据
  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 2);

  Serial.print("Temperature °C): ");
  Serial.println((float)DHT11.temperature, 2);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.clear();
  lcd.print("H:");
  lcd.print((float)DHT11.humidity );
  lcd.setCursor(8, 0);
  // print the number of seconds since reset:
  lcd.print("T:");
  lcd.print((float)DHT11.temperature );
     int SensorState = digitalRead(Sensor);
       Serial.print("HAVE"  );
Serial.print( SensorState );
  lcd.setCursor(0, 1);

     if(SensorState == 1)
     {
      lcd.print("yes");

             pinMode( fengming  , OUTPUT);
             digitalWrite(A0, HIGH); // turn the LED on (HIGH is the voltage level)
                digitalWrite(A1, LOW); // turn the LED on (HIGH is the voltage level)
                digitalWrite(A2, HIGH); // turn the LED on (HIGH is the voltage level)
        for(int i=200;i<=400;i++)
                {
                  tone(fengming , i);
                  delay(5); 
                          
                                                     
                }
                delay(40);
                for(int i = 400; i >= 200; i--)
                {
                  tone(fengming,i);
                  delay(10);
                          
                }
     }
     else
     {
                 pinMode( fengming  , INPUT);
digitalWrite(A0, HIGH); // turn the LED on (HIGH is the voltage level)
                digitalWrite(A1, HIGH); // turn the LED on (HIGH is the voltage level)
                digitalWrite(A2, HIGH); // turn the LED on (HIGH is the voltage level)
            lcd.print("no");

     }
        }
        if(c == '2')
        
        {
             Serial.println("IN 2\n");
                           pinMode( fengming  , INPUT);
                              lcd.clear();
                              lcd.print("Goodbye!");
        }
  
  delay(100);
   
}

//Librerias
#include "BluetoothSerial.h"

//Variables

//Control
String Variable = "";
bool Estado_Led=false;
//Motores
const byte MotorA[]={26,25};
const byte MotorB[]={27,12};

//Creación del PWM para la ESP32
const uint16_t Frecuencia = 5000;
const byte Resolucion = 10;
const byte Canales[] ={0,1,2,3};

//Variables de Control de Velocidad
uint16_t velocidades[]={0,0};


//BLUETOOTH

//#define USE_PIN 

const char *pin = "1234"; 

String device_name = "Kit_2";

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;



void setup() {

  //Inicialización de la Comunicación Serial
  Serial.begin(115200);
  
  //Bluetooth
  SerialBT.begin(device_name); //Bluetooth device name
  Serial.printf("The device with name \"%s\" is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str());
  #ifdef USE_PIN
    SerialBT.setPin(pin);
    Serial.println("Using PIN");
  #endif

  //Inicialización de los Pines para el Control de los Motores
  Inicialiar_Pines();

  //Creación del PWM
  CrearPWM();
}

void loop() {
  if (SerialBT.available()) {

    
    //Obtención de la variable
    char receivedChar = (char)SerialBT.read();
    Variable = "";
    Variable += receivedChar;
    //Derecha
    if(Variable.equals("3")){

      //MotorA
      ledcWrite(Canales[0],0);
      ledcWrite(Canales[1],500);
      //MotorB
      ledcWrite(Canales[2],1000);
      ledcWrite(Canales[3],0);
      //Imprimir
      Serial.println("Derecha");
    }
    //Izquierda
    if(Variable == "4"){

      //MotorA
      ledcWrite(Canales[0],1000);
      ledcWrite(Canales[1],0);
      //MotorB
      ledcWrite(Canales[2],0);
      ledcWrite(Canales[3],500);
      //Imprimir
      Serial.println("Izquierda");
    }
    //Adelante
    if(Variable == "1"){

      //MotorA
      ledcWrite(Canales[0],1000);
      ledcWrite(Canales[1],0);
      //MotorB
      ledcWrite(Canales[2],1000);
      ledcWrite(Canales[3],0);
      //Imprimir
      Serial.println("Adelante");
    }
    //Atras
    if(Variable == "2"){

      //MotorA
      ledcWrite(Canales[0],0);
      ledcWrite(Canales[1],1000);
      //MotorB
      ledcWrite(Canales[2],0);
      ledcWrite(Canales[3],1000);
      //Imprimir
      Serial.println("Atras");
    }
    if(Variable == "5"){
      ledcWrite(Canales[0],0);
      ledcWrite(Canales[1],0);
      ledcWrite(Canales[2],0);
      ledcWrite(Canales[3],0);
      Serial.println("Stop");
    }
  }
}

void Inicialiar_Pines(){
  pinMode(MotorA[0],OUTPUT);
  pinMode(MotorA[1],OUTPUT);
  pinMode(MotorB[0],OUTPUT);
  pinMode(MotorB[1],OUTPUT);
}
void CrearPWM(){
  ledcSetup(Canales[0],Frecuencia,Resolucion); 
  ledcSetup(Canales[1],Frecuencia,Resolucion); 
  ledcSetup(Canales[2],Frecuencia,Resolucion); 
  ledcSetup(Canales[3],Frecuencia,Resolucion); 
  ledcAttachPin(MotorA[0],Canales[0]);
  ledcAttachPin(MotorA[1],Canales[1]);
  ledcAttachPin(MotorB[0],Canales[2]);
  ledcAttachPin(MotorB[1],Canales[3]);
}

/* 
 *  ENGLISH
 *  
 *  This software "hacks" a regular light power switch for automation.
 *  
 *  When the system starts the relay is set to OFF, no mater in what position the 
 *  light switch is. Maybe it was left ON when a power surge happened.
 *  
 *  At the first change on this power switch, lights will be powered ON, even if
 *  the switch goes to the OPEN position.
 *  
 *  This allows, among other things, to use regular light switches on home automation
 *  systems, avoiding the need to change the switch to some kind of use mommentary push key.
 *  
 *  As it is now integrated to an automation system, you can also use it as a parallel light switch,
 *  using several switches in different areas of a room to turn ON or OFF some especific light.
 *  
 *  The touch and feel is the same as the old fashion light switches, with all the bennefits 
 *  that computerized home automation can offer.
 *  
 *  By: Angelo Marzolla
 *  angelo.marzolla@gmail.com 
 *    
 *  ****** this is my first contribution for GitHub. If you don't mind, please, send me a note if you like it. Thanks!
 *  
 *  
 *  
 *    
 *  PORTUGUES
 *  
 *  Lógica para "enganar" interruptor comum e fazer com que 
 *  ele seja um acionador de automação de iluminação.
 *  
 *  Quando o sistema inicia, os relês ficam DESLIGADOS, não importa
 *  a posição em que o interruptor esteja (On ou OFF).
 *  
 *  Ao primeiro acionamento, (de ON para OFF ou de OFF para ON) o sistema
 *  aciona o relê a que este interruptor esteja ligado.
 *  
 *  Isto permite, entre outras coisas, o acionamento de uma luminária em "paralelo".
 *  É um emulador.
 *  
 *  Além disso, pertite todas as funcções que eua automação tradicional permite.
 *  
 *  Evita a necessidade de trocar os interruptores tradicionais por pulsadores.
 *  
 *  By: Angelo Marzolla
 *  angelo.marzolla@gmail.com 
 *  
 *  
 *  
 *    
 *    
 *    
 */





bool switch01;       // switch status is always OFF when powering system ON. When switched , it changes status of the relay.
bool invert01;       // true when the actual status is inverted (closed turn relay ON, and open turns it OFF0
// bool relay01;     // this line is commented and serves to read on screen for debugging such as other commented lines are.

// Arduino ports
int relay01port = 13;   // Arduino's por number that powers the relay
int in1   = 2;          // Arduino's por number where the physical switch is connected (when connected to ground, it means closed)


void setup() 
{
//  Serial.begin(115200);

//  pinMode( relay01port, OUTPUT);
//  pinMode( in1, INPUT_PULLUP);
  
  digitalWrite(relay01port, LOW);      // sets relay OFF when system is powered ON (useful in the case of a power loss)
  switch01 = !digitalRead( in1 );      // reads the initial status of the switch (open or closed)

//  Serial.println( switch01 );

  
  if ( switch01 )                      // detects if the switch was left closed since the last usage when powering ON the system
  {
    invert01 = true;
  }
  else
  {
    invert01 = false; 
  }

}




void loop() 
{

//  Serial.print( "invert01 = ");
//  Serial.println( invert01 );
//  Serial.print( "switch01 = " );
//  Serial.println( switch01 );
//  Serial.print( "relay01 = " );
//  Serial.println( relay01 );
//  Serial.println();
//  delay(1000);


  switch01 = !digitalRead( in1 );                       // reads the switch to see if it was changed and switches ON or OFF the relay

  if ( invert01 )
  {
    if ( switch01 )
    {
      digitalWrite(relay01port, LOW);
//      relay01 = false;
    }
    else
    {
      digitalWrite(relay01port, HIGH);
//      relay01 = true;    
    }
  }
  else
  {   
    if ( switch01 )
    {
      digitalWrite(relay01port, HIGH);
//      relay01 = true;
    }
    else
    {
      digitalWrite(relay01port, LOW);
//      relay01 = false;
    }
 
  
  }

       
}

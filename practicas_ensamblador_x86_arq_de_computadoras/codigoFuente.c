#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

long numUno=0;
long numDos=0;
double resultado=0;
int posicion=0;
char tecla;
const byte FILAS=4;
const byte COLS=4;

char teclas[FILAS][COLS] = {

{'1','2','3','/'},

{'4','5','6','*'},

{'7','8','9','-'},

{'C','0','=','+'} };

byte filaPins[FILAS] = {7 ,6 ,5 ,4};

byte colPins[COLS] = {3, 2, 1, 0};

Keypad customKeypad = Keypad( makeKeymap(teclas), filaPins, colPins, FILAS, COLS);

void setup()
{
	lcd.begin(16,2);
	lcd.setCursor(5,0);
	lcd.clear(); 
}

void loop() 
{
	tecla = customKeypad.getKey();

	switch(tecla) 
    {
		case '0' ... '9':
			lcd.setCursor(0,0);
			numUno = numUno * 10 + (tecla - '0');
			lcd.print(numUno);
			posicion++;
			break;
		case '+':
			numUno = (resultado != 0 ? resultado : numUno);
			lcd.setCursor(posicion,0);
			lcd.print("+");
			posicion++;
			numDos = SegundoNumero();
			resultado = numUno + numDos;
			lcd.setCursor(1,1);
			lcd.print(resultado);
			numUno = 0,
			numDos = 0;
			posicion=0;
			break;
		case '-':
			numUno = (resultado != 0 ? resultado : numUno);
			lcd.setCursor(posicion,0);
			lcd.print("-");
			posicion++;
			numDos = SegundoNumero();
			resultado = numUno - numDos;
			lcd.setCursor(1,1);
			lcd.print(resultado);
			numUno = 0,
      		numDos = 0;
			posicion=0;
			break;
		case '*':
			numUno = (resultado != 0 ? resultado : numUno);
			lcd.setCursor(posicion,0);
			lcd.print("*");
			posicion++;
			numDos = SegundoNumero();
			resultado = numUno * numDos;
			lcd.setCursor(1,1);
			lcd.print(resultado);
      		numUno = 0;
      		numDos = 0;
			posicion=0;
			break;
		case '/':
			numUno = (resultado != 0 ? resultado : numUno);
			lcd.setCursor(posicion,0);
			lcd.print("/");
			posicion++;
			numDos = SegundoNumero(); lcd.setCursor(1,1);
			numDos == 0 ? lcd.print("Error") : resultado = (float)numUno / (float)numDos;
			lcd.print(resultado);
			numUno = 0,
			numDos = 0;
			posicion=0;
			break;
		case 'C':
			resultado = 0;
			numUno = 0;
      		numDos = 0;
			posicion = 0;
			lcd.clear();
			break; 
    }
}

long SegundoNumero() 
{
	while( 1 ) 
    {
      tecla = customKeypad.getKey();

      if(tecla >= '0' && tecla <= '9') 
      {
        numDos = numDos * 10 + (tecla - '0');
      	lcd.setCursor(posicion,0);
      	lcd.print(numDos); 
      }

      if(tecla == 'C') 
      {
        resultado = 0;
        numUno = 0;
        numDos = 0;
        posicion = 0;
        lcd.clear();
        break; 
      }

      if(tecla == '=')
      {
        lcd.setCursor(0,1);
        lcd.print("=");
        posicion = resultado;
        lcd.clear();
        lcd.setCursor(0,1);
        lcd.print("=");
        break; 
      }
	}
return numDos;
}
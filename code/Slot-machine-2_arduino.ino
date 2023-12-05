//      ▂▃▄▅▆▇█▓▒░SLOT MACHINE░▒▓█▇▆▅▄▃▂  
//  
//     Progetto ideato e realizzato da Emilio Tulli
//
//  Realizzazione di una slot machine utilizzando display a
//   7 segmenti, display lcd 16x2 e registri a scorrimento
//
//  collegmento primo integrato:(fili arancioni)
//
//  pin 1) segmento b del primo display a 7 segmenti
//  pin 2) segmento c 
//  pin 3) segmento d
//  pin 4) segmento e
//  pin 5) segmento f
//  pin 6) segmento g
//  pin 7) vuoto
//  pin 8) gnd
//  pin 9) vuoto
//  pin 10) vcc
//  pin 11) pin 2 di arduino
//  pin 12) pin A1 di arduino
//  pin 13) gnd
//  pin 14) pin A0 di arduino
//  pin 15) segmento a
//  pin 16) vcc
//
//  collegamento secondo integrato:(fili gialli)
//
//  uguale al precedente tranne i pin 11 12 e 14
//
//  pin 11) pin 5 di arduino
//  pin 12) pin 4 di arduino
//  pin 14) pin 3 di arduino
//
//  collegamento terzo integrato:(fili verdi)
//  
//  uguale al precedente tranne i pin 11 12 e 14
//
//  pin 11) pin 8 di arduino
//  pin 12) pin 7 di arduino
//  pin 14) pin 6 di arduino
//
//  collegamento quarto integrato:(fili azzurri)
//
//  uguale al precedente tranne i pin 11 12 e 14
//
//  pin 11) pin 11 di arduino
//  pin 12) pin 10 di arduino
//  pin 14) pin 9 di arduino
//
//  
//  collegare il pulsante al pin 12 di arduino
//
//  collegare il terzo e l'ottavo pin al gnd su tutti i display a 7 segmenti
//
//  collegamenti display lcd:
//
//  pin RS al pin 12 di arduino
//  pin Enable al pin 11 di aruino
//  pin D4 al pin 5 di aruino
//  pin D5 al pin 4 di aruino
//  pin D6 al pin 3 di aruino
//  pin D7 al pin 2 di aruino
//  pin R/W a gnd
//  pin VSS a gnd
//  pin VCC a vcc
//
//  collegamento potenziometro:
//
//  estremità vcc e gnd
//  morsetto centrale al pin VO del display (pin 3)
//
//      ▂▃▅▆▇█ █ █ █ █ █ █ █ █ █ █ █ █▇▆▅▃▂



//includo la libreria per il display
#include <LiquidCrystal.h>

//inizializzo la libreria dicendo su quali pin è collegato il display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void jackpot(){//subroutine per quando si fa jackpot
lcd.begin(16, 2);//imposto il numero di righe e colonne
  lcd.print("    jackpot!");//scrivo il messaggio sul display usando gli spazi per centrarlo
  delay(500);// aspetto nezzo secondo
}

void ritenta (){//subroutine per quando si perde
  lcd.begin(16, 2);//imposto il numero di righe e colonne
  lcd.print(" ritenta sarai                           piu fortunato");//scrivo il messaggio sul display usando gli spazi per centrarlo
  delay(500);
}  



void setup() {
  
  Serial.begin(9600);//inizializzo la porta seriale
  
}

void loop() {   
  
//  lcd.clear();//cancella tutto sul display lcd e posiziona il cursore il alto a sinistra
  delay(1000);//aspetto 10 secondi
  
int val = digitalRead(6);//controllo lo stato del pin e lo assegno a una variabile
  
  if(val == LOW){//se il pin ha valore logico basso 
    
    ritenta();//eseguo la subroutine ritenta
    Serial.write("ritenta");//scrivo ritenta sulla porta seriale
  
  }
  
int val2 = digitalRead(9);//controllo lo stato del pin e lo assegno a una variabile
  
  if(val2 == HIGH){//se il pin ha valore logico alto
  
    jackpot();//esegue la subroutine jackpot
    Serial.write("jackpot");//scrivo jackpot sulla porta seriale
  
  }  
} 

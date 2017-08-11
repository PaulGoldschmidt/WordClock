/**
 * EINSTELLUNGEN WORDCLOCK MASTER SKETCH - WORKSHOP EDITION
 * 
 * copyright 2017 Paul Goldschmidt
 * 
 * 
 * ............................................................
 * Einstellungen für:
 *    
 *    - Nachtabschaltung          (Part #1)
 *    - RTC-Modul                 (Part #2)
 *    - DCF77-Modul               (Part #3)
 *    - Debugging-Einstellungen   (Part #4)
 *    - LED-Einstellungen         (Part #5)
 *    - Effekte                   (Part #6)
 *    -
 *    -
 */
//--------------------------------
/*
 * ------------------------------------------------------------
 *                           PART 1
 *                      NACHTABSCHALTUNG
 * ------------------------------------------------------------
 * 
 * Hier kannst du die Nachtabschaltung an oder aus schalten.
 * Wenn du sie an machst, geht die Uhr nach einer bestimmten
 * Uhrzeit aus und nach einer zweiten defenierbaren Uhrzeit
 * wieder an.
 */
//#include "dcf77.h";
 // Geb zuerst an, ob die Nachtabschaltung aktiviert werden soll oder nicht. (0 = aus | 1 = an)
 const int NightTurnOff_Activated = 0;
    
    // Wenn Nachtabschaltung an:
    // Gebe die Uhrzeit im 24-Stunden format an.
    const int NightTurnOff = 23;

    // Und hier wann die Uhr wieder an gehen soll. (Auch im 24 Stunden Format!)
    const int NightTurnOn = 5;
// -----------------------------------------------------------------------------
// Ende Part 1


/*
 * ------------------------------------------------------------
 *                           PART 2
 *                         RTC-Modul
 * ------------------------------------------------------------
 * 
 * Hier die Einstellungen für das RTC-Modul (Real-Time-Clock).
 * Dieses Modul braucht jede WordClock!
 * Du musst auf einem ATMega 2560 PRO den Pin 20 (SDA) und 
 * den Pin 21 (SCL) verwenden.  
 * Auf dem ATMega 2560-Entwicklungsbord gibt es extra SDA und SCL Pins.
 * ACHTUNG!
 * Du darfst an diesen Pins keine LED-Stripes anschliessen.
 * 
 * Ich empfehle als RTC-Modul ein ds1307 RTC Modul.
 * Das hat bisher immer sehr gut funkioniert.
 */
// -----------------------------------------------------------------------------
// Ende Part 2  


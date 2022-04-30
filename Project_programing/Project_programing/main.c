/*! \mainpage Projekt podstawy programowania 2 - Książka telefoniczna
 *
 * \section Opis
 *
 * Celem naszego projektu było opracowanie książki telefonicznej.  Każdy wpis w książce telefonicznej powinien posiadać takie dane jak Id, nazwisko, imię, ulica, numer domu/mieszkania, kod pocztowy ,miasto, numer telefonu. Udało nam się zawrzeć wszystkie te dane w pojedynczej strukturze:
 *
 * 
 *contact_struct:
 * 
 * unsigned int id
 * 
 * char name [30]
 * 
 * char surname [30]
 * 
 * adress_struct
 * 
 * char street [30]
 * 
 * short int number
 * 
 * char postal_code [8]
 * 
 * char city [30]
 * 
 * char phone_number [11]
 * 
 * 
 * 
 * książę
 * Jako strukturę danych do przechowywania wszystkich kontaktów opracowaliśmy dwukierunkową listę ze wskaźnikami na początek i koniec listy, dzięki czemu później można było przyspieszyć działanie części operacji.
 *
 * Książka telefoniczna miała także umożliwiać sortowanie według określonego elementu wpisu w książce telefonicznej. Jako algorytm sortowania wybraliśmy sortowanie typu mergesort, w nim też opracowaliśmy porównywanie dwóch elementów zależne od wskaźnika na funkcję, dzięki czemu w łatwy sposób można zmienić, według którego parametru program ma sortować książkę, Aby nie musieć sortować dwa wyrazy tablicy raz rosnąco, a raz malejąco wykorzystaliśmy  obecność dwóch wskaźników jeden na początku i jeden na końcu do wypisywania listy w kolejności odwrotnej.
 *
 * w przypadku dodawania elementów do książki telefonicznej opracowaliśmy funkcja pozwalająca na wygenerowanie najmniejszego unikatowego numeru id i przypisanie go do nowo utworzonego elementu. Dzięki takiemu rozwiązaniu nie ma później problemu z wyborem elementu po ID do edycji lub usunięcia.
 *
 * Wyszukiwanie elementów opracowaliśmy poprzez tworzenie tymczasowej listy, do której zostaje skopiowane elementy spełniające warunek wyszukiwania. Porównanie elementów jak przy sortowaniu listy zostało uzależnione od wskaźnika na funkcję, dzięki czemu można przeszukać książkę po różnych elementach wpisu.
 *
 * Ostatnim aspektem książki telefonicznej jest możliwość zapisu i odczytu danych z pliku. Jako folder gdzie będą przechowywane dane o książce telefonicznej utworzyliśmy folder “phone_data” a jako format pliku utworzyły “.pbd”. Aby ułatwić użytkownikowi wybierania pliku i uniknięcia próby otworzenia pliku, który nie istnieje wykorzystaliśmy bibliotek dirent.h do wyświetlenia listy plików w folderze phone_data i następnie możliwe wybrania numeru pliku i jego odtworzenia
 *
 *
 * Z wszystkimi naszymi celami udało nam się wykonać na pierwszy termin, dzięki czemu na drugi termin pozostało nam jedynie poprawienie ewentualnych błędów w programie czy też poprawnie błędów pisowni, a także opracowanie dokumentacji doxygen
 *
 *
 * \section autorzy
 *
 * Tomasz Bogdan
 * 
 * Maciej Cedzyński
 * 
 * Filip Borowiec
 * 
 * 
 *
 * 
 */

/**
 * @file main.c
 * @author Tomasz Bogdan, Maciej Cedzyński, Filip Borowiec
 * @brief plik ten zawiera funkcje main aktywująca główny program * @version 0.1
 * @date 2022-03-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */




#include <stdio.h>
#include "phone_book.h"

 /**
  * @brief funkcja main aktywująca główne działanie programu
  *
  * @return int
  */

int main()
{
	system("CHCP 1250 >NUL");
	start_ui();
	return 0;

}
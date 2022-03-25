/*! \mainpage Projekt podstawy programowania 2 - Książka telefoniczna
 *
 * \section Opis
 *
 * ...tresc...
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
 * @brief plik ten zaweira funkcje main aktywujaca głowny program
 * @version 0.1
 * @date 2022-03-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */




#include <stdio.h>
#include "phone_book.h"

/**
 * @brief funkjca main aaktyujaca glowne dzialanie programu
 * 
 * @return int 
 */
int main()
{
	system("CHCP 1250 >NUL");
	start_ui();
	return 0;

}
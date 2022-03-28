/*! \mainpage Projekt podstawy programowania 2 - Książka telefoniczna
 *
 * \section Opis
 *
 * Program umożliwia tworzenie otwieranie i zarządzanie książką telefoniczną
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
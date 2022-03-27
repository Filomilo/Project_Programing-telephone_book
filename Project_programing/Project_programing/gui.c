#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "phone_book.h"
#include <stdio.h>
#include <math.h>



#define SCROLL_SPEED 20

#define SCREEN_H 720
#define SCREEN_W 1280
#define ROW_H 40
#define UPPER_H 50
#define ELEMENT_H 30

#define ID_W 50
#define NAME_W 250
#define STREET_W 250
#define NR_W 40
#define POSTAL_W 80
#define CITY_W 250
#define PHONE_W (SCREEN_W-CITY_W-POSTAL_W-NR_W-STREET_W-NAME_W-NAME_W-ID_W)

int upper_menu_cliciing(ALLEGRO_DISPLAY* display, ALLEGRO_MOUSE_STATE mouse)
{
	 int buttoon_state=0;
	ALLEGRO_FONT* font = al_load_ttf_font("arial.ttf", 25, 0);
		ALLEGRO_COLOR white = al_map_rgb(255, 255, 255);
		ALLEGRO_COLOR highlight_color = al_map_rgb(255, 0, 0);
	al_set_target_backbuffer(display);
	int Theight = al_get_font_line_height(font);

	int line_width = 3;

	//ID
	int prev_width_block = 0;
	int width_block = ID_W;
	if (mouse.x > prev_width_block && mouse.x < prev_width_block + width_block && mouse.y < ROW_H + line_width)
	{
		al_draw_filled_rectangle(prev_width_block, 0, width_block + prev_width_block, UPPER_H, highlight_color);
		if (al_mouse_button_down(&mouse, 1))
		{
			buttoon_state = 1;

		}
	}
	al_draw_rectangle(prev_width_block, 0, width_block + prev_width_block, UPPER_H, white, line_width);
	char txt[40] = "id";
	float Twidth = al_get_text_width(font,txt);
	al_draw_text(font, white, width_block /2 - Twidth / 2 + prev_width_block, ROW_H / 2  - Theight/3, 0, txt);


	//NAME
	prev_width_block += width_block;
	 width_block = NAME_W*2;
	 if (mouse.x > prev_width_block && mouse.x < prev_width_block + width_block && mouse.y < ROW_H + line_width)
	 {
		 al_draw_filled_rectangle(prev_width_block, 0, width_block + prev_width_block, UPPER_H, highlight_color);
		 if (al_mouse_button_down(&mouse, 1))
		 {
			 buttoon_state = 2;

		 }
	 }
	al_draw_rectangle(prev_width_block, 0, width_block+ prev_width_block, UPPER_H, white, line_width);
	strncpy_s(txt, 40, "imie", 40);
	 Twidth = al_get_text_width(font, txt);
	al_draw_text(font, white, width_block /2 + prev_width_block -Twidth/2, ROW_H / 2 - Theight / 3, 0, txt);


	/*
	//SURNAME
	prev_width_block += width_block;
	width_block = NAME_W;
	if (mouse.x > prev_width_block && mouse.x < prev_width_block + width_block && mouse.y < ROW_H + line_width)
	{
		al_draw_filled_rectangle(prev_width_block, 0, width_block + prev_width_block, UPPER_H, highlight_color);
		if (al_mouse_button_down(&mouse, 1))
		{
			buttoon_state = 3;

		}
	}
	al_draw_rectangle(prev_width_block, 0, width_block + prev_width_block, UPPER_H, white, line_width);
	strncpy_s(txt, 40, "nazwisko", 40);
	Twidth = al_get_text_width(font, txt);
	al_draw_text(font, white, width_block / 2 + prev_width_block - Twidth / 2, ROW_H / 2 - Theight / 3, 0, txt);

	*/

	//STREET
	prev_width_block += width_block;
	width_block = STREET_W;
	if (mouse.x > prev_width_block && mouse.x < prev_width_block + width_block && mouse.y < ROW_H + line_width)
	{
		al_draw_filled_rectangle(prev_width_block, 0, width_block + prev_width_block, UPPER_H, highlight_color);
		if (al_mouse_button_down(&mouse, 1))
		{
			buttoon_state = 3;

		}
	}
	al_draw_rectangle(prev_width_block, 0, width_block + prev_width_block, UPPER_H, white, line_width);
	strncpy_s(txt, 40, "ulica", 40);
	Twidth = al_get_text_width(font, txt);
	al_draw_text(font, white, width_block / 2 + prev_width_block - Twidth / 2, ROW_H / 2 - Theight / 3, 0, txt);



	//HOUSE NUMBER
	prev_width_block += width_block;
	width_block = NR_W;
	if (mouse.x > prev_width_block && mouse.x < prev_width_block + width_block && mouse.y < ROW_H + line_width)
	{
		al_draw_filled_rectangle(prev_width_block, 0, width_block + prev_width_block, UPPER_H, highlight_color);
		if (al_mouse_button_down(&mouse, 1))
		{
			buttoon_state = 4;

		}
	}
	al_draw_rectangle(prev_width_block, 0, width_block + prev_width_block, UPPER_H, white, line_width);
	strncpy_s(txt, 40, "nr.", 40);
	Twidth = al_get_text_width(font, txt);
	al_draw_text(font, white, width_block / 2 + prev_width_block - Twidth / 2, ROW_H / 2 - Theight / 3, 0, txt);

	//POSTAL CODE
	prev_width_block += width_block;
	width_block = POSTAL_W;
	if (mouse.x > prev_width_block && mouse.x < prev_width_block + width_block && mouse.y < ROW_H + line_width)
	{
		al_draw_filled_rectangle(prev_width_block, 0, width_block + prev_width_block, UPPER_H, highlight_color);
		if (al_mouse_button_down(&mouse, 1))
		{
			buttoon_state = 5;

		}
	}
	al_draw_rectangle(prev_width_block, 0, width_block + prev_width_block, UPPER_H, white, line_width);
	strncpy_s(txt, 40, "poczta", 40);
	Twidth = al_get_text_width(font, txt);
	al_draw_text(font, white, width_block / 2 + prev_width_block - Twidth / 2, ROW_H / 2 - Theight / 3, 0, txt);



	//CITY
	prev_width_block += width_block;
	width_block = CITY_W;
	if (mouse.x > prev_width_block && mouse.x < prev_width_block + width_block && mouse.y < ROW_H + line_width)
	{
		al_draw_filled_rectangle(prev_width_block, 0, width_block + prev_width_block, UPPER_H, highlight_color);
		if (al_mouse_button_down(&mouse, 1))
		{
			buttoon_state = 6;

		}
	}
	al_draw_rectangle(prev_width_block, 0, width_block + prev_width_block, UPPER_H, white, line_width);
	strncpy_s(txt, 40, "miasto", 40);
	Twidth = al_get_text_width(font, txt);
	al_draw_text(font, white, width_block / 2 + prev_width_block - Twidth / 2, ROW_H / 2 - Theight / 3, 0, txt);



	//NUMer telefonu
	prev_width_block += width_block;
	width_block = PHONE_W;
	if (mouse.x > prev_width_block && mouse.x < prev_width_block + width_block && mouse.y < ROW_H + line_width)
	{
		al_draw_filled_rectangle(prev_width_block, 0, width_block + prev_width_block, UPPER_H, highlight_color);
		if (al_mouse_button_down(&mouse, 1))
		{
			buttoon_state = 7;

		}
	}
	al_draw_rectangle(prev_width_block, 0, width_block + prev_width_block, UPPER_H, white, line_width);
	strncpy_s(txt, 40, "telefon", 40);
	Twidth = al_get_text_width(font, txt);
	al_draw_text(font, white, width_block / 2 + prev_width_block - Twidth / 2, ROW_H / 2 - Theight / 3, 0, txt);
	
		al_destroy_font(font);
		return buttoon_state;
}

int upper_menu(ALLEGRO_DISPLAY* display, ALLEGRO_MOUSE_STATE mouse)
{
	al_draw_filled_rectangle(0, 0, SCREEN_W, UPPER_H, al_map_rgb(0, 0, 0));
	static int button = 0;
	static int button_prev = 0;
	button = upper_menu_cliciing(display, mouse);
	int ret = 0;
	ret = 0;
	if (button == 0 && button_prev!=button)
	{
		ret = button_prev;
	}

	button_prev = button;
	return ret;
}

ALLEGRO_BITMAP* genrarate_bitamp_list(list_pointers list)
{
	int counter = count_elements(list);
	ALLEGRO_BITMAP* bitmap;
	bitmap = al_create_bitmap(SCREEN_W, ROW_H * counter);
	al_set_target_bitmap(bitmap);
	ALLEGRO_FONT* font = al_load_ttf_font("arial.ttf", 15, 0);
	ALLEGRO_COLOR white = al_map_rgb(0, 255, 255);
	ALLEGRO_COLOR highlight_color = al_map_rgb(255, 0, 0);
	int Theight = al_get_font_line_height(font);
	int line_width = 2;
	char txt[40] = "";
	
	float Twidth = 0;
	int prev_width_block = 0;
	int width_block = ID_W;
	for (int i = 0; i < counter-1; i++)
	{
		//ID
		 prev_width_block = 0;
		 width_block = ID_W;
		al_draw_rectangle(prev_width_block, 0 + i * ELEMENT_H, width_block + prev_width_block, ELEMENT_H + i * ELEMENT_H, white, line_width);
		//strncpy_s(txt, 40, list.head->data, 40);
		sprintf_s(txt, 40, "%d", list.head->data.id);
		 Twidth = al_get_text_width(font, txt);
		al_draw_text(font, white, width_block / 2 - Twidth / 2 + prev_width_block, ELEMENT_H / 2 - Theight / 3 + i * ELEMENT_H, 0, txt);

		
		//NAME
		prev_width_block += width_block;
		width_block = NAME_W;
		al_draw_rectangle(prev_width_block, 0 + i * ELEMENT_H, width_block + prev_width_block, ELEMENT_H + i * ELEMENT_H, white, line_width);
		strncpy_s(txt, 40, list.head->data.name, 40);
		Twidth = al_get_text_width(font, txt);
		al_draw_text(font, white, width_block / 2 + prev_width_block - Twidth / 2, ELEMENT_H / 2 - Theight / 3 + i * ELEMENT_H, 0, txt);



		//SURNAME
		prev_width_block += width_block;
		width_block = NAME_W;
		al_draw_rectangle(prev_width_block, 0 + i * ELEMENT_H, width_block + prev_width_block, ELEMENT_H + i * ELEMENT_H, white, line_width);
		strncpy_s(txt, 40, list.head->data.surname, 40);
		Twidth = al_get_text_width(font, txt);
		al_draw_text(font, white, width_block / 2 + prev_width_block - Twidth / 2, ELEMENT_H / 2 - Theight / 3 + i * ELEMENT_H, 0, txt);



		//STREET
		prev_width_block += width_block;
		width_block = STREET_W;
		al_draw_rectangle(prev_width_block, 0 + i * ELEMENT_H, width_block + prev_width_block, ELEMENT_H + i * ELEMENT_H, white, line_width);
		strncpy_s(txt, 40, list.head->data.adress.street, 40);
		Twidth = al_get_text_width(font, txt);
		al_draw_text(font, white, width_block / 2 + prev_width_block - Twidth / 2, ELEMENT_H / 2 - Theight / 3 + i * ELEMENT_H, 0, txt);



		//HOUSE NUMBER
		prev_width_block += width_block;
		width_block = NR_W;
		al_draw_rectangle(prev_width_block, 0 + i * ELEMENT_H, width_block + prev_width_block, ELEMENT_H + i * ELEMENT_H, white, line_width);
		sprintf_s(txt, 40, "%d", list.head->data.adress.number);
		Twidth = al_get_text_width(font, txt);
		al_draw_text(font, white, width_block / 2 + prev_width_block - Twidth / 2, ELEMENT_H / 2 - Theight / 3 + i * ELEMENT_H, 0, txt);

		//POSTAL CODE
		prev_width_block += width_block;
		width_block = POSTAL_W;
		al_draw_rectangle(prev_width_block, 0 + i * ELEMENT_H, width_block + prev_width_block, ELEMENT_H + i * ELEMENT_H, white, line_width);
		strncpy_s(txt, 40, list.head->data.adress.postal_code, 40);
		Twidth = al_get_text_width(font, txt);
		al_draw_text(font, white, width_block / 2 + prev_width_block - Twidth / 2, ELEMENT_H / 2 - Theight / 3 + i * ELEMENT_H, 0, txt);



		//CITY
		prev_width_block += width_block;
		width_block = CITY_W;
		al_draw_rectangle(prev_width_block, 0 + i * ELEMENT_H, width_block + prev_width_block, ELEMENT_H + i * ELEMENT_H, white, line_width);
		strncpy_s(txt, 40, list.head->data.adress.city, 40);
		Twidth = al_get_text_width(font, txt);
		al_draw_text(font, white, width_block / 2 + prev_width_block - Twidth / 2, ELEMENT_H / 2 - Theight / 3 + i * ELEMENT_H, 0, txt);



		//NUMer telefonu
		prev_width_block += width_block;
		width_block = PHONE_W;
		al_draw_rectangle(prev_width_block, 0+i* ELEMENT_H, width_block + prev_width_block, ELEMENT_H+i* ELEMENT_H, white, line_width);
		strncpy_s(txt, 40, list.head->data.phone_number, 40);
		Twidth = al_get_text_width(font, txt);
		al_draw_text(font, white, width_block / 2 + prev_width_block - Twidth / 2, ELEMENT_H / 3 - Theight / 3 + i * ELEMENT_H, 0, txt);


		list.head = list.head->prev;
	}
	//printf("press\n");
	//getchar();
	al_destroy_font(font);
	
	return bitmap;
}




void draw_list_scroll(ALLEGRO_DISPLAY* display,  ALLEGRO_BITMAP* bitmap, int scroll, int selected)
{
	al_set_target_backbuffer(display);
	al_draw_bitmap_region(bitmap, 0, scroll, SCREEN_W, SCREEN_H, 0, UPPER_H, 0);
	if(selected>=0)
	al_draw_rectangle(0, UPPER_H + ELEMENT_H * selected-scroll , SCREEN_W,  UPPER_H + ELEMENT_H * selected-scroll+ELEMENT_H, al_map_rgb(0, 255, 25), 5);

}


void draw_element(list_node* element, int selected)
{
	ALLEGRO_FONT* font = al_load_ttf_font("arial.ttf", 40, 0);
	ALLEGRO_COLOR white = al_map_rgb(255, 255, 255);
	al_draw_textf(font, white, 10, 50, 0, "Imie:");
	al_draw_text(font, white, 300, 50, 0, element->data.name);

	al_draw_textf(font, white, 10, 100, 0, "Nazwisko:");
	al_draw_text(font, white, 300, 100, 0, element->data.surname);

	al_draw_textf(font, white, 10, 150, 0, "Nr:");
	al_draw_textf(font, white, 300, 150, 0, "%d", element->data.adress.number);

	al_draw_textf(font, white, 10, 200, 0, "Kod pocztowy:");
	al_draw_text(font, white, 300, 200, 0, element->data.adress.postal_code);

	al_draw_textf(font, white, 10, 250, 0, "Miasto:");
	al_draw_text(font, white, 300, 250, 0, element->data.adress.city);

	al_draw_textf(font, white, 10, 300, 0, "Numer telefonu:");
	al_draw_text(font, white, 300, 300, 0, element->data.phone_number);
	

	


	al_draw_line(10, 100 + selected * 50, 700, 100 + selected * 50, white, 2);

	al_destroy_font(font);


}


void manage_elemnt(list_node* element)
{


	
	ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);
	ALLEGRO_KEYBOARD_STATE key;
	ALLEGRO_EVENT_QUEUE *event=al_create_event_queue();
	ALLEGRO_EVENT ev;
	char txt[50] = "";
	
	strncpy_s(txt, 30, element->data.name, 30);
	int sel = 0;
	int psel = 0;

	int telement = strlen(txt);
	al_register_event_source(event, al_get_keyboard_event_source());
	while (1)
	{








		al_get_keyboard_state(&key);
		if (al_key_down(&key, ALLEGRO_KEY_DOWN) || al_key_down(&key, ALLEGRO_KEY_ENTER))
		{
			sel = (sel + 1) % 6;
			al_rest(0.2);
		}
		if (al_key_down(&key, ALLEGRO_KEY_UP))
		{
			sel = (sel - 1) < 0 ? 5 : sel - 1;
			al_rest(0.2);
		}



		if (sel != psel)
			switch (sel)
			{
			case 0:   strncpy_s(txt, 30, element->data.name, 30); telement = strlen(txt); break;
			case 1:  strncpy_s(txt, 30, element->data.surname, 30); telement = strlen(txt); break;
			case 2:  strncpy_s(txt, 30, element->data.surname, 30); telement = strlen(txt); break;
			//case 3:  strncpy_s(txt, 7, element->data.adress.postal_code, 7); telement = strlen(txt); break;
			case 4:  strncpy_s(txt, 20, element->data.adress.city, 20); telement = strlen(txt); break;
			case 5:  strncpy_s(txt, 30, element->data.phone_number, 10); telement = strlen(txt); break;
			}



		al_get_next_event(event, &ev);
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN && telement<20 && !(sel==2 && telement<=3) && !(sel == 5 && telement <= 10))
		{
			printf("%d\n", ev.keyboard.keycode);
			if (ev.keyboard.keycode < 26)
			{
				txt[telement] = ev.keyboard.keycode + 96;
				telement += 1;
				txt[telement] = '\0';
			}
			if (ev.keyboard.keycode >27 && ev.keyboard.keycode<46)
			{
				txt[telement] = (ev.keyboard.keycode  -27)%10+48;
				telement += 1;
				txt[telement] = '\0';
			}
			if (ev.keyboard.keycode ==ALLEGRO_KEY_BACKSPACE && telement>0)
			{

				telement -= 1;
				txt[telement] = '\0';
			}

			
			
			
		}




		switch (sel)
		{
		case 0:   strncpy_s(element->data.name, 30, txt, 30);  break;
		case 1:  strncpy_s(element->data.surname, 30, txt, 30);  break;
		case 2:  strncpy_s(element->data.surname, 30, txt, 30);  break;
		case 3:  strncpy_s(element->data.adress.postal_code, 30, txt, 30);  break;
		case 4:  strncpy_s(element->data.adress.city, 30, txt, 30);  break;
		case 5:  strncpy_s(element->data.phone_number, 11, txt, 11);  break;
		}








		
		al_clear_to_color(black);
		draw_element(element, sel);
		al_flip_display();
		psel = sel;
		if (al_key_down(&key, ALLEGRO_KEY_ESCAPE))
			break;
	}
}


void draw_menu(ALLEGRO_DISPLAY* display, list_pointers list)
{
	ALLEGRO_FONT* font = al_load_ttf_font("arial.ttf", 20, 0);
	ALLEGRO_COLOR white = al_map_rgb(255, 255, 255);
	ALLEGRO_BITMAP* bitmap;
	ALLEGRO_MOUSE_STATE mouse;
	ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);
	bitmap = genrarate_bitamp_list(list);
	al_set_target_backbuffer(display);
	int sort_choice = 0;
	int scroll_limit = -al_get_bitmap_height(bitmap) + SCREEN_H * 2 - 2 * UPPER_H;// -2 * SCREEN_H + 2 * UPPER_H;
	while (1)
	{
		al_clear_to_color(black);
		al_get_mouse_state(&mouse);
		scroll_limit = -al_get_bitmap_height(bitmap) + SCREEN_H * 2 - 2 * UPPER_H;

		if (mouse.z > 0)
			al_set_mouse_z(0);
		if (mouse.z * SCROLL_SPEED <= scroll_limit)
			al_set_mouse_z(scroll_limit / SCROLL_SPEED);


		


		
		


		//opcja wyboru sortowanie
		sort_choice=upper_menu(display, mouse);
		switch (sort_choice)
		{
		case 1: al_destroy_bitmap(bitmap); list = merge_sort(list, id_cmp); bitmap = genrarate_bitamp_list(list); break;
		case 2: al_destroy_bitmap(bitmap); list = merge_sort(list,	name_cmp); bitmap = genrarate_bitamp_list(list); break;
		case 3: al_destroy_bitmap(bitmap); list = merge_sort(list, street_cmp); bitmap = genrarate_bitamp_list(list); break;
		case 4: al_destroy_bitmap(bitmap); list = merge_sort(list, number_cmp); bitmap = genrarate_bitamp_list(list); break;
		case 5: al_destroy_bitmap(bitmap); list = merge_sort(list, postal_code_cmp); bitmap = genrarate_bitamp_list(list); break;
		case 6: al_destroy_bitmap(bitmap); list = merge_sort(list, city_cmp); bitmap = genrarate_bitamp_list(list); break;
		case 7: al_destroy_bitmap(bitmap); list = merge_sort(list, number_cmp); bitmap = genrarate_bitamp_list(list); break;
		}






		//selction of element
		int sel_elem = (mouse.y - UPPER_H + -mouse.z * SCROLL_SPEED) / ELEMENT_H;
		if (mouse.y < UPPER_H)
			sel_elem = -1;
		printf("%d\n", sel_elem);



		//clicing elemnr
		if (al_mouse_button_down(&mouse, 1))
		{
			if (sel_elem >= 0);
			al_set_target_backbuffer(display);
			manage_elemnt(select_num_node(list, sel_elem));
			al_destroy_bitmap(bitmap); list = merge_sort(list, id_cmp); bitmap = genrarate_bitamp_list(list);
			al_set_mouse_z(0);
			al_rest(0.2);
		}



		draw_list_scroll(display, bitmap, -mouse.z * SCROLL_SPEED, sel_elem);


		

		al_flip_display();
		
	}

	
}




void start_gui()
{
	ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);
	ALLEGRO_DISPLAY* display;
	al_init();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_mouse();
	al_install_keyboard();
	display = al_create_display(SCREEN_W, SCREEN_H);

	list_pointers list;
	list = load("123");
	//print_list_head(list);
	manage_elemnt(list.tail);
	//draw_menu(display, list);
	/*
	ALLEGRO_MOUSE_STATE mouse;
	while (1){
		al_get_mouse_state(&mouse);
	printf("%d\n",upper_menu(display, mouse));
	
	al_flip_display();
	al_clear_to_color(black);
}
	getchar();
	*/
	//getchar();
	al_destroy_display(display);

}
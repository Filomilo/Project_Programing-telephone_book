#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "phone_book.h"
#include <stdio.h>
#include <math.h>





#define SCREEN_H 720
#define SCREEN_W 1280
#define ROW_H 40
#define UPPER_H 50

#define ID_W 50
#define NAME_W 250
#define STREET_W 250
#define NR_W 40
#define POSTAL_W 80
#define CITY_W 250
#define PHONE_W (SCREEN_W-CITY_W-POSTAL_W-NR_W-STREET_W-NAME_W-NAME_W-ID_W)

int upper_menu(ALLEGRO_DISPLAY* display, ALLEGRO_MOUSE_STATE mouse)
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
	 width_block = NAME_W;
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



	//STREET
	prev_width_block += width_block;
	width_block = STREET_W;
	if (mouse.x > prev_width_block && mouse.x < prev_width_block + width_block && mouse.y < ROW_H + line_width)
	{
		al_draw_filled_rectangle(prev_width_block, 0, width_block + prev_width_block, UPPER_H, highlight_color);
		if (al_mouse_button_down(&mouse, 1))
		{
			buttoon_state = 4;

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
			buttoon_state = 5;

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
			buttoon_state = 6;

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
			buttoon_state = 7;

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
			buttoon_state = 8;

		}
	}
	al_draw_rectangle(prev_width_block, 0, width_block + prev_width_block, UPPER_H, white, line_width);
	strncpy_s(txt, 40, "telefon", 40);
	Twidth = al_get_text_width(font, txt);
	al_draw_text(font, white, width_block / 2 + prev_width_block - Twidth / 2, ROW_H / 2 - Theight / 3, 0, txt);
	
		al_destroy_font(font);
		return buttoon_state;
}




void draw_menu(ALLEGRO_DISPLAY* display, list_pointers list)
{
	ALLEGRO_FONT *font = al_load_ttf_font("arial.ttf", 20,0);
	ALLEGRO_COLOR white = al_map_rgb(255, 255, 255);
	int counter = count_elements(list);
	printf("ELEMNetTS: %d", counter);
	ALLEGRO_BITMAP* bitmap;
	bitmap = al_create_bitmap(SCREEN_W, ROW_H*counter);
	al_set_target_bitmap(bitmap);
	int font_height = al_get_font_line_height(font);

	int name_block_width= 200;
	for (int i = 0; i < counter; i++)
	{
		al_draw_rectangle(0, 0 + i * ROW_H, 40, ROW_H + i * ROW_H,white ,2);
		al_draw_rectangle(40, 0 + i * ROW_H, 200, ROW_H + i * ROW_H, white, 2);
		al_draw_text(font, white, 0, 0 + i * ROW_H+ font_height/2, 0, list.head->data.name);


	}
	al_set_target_backbuffer(display);
	al_draw_bitmap_region(bitmap, 0, 0, SCREEN_W, SCREEN_H, 0, 80, 0);

	al_flip_display();


	getchar();
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
	display = al_create_display(SCREEN_W, SCREEN_H);

	list_pointers list;
	list = load("test");
	print_list_head(list);

	//draw_menu(display, list);
	ALLEGRO_MOUSE_STATE mouse;
	while (1){
		al_get_mouse_state(&mouse);
	printf("%d\n",upper_menu(display, mouse));
	
	al_flip_display();
	al_clear_to_color(black);
}
	getchar();

	al_destroy_display(display);

}
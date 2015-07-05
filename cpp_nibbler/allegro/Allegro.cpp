/*
** vadee_s
*/

#include "Allegro.hh"

LibAllegro::LibAllegro()
{
}

LibAllegro::~LibAllegro()
{
  al_destroy_display(_display);
}

bool		LibAllegro::getFont(const char* filename, ALLEGRO_FONT **font)
{
  al_set_path_filename(_path, filename);
  *font = al_load_ttf_font(al_path_cstr(_path, '/'), CASE_SIZE, 0);
  if (!font)
    return false;
  return true;
}

bool		LibAllegro::getImage(const char *filename, ALLEGRO_BITMAP **image, int x, int y)
{
  ALLEGRO_BITMAP *loaded_bmp;
  ALLEGRO_BITMAP *prev_target;

  *image = al_create_bitmap(x, y);
  if (!*image)
    return NULL;
  al_set_path_filename(_path, filename);
  if (!(loaded_bmp = al_load_bitmap(al_path_cstr(_path, '/'))))
    {
      al_destroy_bitmap(*image);
      std::cerr << "Failed To load image from '" << filename << "'." << std::endl;
      return false;
    }
  prev_target = al_get_target_bitmap();
  al_set_target_bitmap(*image);
  al_draw_scaled_bitmap(loaded_bmp,
			0, 0,
			al_get_bitmap_width(loaded_bmp),
			al_get_bitmap_height(loaded_bmp),
			0, 0,
			x, y,
			0
			);
  al_set_target_bitmap(prev_target);
  al_destroy_bitmap(loaded_bmp);
  return true;
}

bool		LibAllegro::initGui(int x, int y)
{
  _display = NULL;
  x *= CASE_SIZE;
  y *= CASE_SIZE;
  if (!al_init())
    {
      std::cerr << "Failed To initialize Allegro" << std::endl;
      return false;
    }
  if (al_get_monitor_info(0, &_infos)
      && (x > _infos.x2
	  || y > _infos.y2))
    {
      std::cerr << "Failed to initialize map : size is too big" << std::endl;
      return false;
    }
  else if (!(_display = al_create_display(x, y)))
    {
     std::cerr << "Failed To initialize display" << std::endl;
     return false;
    }
  else if (!al_install_keyboard())
    {
      std::cerr << "Failed To initialize keyboard" << std::endl;
      return false;
    }
  else if (!al_init_image_addon())
    {
      std::cerr << "Failed To initialize images" << std::endl;
      return false;
    }
  al_init_font_addon();
  if (!al_init_ttf_addon())
    {
      std::cerr << "Failed To initialize font" << std::endl;
      return false;
    }
  else if (!(_path = al_get_standard_path(ALLEGRO_RESOURCES_PATH)))
    {
      std::cerr << "Failed To initialize path" << std::endl;
      return false;
    }
  al_clear_to_color(al_map_rgb(255, 255, 255));
  al_flip_display();
  al_append_path_component(_path, "allegro/ressources");
  if (!getImage("pomme.bmp", &_food_image, CASE_SIZE, CASE_SIZE)
      || !getImage("snake_head.png", &_snake_head_image, CASE_SIZE, CASE_SIZE)
      || !getImage("game_over.png", &_game_over_image, x, y - CASE_SIZE)
      || !getImage("banane.bmp", &_food_image_speed, CASE_SIZE, CASE_SIZE)
      || !getImage("fraise.png", &_food_image_invert, CASE_SIZE, CASE_SIZE)
      || !getFont("Blazed.ttf", &font))
    return false;
  _event_queue = al_create_event_queue();
  if (!_event_queue)
    {
      std::cerr << "Failed To initialize event queue" << std::endl;
      return false;
    }

  al_register_event_source(_event_queue, al_get_keyboard_event_source());
  return true;
}

e_way		LibAllegro::getEvent()
{
  if (!al_get_next_event(_event_queue, &_event))
    return NOTHING;
  if (_event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
    return EXIT;
  else if (_event.type == ALLEGRO_EVENT_KEY_DOWN)
    {
      switch (_event.keyboard.keycode)
	{
	case ALLEGRO_KEY_ESCAPE:
	  return EXIT;
	case ALLEGRO_KEY_DOWN:
	  return DOWN;
	case ALLEGRO_KEY_UP:
	  return TOP;
	case ALLEGRO_KEY_LEFT:
	  return LEFT;
	case ALLEGRO_KEY_RIGHT:
	  return RIGHT;
	}
    }
  return NOTHING;
}


bool		LibAllegro::moveSnake(std::pair<unsigned int, unsigned int> from, std::pair<unsigned int, unsigned int> to, bool eat)
{
  if (!eat)
    al_draw_filled_rectangle(from.first * CASE_SIZE, from.second * CASE_SIZE, (from.first * CASE_SIZE) + CASE_SIZE, (from.second * CASE_SIZE) + CASE_SIZE, al_map_rgb(255, 255, 255));
  else
    al_draw_filled_rectangle(to.first * CASE_SIZE, to.second * CASE_SIZE, (to.first * CASE_SIZE) + CASE_SIZE, (to.second * CASE_SIZE) + CASE_SIZE, al_map_rgb(255, 255, 255));
  al_draw_bitmap(_snake_head_image, to.first * CASE_SIZE, to.second * CASE_SIZE, 0);
  al_flip_display();
  return true;
}

bool		LibAllegro::addItem(std::pair<int, int> from, e_itemType type)
{
  if (type == GROW)
    al_draw_bitmap(_food_image, from.first * CASE_SIZE, from.second * CASE_SIZE, 0);
  else if (type == SPEED)
    al_draw_bitmap(_food_image_speed, from.first * CASE_SIZE, from.second * CASE_SIZE, 0);
  else if (type == INVERT)
    al_draw_bitmap(_food_image_invert, from.first * CASE_SIZE, from.second * CASE_SIZE, 0);
  al_flip_display();
  return true;
}

void		LibAllegro::gameOver(size_t score)
{
  al_clear_to_color(al_map_rgb(255, 255, 255));
  al_draw_bitmap(_game_over_image, 0, 0, 0);
  al_draw_textf(font, al_map_rgb(255, 0, 0), al_get_display_width(_display) / 2, al_get_display_height(_display) - CASE_SIZE , ALLEGRO_ALIGN_CENTRE, "score : %lu.", score);
  al_flip_display();
  al_rest(3);
}

extern "C"
{
  LibAllegro	*getInstance()
  {
    return (new LibAllegro);
  }
}

/*
** vadee_s
*/

#ifndef ALLEGRO_H_
# define ALLEGRO_H_

# include <iostream>
# include <allegro5/allegro.h>
# include <allegro5/allegro_image.h>
# include <allegro5/allegro_primitives.h>
# include <allegro5/allegro_font.h>
# include <allegro5/allegro_ttf.h>
# include "IGui.hh"

# define CASE_SIZE 20

class			LibAllegro : public IGui
{

  private:

  ALLEGRO_DISPLAY	*_display;
  ALLEGRO_BITMAP	*_snake_head_image;
  ALLEGRO_BITMAP	*_food_image;
  ALLEGRO_BITMAP	*_food_image_speed;
  ALLEGRO_BITMAP	*_food_image_invert;
  ALLEGRO_BITMAP	*_game_over_image;
  ALLEGRO_EVENT_QUEUE	*_event_queue;
  ALLEGRO_EVENT		_event;
  ALLEGRO_PATH		*_path;
  ALLEGRO_FONT		*font;
  ALLEGRO_MONITOR_INFO	_infos;

  private:
  bool			getImage(const char *filename, ALLEGRO_BITMAP **image, int x, int y);
  bool			getFont(const char* filename, ALLEGRO_FONT **font);

public :
  LibAllegro();
  ~LibAllegro();
  e_way			getEvent();
  bool			initGui(int x, int y);
  bool			moveSnake(std::pair<unsigned int, unsigned int> from, std::pair<unsigned int, unsigned int> to, bool eat);
  bool			addItem(std::pair<int, int> from, e_itemType type);
  void			gameOver(size_t score);
};



#endif /* !ALLEGRO_H_ */

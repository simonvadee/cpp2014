//
// Correspondance.hh for plazza in /home/girard_r/Documents/plazza/classes/sources
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Tue Apr 21 16:05:32 2015 Aurélien GIRARDEAU
// Last update Tue Apr 21 16:05:33 2015 Aurélien GIRARDEAU
//

#ifndef CORRESPONDANCE_H_
# define CORRESPONDANCE_H_

# include <iostream>
# include <algorithm>
# include <map>
# include <deque>

enum	e_msgtype
  {
    ORDER = 1,
    ASK_STATE,
    ANSWER_STATE,
    ANSWER_COOK,
    END_ANSWER,
    CLOSE_KITCHEN,
    ORDER_COMPLETE
  };

enum	e_ingr
  {
    DOE = 1,
    TOMATO,
    GRUYERE,
    HAM,
    MUSHROOMS,
    STEAK,
    EGGPLANT,
    GOAT_CHEESE,
    CHIEF_LOVE,
    END
  };

enum	e_pizza
  {
    REGINA = 1,
    MARGARITA = 2,
    AMERICANA = 4,
    FANTASIA = 8
  };

enum	e_size
  {
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
  };

typedef struct			s_state
{
  e_msgtype			msg;
  int				ingr[9];
}				t_state;

typedef struct			s_pack
{
  e_msgtype			msg;
  e_pizza			pizza;
  e_size			size;
}				t_pack;

class							Correspondance
{
public:

  Correspondance();
  ~Correspondance();
  std::map<e_ingr, int>						makeReciepe(char const* ingr);
  e_pizza							getCodeFromName(std::string pizza);
  std::map<e_ingr, int>						getReciepeFromName(std::string pizza);
  useconds_t							getTimeFromName(std::string pizza);
  useconds_t							getTimeFromCode(e_pizza code);
  e_size							getSizeFromName(std::string pizza);
  std::string							getNameFromCode(e_pizza code);
  std::map<e_ingr, int>						getReciepeFromCode(e_pizza code);
  e_ingr							getIngrFromName(std::string name);
  std::string							getIngrFromCode(e_ingr code);
  std::string							getSizeFromCode(e_size code);


private:

  std::map<std::string, e_ingr>					_find_ingr;

  std::map<std::string, std::map<e_ingr, int> >			_find_reciepe;
  std::map<std::string, e_pizza>				_find_namecode;
  std::map<std::string, unsigned int>				_find_time;
  std::map<std::string, e_size>					_find_size;
};

#endif /* !CORRESPONDANCE_H_ */

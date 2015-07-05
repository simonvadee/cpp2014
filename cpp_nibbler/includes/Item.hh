//
// Item.hh for nibbler in /home/girard_r/rendu/cpp_nibbler
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Wed Mar 25 17:36:29 2015 Aurélien GIRARDEAU
// Last update Wed Mar 25 17:37:19 2015 Aurélien GIRARDEAU
//

#ifndef _CPP_NIBBLER_ITEM_HH_
# define _CPP_NIBBLER_ITEM_HH_

# include "IGui.hh"

class								Item
{
private:
  e_itemType							_type;
  std::pair<unsigned int, unsigned int>				_pos;

public:
  Item(e_itemType type, unsigned int x, unsigned int y);
  ~Item();
  std::pair<unsigned int, unsigned int>				getPos() const;
  e_itemType							getType() const;
};

#endif /*_CPP_NIBBLER_ITEM_HH_ */

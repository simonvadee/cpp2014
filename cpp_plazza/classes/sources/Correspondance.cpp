//
// Correspondance.cpp for plazza in /home/girard_r/Documents/plazza
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Tue Apr 21 15:34:53 2015 Aurélien GIRARDEAU
// Last update Wed Apr 22 13:19:37 2015 Aurélien GIRARDEAU
//

#include "Correspondance.hh"

Correspondance::Correspondance()
{
  _find_ingr["doe"] = DOE;
  _find_ingr["tomato"] = TOMATO;
  _find_ingr["gruyere"] = GRUYERE;
  _find_ingr["ham"] = HAM;
  _find_ingr["mushrooms"] = MUSHROOMS;
  _find_ingr["steack"] = STEAK;
  _find_ingr["eggplant"] = EGGPLANT;
  _find_ingr["goat cheese"] = GOAT_CHEESE;
  _find_ingr["chief love"] = CHIEF_LOVE;
  _find_reciepe["regina"] = makeReciepe("doe, tomato, gruyere");
  _find_reciepe["margarita"] = makeReciepe("doe, tomato, gruyere, ham, mushrooms");
  _find_reciepe["americana"] = makeReciepe("doe, tomato, gruyere, steak");
  _find_reciepe["fantasia"] = makeReciepe("doe, tomato, eggplant, goat cheese, chief love");
  _find_namecode["regina"] = REGINA;
  _find_namecode["margarita"] = MARGARITA;
  _find_namecode["americana"] = AMERICANA;
  _find_namecode["fantasia"] = FANTASIA;
  _find_time["regina"] = 1;
  _find_time["margarita"] = 2;
  _find_time["americana"] = 2;
  _find_time["fantasia"] = 4;
  _find_size["s"] = S;
  _find_size["m"] = M;
  _find_size["l"] = L;
  _find_size["xl"] = XL;
  _find_size["xxl"] = XXL;
}

Correspondance::~Correspondance()
{

}

e_ingr					Correspondance::getIngrFromName(std::string name)
{
  return _find_ingr[name];
}

std::map<e_ingr, int>			Correspondance::makeReciepe(char const *ingr)
{
  std::string				parse;
  std::map<e_ingr, int>			ret;
  std::size_t				found;
  std::size_t				start;
  std::size_t				find_q;
  int					quantity;
  std::string				key;

  parse = ingr;
  start = 0;
  found = 0;
  while (found != std::string::npos)
    {
      found = parse.find(',', start);
      key = parse.substr(start, found - start);
      if ((find_q = key.find(" x")) != std::string::npos)
	{
	  quantity = static_cast<int>(key[find_q + 2] - 48);
	  key.erase(key.size() - 3);
	}
      else
	quantity = 1;
      start = found + 2;
      ret[getIngrFromName(key)] = quantity;
    }
  return ret;
}



e_pizza					Correspondance::getCodeFromName(std::string pizza)
{
  std::transform(pizza.begin(), pizza.end(), pizza.begin(), ::tolower);
  return _find_namecode[pizza];
}

std::map<e_ingr, int>			Correspondance::getReciepeFromName(std::string pizza)
{
  std::transform(pizza.begin(), pizza.end(), pizza.begin(), ::tolower);
  return _find_reciepe[pizza];
}

std::map<e_ingr, int>			Correspondance::getReciepeFromCode(e_pizza code)
{
  return _find_reciepe[getNameFromCode(code)];
}

useconds_t				Correspondance::getTimeFromName(std::string pizza)
{
  std::transform(pizza.begin(), pizza.end(), pizza.begin(), ::tolower);
  return _find_time[pizza];
}

useconds_t				Correspondance::getTimeFromCode(e_pizza code)
{
  return _find_time[getNameFromCode(code)];
}

e_size					Correspondance::getSizeFromName(std::string pizza)
{
  std::transform(pizza.begin(), pizza.end(), pizza.begin(), ::tolower);
  return _find_size[pizza];
}

std::string				Correspondance::getNameFromCode(e_pizza code)
{
  for (std::map<std::string, e_pizza>::iterator	it = _find_namecode.begin(); it != _find_namecode.end(); ++it)
    {
      if (it->second == code)
	return it->first;
    }
  return "none";
}

std::string				Correspondance::getSizeFromCode(e_size code)
{
  for (std::map<std::string, e_size>::iterator	it = _find_size.begin(); it != _find_size.end(); ++it)
    {
      if (it->second == code)
	return it->first;
    }
  return "none";
}

std::string				Correspondance::getIngrFromCode(e_ingr code)
{
  for (std::map<std::string, e_ingr>::iterator	it = _find_ingr.begin(); it != _find_ingr.end(); ++it)
    {
      if (it->second == code)
	return it->first;
    }
  return "none";
}

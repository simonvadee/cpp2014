//
// myUnitTests.cpp for santa  in /home/theoph_t/cpp_santa/Sources/Main/Sources
//
// Made by Titouan Theophile
// Login   <theoph_t@epitech.net>
//
// Started on  Sun Jan 18 06:14:04 2015 Titouan Theophile
// Last update Sun Jan 18 08:33:55 2015 Titouan Theophile
//

#include "Teddy.hh"
#include "LittlePony.hh"

Object *MyUnitTests2(Object **array)
{
  bool err = false;

  std::cout << "\033[0;31m#### Begining of the test ####\033[0m" << std::endl;
  std::cout << "\tChecking the array given in parameter..." << std::endl;
  std::cout << "\t\t... array[0] = " << array[0]->getTitle() << "." << std::endl;
  if (array[0]->getType() != TOY)
    {
      err = true;
      std::cerr << "\t\033[1;35mERROR array[0] is not of type Toy\033[0m" << std::endl;
    }
  std::cout << "\t\t... array[1] = " << array[1]->getTitle() << "." << std::endl;
  if (array[1]->getType() != BOX)
    {
      err = true;
      std::cerr << "\t\033[1;35mERROR array[1] is not of type Box\033[0m"<< std::endl;
    }
  std::cout << "\t\t... array[2] = " << array[2]->getTitle() << "." << std::endl;
  if (array[2]->getType() != GIFTPAPER)
    {
      err = true;
      std::cerr << "\t\033[1;35mERROR array[2] is not of type GiftPaper\033[0m" << std::endl;
    }
  std::cout << "\t\t... array[3] = " << array[3] << "." << std::endl;
  if (array[3] != NULL)
    {
      std::cerr << "\t\033[1;35mERROR array[3] is not of NULL pointer" << std::endl;
    }
  std::cout << "\tAll Given parameters are correct !" << std::endl;
  std::cout << "\tInitializing gift wrapping..." << std::endl;
  std::cout << "\t\t...Moving the Toy into the Box" << std::endl;
  if (array[1]->wrapMeThat(array[0]) == false)
    {
      std::cerr << "\t\033[1;35mERROR : TOY is not stock in the box\033[0m" << std::endl;
      err = true;
    }
  std::cout << "\t\t...Wrapping the Box with the GiftPaper" << std::endl;
  if (array[2]->wrapMeThat(array[1]) == false)
    {
      std::cerr << "\t\033[1;35mERROR : Box is not wrap in the GiftPaper\033[0m";
      err = true;
    }
  if (err == false)
    std::cout << "\t\033[32mSUCCESS : the gift is correctly build ! \033[0m" << std::endl;
  std::cout << "\tReturning the array." << std::endl;
  std::cout << "\033[0;31m#### Ending of the test ####\033[0m" << std::endl;
  return array[2];
}


Object **MyUnitTests1()
{
  std::cout << "\033[0;31m#### Begining of the test ####\033[0m" << std::endl;
  std::cout << "\tcreation of the pointer to a Teddy class." << std::endl;
  Object *teddy = new Teddy("bisounours");
  std::cout << "\tcreation of the pointer to a LittlePony class." << std::endl;
  Object *pony = new LittlePony("gay pony");
  std::cout << "\tInitialisation of the array." << std::endl;
  Object **array = new Object*[3];
  std::cout << "\tChecking Pony Name : \033[0;36m" << pony->getTitle() << "\033[0m." << std::endl;
  std::cout << "\tChecking Teddy Name : \033[0;36m" << teddy->getTitle() << "\033[0m." << std::endl;
  std::cout << "\tfilling up the array with the pony and teddy object..." << std::endl;
  std::cout << "\t\t...Adding teddy to the array." << std::endl;
  array[0] = teddy;
  std::cout << "\t\t...Adding pony to the array." << std::endl;
  array[1] = pony;
  std::cout << "\t\t...Seting NULL pointer at the end of the array." << std::endl;
  array[2] = NULL;
  std::cout << "\tChecking the content of the array : array[0] = \"\033[0;36m"<< array[0]->getTitle() << "\033[0m\", array[1] = \"\033[0;36m" << array[1]->getTitle() << "\033[0m\", array[2] = \033[0;35m" << array[2] << "\033[0m !" << std::endl;
  if (array[0]->getTitle() != "bisounours" || array[1]->getTitle() != "gay pony")
    std::cerr << "\t\033[1;35mERROR : the array isn't correctly set ! \033[0m" << std::endl;
  else
    std::cout << "\t\033[32mSUCCESS : the array is correctly set ! \033[0m" << std::endl;
  std::cout << "\tReturning the array." << std::endl;
  std::cout << "\033[0;31m#### Ending of the test ####\033[0m" << std::endl;
  return array;
}

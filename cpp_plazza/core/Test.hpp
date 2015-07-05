//
// Test.hh for test in /home/girard_r/Documents/plazza/tp
// 
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
// 
// Started on  Thu Apr 16 16:21:58 2015 Aurélien GIRARDEAU
// Last update Fri Apr 17 13:17:38 2015 Aurélien GIRARDEAU
//

#ifndef TEST_HH_
# define TEST_HH_

# include <string>
# include <iostream>
# include <unistd.h>
# include "AObj.hh"
# include "Mutex.hh"

class		Test : public AObj
{
private :
  int		*_cmp;

public :
  Test(int *cmp)
    : AObj(NULL), _cmp(cmp)
  {}
  virtual ~Test() {}
  virtual void		start()
  {
    for (int i  = 0; i < 10; ++i)
      *_cmp += 1;
    std::cout << "youpi je suis en marche !!!" << std::endl;
  }
};

#endif

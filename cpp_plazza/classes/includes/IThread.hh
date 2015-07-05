//
// IThread.hh for Plazza in /home/girard_r/Documents/plazza/tp
// 
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
// 
// Started on  Thu Apr 16 14:38:17 2015 Aurélien GIRARDEAU
// Last update Thu Apr 16 17:26:02 2015 Aurélien GIRARDEAU
//

#ifndef ITHREAD_HH_
# define ITHREAD_HH_

# include <pthread.h>

class		IThread
{
public :
  typedef enum
    {
      WAITING = 1,
      RUNNING,
      DEAD
    }		e_status;

  virtual ~IThread() {}
  virtual bool		wait() = 0;
  virtual bool		start() = 0;
};

#endif

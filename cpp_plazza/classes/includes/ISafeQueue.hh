//
// ISafeQueue.hh for plazza in /home/girard_r/Documents/plazza/tp
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Mon Apr 20 16:07:36 2015 Aurélien GIRARDEAU
// Last update Fri Apr 24 21:47:54 2015 Aurélien GIRARDEAU
//

#ifndef ISAFEQUEUE_HH_
# define ISAFEQUEUE_HH_

template <typename T>
class			ISafeQueue
{
public:
  virtual ~ISafeQueue(void) {}
  virtual void		push(T const& value) = 0;
  virtual bool		tryPop(T** value) = 0;
  virtual bool		isFinished(void) = 0;
  virtual void		setFinished(void) = 0;
};

#endif

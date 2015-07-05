//
// CondVar.cpp for CondVar in /home/girard_r/Documents/plazza/tp
// 
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
// 
// Started on  Fri Apr 17 13:24:45 2015 Aurélien GIRARDEAU
// Last update Fri Apr 17 15:23:11 2015 Aurélien GIRARDEAU
//

#include "CondVar.hh"

CondVar::CondVar(Mutex *mutex)
  : _mutex(mutex)
{
  pthread_cond_init(&_cond, NULL);
}

CondVar::~CondVar()
{
}

void		CondVar::wait(void)
{
  pthread_cond_wait(&_cond, _mutex->getMutex());
}

void		CondVar::signal(void)
{
  if (pthread_cond_signal(&_cond))
    throw std::exception();
}

void		CondVar::broadcast(void)
{
  if (pthread_cond_broadcast(&_cond))
    throw std::exception();
}

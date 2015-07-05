//
// Mutex.cpp for Plazza in /home/girard_r/Documents/plazza/tp
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Thu Apr 16 13:48:33 2015 Aurélien GIRARDEAU
// Last update Fri Apr 17 13:31:23 2015 Aurélien GIRARDEAU
//

#include "Mutex.hh"

Mutex::Mutex()
{
  pthread_mutex_init(&_mutex, NULL);
}

Mutex::~Mutex()
{
  pthread_mutex_destroy(&_mutex);
}

void	Mutex::lock()
{
  pthread_mutex_lock(&_mutex);
}

void	Mutex::unlock()
{
  pthread_mutex_unlock(&_mutex);
}

bool	Mutex::trylock()
{
  return (pthread_mutex_trylock(&_mutex) == 0 ? true : false);
}

pthread_mutex_t*	Mutex::getMutex()
{
  return (&_mutex);
}

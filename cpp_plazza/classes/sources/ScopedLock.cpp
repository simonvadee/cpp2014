//
// ScopedLock.cpp for ScopedLock in /home/girard_r/Documents/plazza/tp
// 
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
// 
// Started on  Thu Apr 16 14:14:20 2015 Aurélien GIRARDEAU
// Last update Thu Apr 16 16:10:10 2015 Aurélien GIRARDEAU
//

#include "ScopedLock.hh"

ScopedLock::ScopedLock(Mutex &mutex)
  : _mutex(mutex)
{
  _mutex.lock();
}

ScopedLock::~ScopedLock()
{
  _mutex.unlock();
}

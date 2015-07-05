//
// ScopedLock.hh for ScopedLock in /home/girard_r/Documents/plazza/tp
// 
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
// 
// Started on  Thu Apr 16 14:14:27 2015 Aurélien GIRARDEAU
// Last update Thu Apr 16 14:32:24 2015 Aurélien GIRARDEAU
//

#ifndef SCOPED_LOCK_HH
# define SCOPED_LOCK_HH

# include "Mutex.hh"

class		ScopedLock
{
private :
  Mutex		&_mutex;

public :
  ScopedLock(Mutex &mutex);
  ~ScopedLock();
private :
  ScopedLock&	operator=(ScopedLock const&);
  ScopedLock(ScopedLock const&);
};

#endif /* !SCOPED_LOCK_HH */

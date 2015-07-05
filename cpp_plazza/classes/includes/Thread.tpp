//
// Thread.cpp for plazza in /home/girard_r/Documents/plazza/tp
// 
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
// 
// Started on  Thu Apr 16 15:42:00 2015 Aurélien GIRARDEAU
// Last update Fri Apr 24 19:21:12 2015 Aurélien GIRARDEAU
//

template <typename T>
Thread<T>::Thread(T* handler)
  : _status(WAITING), _handler(handler)
{
  _joinErrors[ESRCH] = "Aucun thread : ne correspond pas à celui passé en argument";
  _joinErrors[EINVAL] = "Le thread a été détaché ou un autre thread attend déjà\
 la fin du même thread.";
  _joinErrors[EDEADLK] = "Le thread passé en argument correspond au thread appelant.";
}

template <typename T>
Thread<T>::~Thread()
{
}

template <typename T>
bool					Thread<T>::wait()
{
  int					ret;
  std::map<int, std::string>::iterator	it;

  if (_status == RUNNING)
    {
      ret = pthread_join(_th, NULL);
      _status = DEAD;
      if ((it = _joinErrors.find(ret)) != _joinErrors.end())
	throw PlazzaError::ThreadError(it->first, it->second);
      return (true);
    }
  return (false);
}

template <typename T>
bool		Thread<T>::start()
{
  if (!pthread_create(&_th, NULL, &start_routine, (void *)_handler))
    {
      _status = RUNNING;
      return (true);
    }
  return (false);
}

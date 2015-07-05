//
// SafeFinished.tpp for plazza in /home/girard_r/Documents/plazza/tp
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Thu Apr 16 19:06:08 2015 Aurélien GIRARDEAU
// Last update Sat Apr 25 17:48:54 2015 Aurélien GIRARDEAU
//

template <typename T>
SafeFinished<T>::SafeFinished(Mutex* mutex)
  : _mutex(mutex)
{
}

template <typename T>
SafeFinished<T>::~SafeFinished(void)
{
}

template <typename T>
void		SafeFinished<T>::push(T const& value)
{
  ScopedLock	lock(*_mutex);

  _queue.push_front(new T(value));
}

template <typename T>
bool		SafeFinished<T>::tryPop(T** value)
{
  ScopedLock	lock(*_mutex);

  *value = NULL;
  if (!_queue.empty())
    {
      *value = new T(*_queue.front());
      _queue.pop_front();
      return true;
    }
  (void)value;
  return false;
}

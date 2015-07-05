//
// SafeQueue.tpp for plazza in /home/girard_r/Documents/plazza/tp
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Thu Apr 16 19:06:08 2015 Aurélien GIRARDEAU
// Last update Sat Apr 25 17:50:00 2015 Aurélien GIRARDEAU
//

template <typename T>
SafeQueue<T>::SafeQueue(Mutex* mutex, CondVar* cond)
  : _isFinished(false), _mutex(mutex), _cond(cond)
{
}

template <typename T>
SafeQueue<T>::~SafeQueue(void)
{
}

template <typename T>
void		SafeQueue<T>::push(T const& value)
{
  ScopedLock	lock(*_mutex);

  _queue.push_front(new T(value));
  _cond->broadcast();
}

template <typename T>
bool		SafeQueue<T>::tryPop(T** value)
{
  *value = NULL;
    if (_queue.size() > 0)
    {
      *value = new T(*_queue.back());
      _queue.pop_back();
      return (true);
    }
  (void)value;
  return (false);
}

template <typename T>
bool		SafeQueue<T>::isFinished(void)
{
  ScopedLock	lock(*_mutex);

  if (_queue.empty() && _isFinished)
    return (true);
  return (false);
}

template <typename T>
void		SafeQueue<T>::setFinished(void)
{
  ScopedLock	lock(*_mutex);

  _isFinished = true;
}

template <typename T>
T		*SafeQueue<T>::pop(void)
{
  if (isFinished())
    throw PlazzaError::ClosingThreads("Work is over");

  ScopedLock	lock(*_mutex);
  T		*ret = NULL;

  if (_queue.empty())
    {
      _cond->wait();
    }
  if (!tryPop(&ret))
    return NULL;
  return ret;
}

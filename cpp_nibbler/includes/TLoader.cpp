//
// TLoader.cpp for nibbler in /home/girard_r/rendu/cpp_nibbler/sources
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Wed Mar 25 19:59:04 2015 Aurélien GIRARDEAU
// Last update Sat Mar 28 18:12:17 2015 Aurélien GIRARDEAU
//

#include <dlfcn.h>
#include <cerrno>
#include <cstring>
#include <cstdio>

template <typename T>
TLoader<T>::TLoader()
{
}

template <typename T>
TLoader<T>::~TLoader()
{
}

template <typename T>
T*		TLoader<T>::getInstance(char* gui)
{
  T*		(*external_creator)();
  void*		dlhandle;

  if ((dlhandle = dlopen(gui, RTLD_LAZY)) == NULL)
    {
      std::cerr << " Library not found" << std::endl;
      return (NULL);
    }
  external_creator = reinterpret_cast<T* (*)()>(dlsym(dlhandle, "getInstance"));
  if (external_creator == NULL)
    {
      std::cerr << " Error while loading library : " << gui << std::endl;
      return (NULL);
    }
  return (external_creator());
}

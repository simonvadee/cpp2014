//
// NamedPipe.cpp for plazza in /home/girard_r/Documents/plazza
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Sun Apr 26 13:58:07 2015 Aurélien GIRARDEAU
// Last update Sun Apr 26 14:01:16 2015 Aurélien GIRARDEAU
//

#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "Exceptions.hpp"
#include "NamedPipe.hh"

NamedPipe::NamedPipe(int pid, const char *fileSend, const char *fileReceive, Correspondance *coresp)
  : _pid(pid),
    _fileSend(fileSend),
    _fileReceive(fileReceive),
    _coresp(coresp)
{
  if ((_fdSend = open(_fileSend, O_RDWR)) == -1
      || (_fdReceive = open(_fileReceive, O_RDWR)) == -1)
    throw PlazzaError::NamedPipeError(errno, "Couldn't open namepipe\n");
}

NamedPipe::~NamedPipe(void)
{
}

int				NamedPipe::getSend() const
{
  return _fdSend;
}

int				NamedPipe::getReceive() const
{
  return _fdReceive;
}

bool			NamedPipe::getMsgType(e_msgtype& type)
{
  int			ret = read(_fdReceive, &type, sizeof(e_msgtype));

  if (ret == -1)
    throw PlazzaError::NamedPipeError(errno, "Couldn't read on namepipe\n");
  else if (ret != sizeof(e_msgtype))
    return (false);
  lseek(_fdReceive, -sizeof(e_msgtype), SEEK_CUR);
  return (true);
}

bool			NamedPipe::send(t_pack& packed)
{
  int			ret = write(_fdSend, &packed, sizeof(t_pack));

  if (ret == -1)
    throw PlazzaError::NamedPipeError(errno, "Couldn't write on namepipe\n");
  else if (ret != sizeof(t_pack))
    return (false);
  return (true);
}

bool			NamedPipe::receive(t_pack *packed)
{
  int			ret = read(_fdReceive, packed, sizeof(t_pack));

  if (ret == -1)
    throw PlazzaError::NamedPipeError(errno, "Couldn't read on namepipe\n");
  else if (ret != sizeof(t_pack))
    return (false);
  return (true);
}

bool			NamedPipe::send(t_state& packed)
{
  int			ret = write(_fdSend, &packed, sizeof(t_state));

  if (ret == -1)
    throw PlazzaError::NamedPipeError(errno, "Couldn't write on namepipe\n");
  else if (ret != sizeof(t_state))
    return (false);
  return (true);
}

bool			NamedPipe::receive(t_state *packed)
{
  int			ret = read(_fdReceive, packed, sizeof(t_state));

  if (ret == -1)
    throw PlazzaError::NamedPipeError(errno, "Couldn't read on namepipe\n");
  else if (ret != sizeof(t_state))
    return (false);
  return (true);
}

void			NamedPipe::closeFd()
{
  close(_fdSend);
  close(_fdReceive);
}

int			NamedPipe::getPid() const
{
  return (_pid);
}

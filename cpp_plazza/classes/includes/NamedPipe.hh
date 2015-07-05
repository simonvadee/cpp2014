//
// NamedPipe.hh for plazza in /home/girard_r/Documents/plazza
// 
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
// 
// Started on  Sun Apr 26 13:58:56 2015 Aurélien GIRARDEAU
// Last update Sun Apr 26 13:58:57 2015 Aurélien GIRARDEAU
//

#ifndef NAMEDPIPE_HH_
# define NAMEDPIPE_HH_

# include "INamedPipe.hh"

class				NamedPipe : public INamedPipe
{
private:
  int				_pid;
  const char*			_fileSend;
  const char*			_fileReceive;
  Correspondance		*_coresp;
  int				_fdSend;
  int				_fdReceive;

public:
  NamedPipe(int pid, const char *fileSend, const char *fileReceive, Correspondance *coresp);
  ~NamedPipe(void);

  bool				getMsgType(e_msgtype &type);
  bool				send(t_pack& packed);
  bool				receive(t_pack *packed);
  bool				send(t_state& packed);
  bool				receive(t_state *packed);
  void				closeFd();
  int				getPid() const;
  int				getSend() const;
  int				getReceive() const;
};

// # include "NamedPipe.tpp"

#endif

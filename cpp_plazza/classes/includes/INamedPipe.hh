#ifndef INAMEDPIPE_HH_
# define INAMEDPIPE_HH_

# include "Correspondance.hh"

class				INamedPipe
{
public:
  virtual ~INamedPipe(void) {}

  virtual bool			send(t_pack& packed) = 0;
  virtual bool			receive(t_pack *packed) = 0;

  virtual bool			send(t_state& packed) = 0;
  virtual bool			receive(t_state *packed) = 0;
};

#endif

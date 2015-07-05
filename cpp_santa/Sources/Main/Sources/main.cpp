#include <iostream>
#include <deque>
#include "LittlePony.hh"
#include "Teddy.hh"
#include "TableRand.hh"
#include "Box.hh"
#include "GiftPaper.hh"
#include "ConveyorBeltPePeNoel.hh"
#include "TablePePeNoel.hh"
#include "ElfOfPePeNoel.hh"
#include "Playmobil.hh"
#include "Barbie.hh"
#include "MagicTypeSource.hh"

Object**			MyUnitTests1();
Object*				MyUnitTests2(Object**);
TablePePeNoel*			createTable();
ConveyorBeltPePeNoel*		createConveyor(std::deque<Object*> queue);

int main()
{
  unsigned int		i = 0;
  
  Toy*			titouan = new LittlePony("Titouan");
  Toy*			poulpy = new Teddy("Poulpy");
  Toy*			alex = new Playmobil("Alex");
  Toy*			simon = new Barbie("Simon");

  Object*		box1 = new Box;
  Object*		box2 = new Box;
  Object*		box3 = new Box;
  Object*		box4 = new Box;

  Object*		redPaper = new GiftPaper;
  Object*		bluePaper = new GiftPaper;
  Object*		greenPaper = new GiftPaper;
  Object*		goldPaper = new GiftPaper;

  IElf*			elf = new ElfOfPePeNoel;

  ITable*		tablePepe = new TablePePeNoel;

  MagicTypeSource	mts;
  ITable*		tableRand;
  
  Object**		testArray1 = MyUnitTests1();

  Object**		secondTest = new Object*[4];
  secondTest[0] = titouan;
  secondTest[1] = box1;
  secondTest[2] = redPaper;
  secondTest[3] = NULL;

  MyUnitTests2(secondTest);

  IConveyorBelt*	conveyor;
  std::deque<Object*>	queue;

  queue.push_back(titouan);
  queue.push_back(box1);
  queue.push_back(redPaper);
  queue.push_back(poulpy);
  queue.push_back(box2);
  queue.push_back(bluePaper);
  queue.push_back(alex);
  queue.push_back(box3);
  queue.push_back(greenPaper);
  queue.push_back(simon);
  queue.push_back(box4);
  queue.push_back(goldPaper);
  conveyor = new ConveyorBeltPePeNoel(queue);

  std::cout << "Running process with a classic table : ->" << std::endl;
  elf->run(*tablePepe, *conveyor);

  mts.learnToyType(titouan);
  mts.learnToyType(poulpy);
  mts.learnToyType(alex);
  mts.learnToyType(simon);
  tableRand = new TableRand(&mts);
  std::cout << std::endl << "Running process with a random generated table : ->" << std::endl;
  elf->run(*tableRand, *conveyor);

  delete titouan;
  delete poulpy;
  delete alex;
  delete simon;
  delete box1;
  delete box2;
  delete box3;
  delete box4;
  delete redPaper;
  delete bluePaper;
  delete greenPaper;
  delete goldPaper;
  delete [] secondTest;
  for (i = 0; testArray1[i] != NULL; i++)
    delete testArray1[i];
  delete [] testArray1;
  delete tableRand;
  delete tablePepe;
  delete conveyor;
  delete elf;
  return 0;
}

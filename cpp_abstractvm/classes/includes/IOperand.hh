//
// IOperand.hh for abstractvm in /home/girard_r/rendu/cpp_abstractvm/classes
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Tue Feb 10 14:54:14 2015 Aurélien GIRARDEAU
// Last update Fri Feb 27 17:29:20 2015 Aurélien GIRARDEAU
//

#ifndef IOPERAND_HH_
# define IOPERAND_HH_

# include <string>

typedef enum
  {
    Int8 = 0,
    Int16,
    Int32,
    Float,
    Double
  }	eOperandType;

class			IOperand
{
public :
  virtual		std::string const& toString() const = 0; // Renvoie une string représentant l'instance

  virtual int		getPrecision() const = 0; // Renvoie la précision du type de l'instance
  virtual eOperandType	getType() const = 0; // Renvoie le type de l'instance

  virtual IOperand*	operator+(const IOperand &rhs) const = 0; //Somme
  virtual IOperand*	operator-(const IOperand &rhs) const = 0; //Difference
  virtual IOperand*	operator*(const IOperand &rhs) const = 0; //Produit
  virtual IOperand*	operator/(const IOperand &rhs) const = 0; //Quotient
  virtual IOperand*	operator%(const IOperand &rhs) const = 0; //Modulo

  virtual ~IOperand() {};
};

#endif /* IOPERAND_HH_ */

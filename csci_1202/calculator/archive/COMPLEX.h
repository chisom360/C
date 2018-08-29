class COMPLEX{
  double Re;
  double Im;
public:
  COMPLEX(double r, double im);
  COMPLEX(const COMPLEX &c)
  {
    Re = c.Re;
    Im = c.Im;
  }
  COMPLEX( )
  {
    Re = Im = 0;
  }
  ~COMPLEX( )
  {
  }

  COMPLEX operator*(const COMPLEX & b) const;
  COMPLEX operator-(const COMPLEX &b) const;
  float getReal() const;
  float getImag() const;
};

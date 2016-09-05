#pragma once
#include <string>
using namespace std;
class cConjunto
{
private:
	double *m_Elements;
	int m_Dimension;
	string xstr = "hola";
wq	///double TOP;
qw	void Copy(double *p_FromArray,int p_startPos, int p_Count);
	
public:
	cConjunto(void);
	cConjunto(double *p_Values, int p_cants);
	virtual ~cConjunto(void);
	//--- normal properties
	int getDimension();
	double getElement(int p_posicion);
	// --- basic method (altas y baja
	void Add(double p_value);
	void Remove(); // todos los elementos
	void Remove(int p_posicion);
	// --- especial Methods
	void Ordering();
	cConjunto unir(cConjunto p_objConEste);
	cConjunto unir(cConjunto p_objConEste, bool p_Distinct);
	cConjunto operator+(cConjunto p_newSet );
	cConjunto operator-(cConjunto p_newSet );
	void leer();
	void grabar();
	int getInteger(string  p_str);

};

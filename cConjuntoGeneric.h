#pragma once
#include <string>
#include <sstream>

using namespace std;


template <class T>

class cConjuntoGeneric
{
private:
	T *m_Elements;
	int m_Dimension;
	///double TOP;
	void Copy(T *p_FromArray, int p_startPos, int p_Count);

public:
	cConjuntoGeneric(void);
	cConjuntoGeneric(T *p_Values, int p_cant);
	virtual ~cConjuntoGeneric(void);
	//--- normal properties
	int getDimension();
	T getElement(int p_posicion);
	// --- basic method (altas y baja
	void Add(T p_value);
	void Remove(); // todos los elementos
	void Remove(int p_posicion);
	// --- especial Methods
	void Ordering();
	cConjuntoGeneric unir(cConjuntoGeneric p_objConEste);
	cConjuntoGeneric unir(cConjuntoGeneric p_objConEste, bool p_Distinct);
	cConjuntoGeneric operator+(cConjuntoGeneric p_newSet);
	cConjuntoGeneric operator-(cConjuntoGeneric p_newSet);
	void leer();
	void grabar();
	T getInteger(string  p_str);
};
///---===========================================
// implementacion interna, por linkers
// normal constructor
template <class T> cConjuntoGeneric<T>::cConjuntoGeneric(void)
{
	m_Dimension = 0;
}
// adicional constructor
template <class T> cConjuntoGeneric<T>::cConjuntoGeneric(T *p_Values, int p_cant){
	if (p_Values == NULL)
		return;
	m_Dimension = p_cant;// sizeof(p_Values);
	m_Elements = new T[m_Dimension];
	Copy(p_Values, 0, m_Dimension);
}
template <class T> cConjuntoGeneric<T>::~cConjuntoGeneric(void)
{
	m_Elements = NULL;
}
//--- normal propertie
template <class T> int cConjuntoGeneric<T>::getDimension(){
	return m_Dimension;
}
template <class T> T cConjuntoGeneric<T>::getElement(int p_posicion){
	if (p_posicion > -1 && p_posicion < m_Dimension)
		return m_Elements[p_posicion];
	else
		return 0; // producir error
}
// --- basic method
template <class T> void cConjuntoGeneric<T>::Add(T p_value){
	T *tempElems = m_Elements; // copy RAm 
	m_Dimension++;
	m_Elements = new T[m_Dimension];
	Copy(tempElems, 0, m_Dimension - 1);
	m_Elements[m_Dimension - 1] = p_value;
}
template <class T> void cConjuntoGeneric<T>::Copy(T *p_FromArray, int p_startPos, int p_Count){
	for (int i = p_startPos; i<p_Count && i<m_Dimension; i++)
		m_Elements[i] = p_FromArray[i];
	return;
}
template <class T> void cConjuntoGeneric<T>::Remove(){
	m_Dimension = 0;
	m_Elements = new T(0);
} // todos los elementos
template <class T> void cConjuntoGeneric<T>::Remove(int p_posicion){
	T *tempElems = m_Elements;
	Copy(tempElems, 0, p_posicion);
	m_Dimension--;
	m_Elements = new T(m_Dimension);
	for (int i = p_posicion + 1; i<m_Dimension + 1; i++)
		m_Elements[i - 1] = tempElems[i];

}
// --- especial Methods
template <class T> void cConjuntoGeneric<T>::Ordering(){
	int K = 0;
	int Y = 1;
	T aux;
	while (K < m_Dimension - 1){
		if (m_Elements[K] > m_Elements[Y]){
			aux = m_Elements[K];
			m_Elements[K] = m_Elements[Y];
			m_Elements[Y] = aux;
			Y = K;
			K = -1; /// inicia de nuevo comparacion 
		}
		K++;
		if (Y <= K)
			Y++;
	}
}
template <class T> cConjuntoGeneric<T> cConjuntoGeneric<T>::unir(cConjuntoGeneric<T>  p_objConEste){
	T *TodosLosElems = new T[m_Dimension + p_objConEste.getDimension()];
	int intIter = 0;
	for (intIter = 0; intIter< m_Dimension; intIter++){
		TodosLosElems[intIter] = m_Elements[intIter];
	}
	for (int I = 0; I< p_objConEste.getDimension(); I++){
		TodosLosElems[intIter] = p_objConEste.getElement(I);
		intIter++;
	}
	cConjuntoGeneric<T> objNewConjunto = cConjuntoGeneric<T>(TodosLosElems);
	return objNewConjunto;
}
template <class T> cConjuntoGeneric<T> cConjuntoGeneric<T>::unir(cConjuntoGeneric<T>  p_objConEste, bool p_Distinct){
	int intIter = 0;
	cConjuntoGeneric<T> objNewConjunto = cConjuntoGeneric<T>();

	for (intIter = 0; intIter< m_Dimension; intIter++){
		objNewConjunto.Add(m_Elements[intIter]);
	}
	for (int I = 0; I< p_objConEste.getDimension(); I++){
		objNewConjunto.Add(p_objConEste.getElement(I));
	}
	return objNewConjunto;
}
template <class T> cConjuntoGeneric<T> cConjuntoGeneric<T>::operator+(cConjuntoGeneric<T> p_newSet){
	return this->unir(p_newSet);
}
template <class T> void  cConjuntoGeneric<T>::leer()
{
	ifstream InputFile = ifstream();
	InputFile.open("C:\\Users\\silverio del orbe\\Documents\\mydocuments\\eBooksMy\\Backup_2010\\oocpp\\Data\\Conjunto.dat");
	string lineaX;
	int Sum = 0;
	while (InputFile.good()){
		getline(InputFile, lineaX);
		///cout << lineaX << endl;

		Add(getInteger(lineaX));
	}
	InputFile.close();


}
template <class T> void  cConjuntoGeneric<T>::grabar()
{
	ofstream outFile = ofstream();
	outFile.open("C:\\Users\\silverio del orbe\\Documents\\mydocuments\\eBooksMy\\Backup_2010\\oocpp\\Data\\Conjunto.dat", ios::app);
	string lineaX;
	for (int i = 0; i < m_Dimension; i++)
	{
		outFile << m_Elements[i] << endl;

	}
	/*for (int i = 0; i < m_Dimension; i++)
	{
	if (i>0) -- 2da iteracion
	outFile << "|";
	outFile << m_Elements[i];


	}*/
	outFile.close();

}
template <class T> T cConjuntoGeneric<T>::getInteger(string p_str){
	istringstream buffer_Int(p_str);
	T lv_num ;
	try
	{
		if (!buffer_Int.bad())
			buffer_Int >> lv_num;
	}
	catch (exception & e)
	{
		
	}
	return lv_num;
}


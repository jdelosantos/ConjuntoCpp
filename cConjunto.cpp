
#include "cConjunto.h"
#include <iostream>

using namespace std;
// normal constructor
cConjunto::cConjunto(void)
{
	m_Dimension = 0;
}
// adicional constructor
cConjunto::cConjunto(double *p_Values, int p_cants){
	if (p_Values == NULL)
		return;
	m_Dimension = p_cants;//sizeof(p_Values); 
	m_Elements = new double[m_Dimension];
	Copy(p_Values,0,m_Dimension);
}
cConjunto::~cConjunto(void)
{
	m_Elements = NULL;
}
	//--- normal properties
int cConjunto::getDimension(){
	return m_Dimension;
}
double cConjunto::getElement(int p_posicion){
	if (p_posicion>-1 && p_posicion <m_Dimension)
		return m_Elements[p_posicion];
	else
		return 0; // producir error
}
	// --- basic method
void cConjunto::Add(double p_value){
	double *tempElems = m_Elements; // copy RAm 
	m_Dimension++;
	m_Elements = new double[m_Dimension];
	Copy(tempElems,0,m_Dimension-1 );
	m_Elements[m_Dimension-1] = p_value; 
}
void cConjunto::Copy(double *p_FromArray,int p_startPos, int p_Count){
	for (int i=p_startPos;i<p_Count && i<m_Dimension ;i++)
		m_Elements[i] = p_FromArray[i];
	return;
}
void cConjunto::Remove(){
	m_Dimension = 0;
	m_Elements = new double(0);
} // todos los elementos
void cConjunto::Remove(int p_posicion){
	double *tempElems = m_Elements; 
	Copy(tempElems,0,p_posicion);
	m_Dimension--;
	m_Elements = new double(m_Dimension);
	for(int i=p_posicion+1;i<m_Dimension+1;i++)
		m_Elements[i-1] = tempElems[i]; 	
	
}
	// --- especial Methods
  void cConjunto::Ordering(){
	int K = 0;
	int Y = 1;
	double aux = 0;
	while(K < m_Dimension-1){
		if (m_Elements[K] > m_Elements[Y]){
			aux = m_Elements[K]; 	
			m_Elements[K] = m_Elements[Y];
			m_Elements[Y] = aux ;
			Y= K;
			K = -1; /// inicia de nuevo comparacion 
		}
		K++;
		if (Y<=K)
			Y++;
	}
  }
	cConjunto cConjunto::unir(cConjunto p_objConEste){
		double *TodosLosElems = new double[m_Dimension+p_objConEste.getDimension()];
		int intIter =0;
		for (intIter=0;intIter< m_Dimension;intIter++){
			TodosLosElems[intIter] = m_Elements[intIter]; 
		}
		for (int I=0;I< p_objConEste.getDimension();I++){
			TodosLosElems[intIter] = p_objConEste.getElement(I);
			intIter++;
		}
		cConjunto objNewConjunto = cConjunto(TodosLosElems, m_Dimension + p_objConEste.getDimension());
		return objNewConjunto;
	}
	cConjunto cConjunto::unir(cConjunto p_objConEste,bool p_Distinct){
		int intIter =0;
		cConjunto objNewConjunto = cConjunto(); 	
		
		for (intIter=0;intIter< m_Dimension;intIter++){
			objNewConjunto.Add( m_Elements[intIter]); 
		}
		for (int I=0;I< p_objConEste.getDimension();I++){
			objNewConjunto.Add( p_objConEste.getElement(I));
		}
		return objNewConjunto;
	}
	cConjunto cConjunto::operator+(cConjunto p_newSet ){
		return this->unir(p_newSet );
	}
	void cConjunto::leer()
	{
		ifstream InputFile = ifstream();
		InputFile.open("C:\\Users\\silverio del orbe\\Documents\\mydocuments\\eBooksMy\\Backup_2010\\oocpp\\Data\\Conjunto.dat");
		string lineaX;
		int Sum = 0;
		while (InputFile.good()){
			getline(InputFile, lineaX);
			///cout << lineaX << endl;

			this->Add( getInteger(lineaX));
		}
		InputFile.close();
		

	}
	void cConjunto::grabar()
	{
		ioutil::saveFile("conjunto", "5");
		ofstream outFile = ofstream();
		outFile.open("C:\\Users\\silverio del orbe\\Documents\\mydocuments\\eBooksMy\\Backup_2010\\oocpp\\Data\\Conjunto.dat", ios::app);
		string lineaX;
		/*for (int i = 0; i < m_Dimension; i++)
		{
			//outFile << "U[" << i << "]=" << m_Elements[i] << endl;
			outFile << m_Elements[i] << endl;

		}*/
		for (int i = 0; i < m_Dimension; i++)
		{
			if (i==0)
				outFile << endl;
			if (i>0)
				outFile << "|";
			outFile << m_Elements[i];
			

		}
		
		outFile.close();

	}
	int cConjunto::getInteger(string p_str){
		istringstream buffer_Int(p_str);
		int lv_num = 0;
		try
		{
			if (!buffer_Int.bad())
				buffer_Int >> lv_num;
		}
		catch (exception & e)
		{
			lv_num= 0;
		}
		return lv_num;
	}


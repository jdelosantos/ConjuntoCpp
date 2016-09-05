#pragma once

template <class T> 
class PuntoT
{
	private:
		T   AbscisaX;
		T  OrdenadaY;
		T  TerceraDim;
		bool isTridim;
		
	public:
		
		  
		// los constructores
		PuntoT(void);
		PuntoT(T x, T y, T z);
		PuntoT(T x, T y );// el plano
		/// operador
		PuntoT operator*(PuntoT B);
		// destructor 
		~PuntoT(void);
		// metodos 
		T getHipotenusa();
		void MoverTo(T x, T y);
		void Mover(T xplus, T yplus);
		// GETTERS ---
		T getX();
		T getY();
		T getZ();
		// sETTERS ---
		void setX(T new_x);
};

// CONSTRUCTORS
template <class T> PuntoT<T>::PuntoT(void)
{
	/*AbscisaX = (T)0;
	OrdenadaY = (T)0;
	TerceraDim = (T)0;
	*/
	}
//---> destroy

template <class T> PuntoT<T>::~PuntoT(void)
{
	isTridim = false;
}

template <class T> PuntoT<T>::PuntoT(T x, T y, T z)
{
	AbscisaX = x;
	OrdenadaY = y;
	TerceraDim = z;
	isTridim = true;
}

template <class T> PuntoT<T>::PuntoT(T x, T y)
{
	AbscisaX = x;
	OrdenadaY = y;
	//TerceraDim = 0;
	isTridim = false;
}

//METHODS ....
template <class T> T PuntoT<T>::getHipotenusa()
{
	T lv_result;
	try{
		float x = AbscisaX;
		float y = OrdenadaY;
		float z = 0;
		if (isTridim)
			z = TerceraDim;
		lv_result = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	}
	catch(exception objerror) {
		lv_result = 0;
	}
	return lv_result;
}
template <class T> void PuntoT<T>::MoverTo(T x, T y)
{
	AbscisaX = x;
	OrdenadaY = y;
}
template <class T> void PuntoT<T>::Mover(T xplus, T yplus)
{
	AbscisaX += xplus;
	OrdenadaY += yplus;
}
template <class T> PuntoT<T> PuntoT<T>::operator*(PuntoT<T> B)
{
	PuntoT<T> C = PuntoT<T>(getX() + B.getX(), OrdenadaY + B.getY(), TerceraDim + B.getZ());
	return C;
}
template <class T> T PuntoT<T>::getX()
{
	return AbscisaX;
}
template <class T> T PuntoT<T>::getY()
{
	return OrdenadaY;
}
template <class T> T PuntoT<T>::getZ()
{
	return TerceraDim;
}
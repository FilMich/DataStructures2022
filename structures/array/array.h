#pragma once

#include "../structure.h"
#include "../vector/vector.h"
#include "../utils.h"
#include <stdexcept>

namespace structures
{
	/// <summary> Pole. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych v poli. </typepram>
	template<typename T>
	class Array : public Structure
	{
	public:
		/// <summary> Konstruktor vytvori pole o velkosti size prvkov. </summary>
		/// <param name = "size"> Pocet prvkov vo vytvorenom poli. </param>
		Array(size_t size);

		/// <summary> Kopirovaci konstruktor. </summary>
		/// <param name = "other"> Pole, z ktoreho sa prevezmu vlastnosti. </param>
		Array(Array<T>& other);

		/// <summary> Destruktor. </summary>
		~Array();

		/// <summary> Vrati pocet prvkov v poli. </summary>
		/// <returns> Pocet prvkov v poli. </returns>
		size_t size() override;

		/// <summary> Priradenie struktury. </summary>
		/// <param name = "other"> Struktura, z ktorej ma prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa struktura nachadza. </returns>
		Structure& assign(Structure& other) override;

		/// <summary> Porovnanie struktur. </summary>
		/// <param name="other">Struktura, s ktorou sa ma tato struktura porovnat. </param>
		/// <returns>True ak su struktury zhodne typom aj obsahom. </returns>
		bool equals(Structure& other) override;

		/// <summary> Vrati adresou prvok na indexe. </summary>
		/// <param name = "index"> Index prvku. </param>
		/// <returns> Adresa prvku na danom indexe. </returns>
		/// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do pola. </exception>
		T& operator[](int index);

		/// <summary> Vrati adresou prvok na indexe. </summary>
		/// <param name = "index"> Index prvku. </param>
		/// <returns> Adresa prvku na danom indexe. </returns>
		/// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do pola. </exception>
		T& at(int index);

		/// <summary> Skopiruje length prvkov z pola src od pozicie srcStartIndex do pola dest od pozicie destStartIndex. </summary>
		/// <param name = "src"> Zdrojove pole. </param>
		/// <param name = "srcStartIndex"> Index prvku v poli src, od ktoreho sa zacne citat. </param>
		/// <param name = "dest"> Cielove pole. </param>
		/// <param name = "destStartIndex"> Index prvku v poli dest, od ktoreho sa zacne zapisovat. </param>
		/// <param name = "length"> Pocet prvkov, ktore budu skopirovane z pol src od pozicie srcStartIndex do pola dest od pozicie destStartIndex. </param>
		/// <exception cref="std::out_of_range"> Vyhodena, ak zaciatocne alebo koncove indexy nepatria do prislusnych poli. </exception>
		static void copy(Array<T>& src, int srcStartIndex, Array<T>& dest, int destStartIndex, int length);

	private:
		/// <summary> Vektor s datami. </summary>
		Vector* vector_;  //adresa vektora kt sluzi ako pole
		/// <summary> Pocet prvkov v poli. </summary>
		size_t size_;

	private:
		/// <summary> Mapovacia funkcia, ktora prevedie index v poli na index vo vektore. </summary>
		/// <param name = "index"> Index v poli. </param>
		/// <returns> Index vo vektore. </returns>
		int mapFunction(int index) const;
	};

	template<typename T>
	Array<T>::Array(size_t size) :
		vector_(new Vector(size * sizeof(T))),		//sizeof * size		inicializovane  calloc  same 0 
		size_(size)
	{
	}

	//vytvorim pole osob ale nebude sa volat konst cize musim spravit pole smernikov na obj  Array<Osoba*> pole4(10);
	// pole4[0] = new Osoba();		//pointre na obj alebo primitivne nic ine
	// pole4[9] = new Osoba(); .... dlzka -1  posledny

	template<typename T>
	Array<T>::Array(Array<T>& other) :
		vector_(new Vector(*(other.vector_))),  //volam copy construktor vektora a to co mi vrati ulozim do vector_
		size_(other.size_)	//vezmem size	//copy const vyzaduje priamo obiekt preto *
	{
	}

	template<typename T>
	Array<T>::~Array()
	{
		delete this->vector_;
		this->vector_ = nullptr;
		this->size_ = 0;
	}

	template<typename T>
	Structure& Array<T>::assign(Structure& other)		//inu strukturu do seba
	{
		Array<T>& otherArray = dynamic_cast<Array<T>&>(other); //nevytvaram novu premmenu ale alternativny identifikator
		//nevznikne lokalna premenna
		if (this != &other) {



			if (this->size_ != otherArray.size_) {
				std::logic_error("Array<T>::assign: Sizes of arr ale different"); //hodi vynimku
			}


			//this->vector_ = otherArray.vector_;  //nie toto zle iba mi smerniky presmeruje

			this->vector_->assign(*(otherArray.vector_)); //this je pointer vector pointer, *(otherArray.vector_) 
			//lebo assign potrebuje obiekt preto *
		}
		return *this; //vraciam obiekt nie pointer a this je pointer
	}

	template<typename T>
	inline bool Array<T>::equals(Structure& other)
	{

		Array<T>* otherArray = dynamic_cast<Array<T>*>(&other); //pretypovanie co vytvori novy pointer 
		//dynamic cast hodi vynimku ak odlisny, nechem vyhadzovat tak cez pointer aby hodil nullpointer

		return otherArray != nullptr &&
			this->size_ == otherArray->size_ &&
			this->vector_->equals(*otherArray->vector_); // vector == otherArray nemozem to bude porovnavat pointre nie obsah


	}
	//mapovanie   i * sizeof(T)   dostanem sa na polozku aku chcem   2*sizeof(T)  na 3 polozku
	//(i-5)*sizeof(T)
	//(i-B)*sizeof(T)+A    //i-Baza   baza zaciatok od 5 alebo hocico,   zaciatocna adresa kde pole zacina A - 10 11 12...,
	//cize musime priratat tu adresu o kt je to posunute +A

	template<typename T>
	size_t Array<T>::size()
	{
		return size_;
	}

	template<typename T>
	T& Array<T>::operator[](int index)
	{
		return at(index);
	}

	template<typename T>
	inline T& Array<T>::at(int index)
	{
		if (index < 0 || index >= this->size_) {	//neplatny index mimo rozsah
			throw std::out_of_range("Array<T>::at: invalid index.");

		}

		int vectorIndex = this->mapFunction(index); //vo vectorIndex budem mat adresu indexu, potom ho viem pretypovat a vybrat z neho hodnotu
		return *reinterpret_cast<T*>(this->vector_->getBytePointer(vectorIndex));	//at vracia byte, ale ja potrebujem 4 bajty
		//getBytePointer ukazovatel na prvok
		//takze preinterpretujem ako adresu T, reinterpret_cast<T*> pozeraj sa na to ako pointer na T nie na byte
		//potom dereferencujem a dostanem ten prvok
	}   //z vektora si vypytame adresu bajtu na prislusnom idexe a potom reinterpretujem na adresa T, a dereferenc dostanem samotne T
		//vracia nam to presne 4 bajty z vectora tam vieme prepisat aj citat

	template<typename T>
	void Array<T>::copy(Array<T>& src, int srcStartIndex, Array<T>& dest, int destStartIndex, int length)
	{
		//zoberie zdrojove pole a cielove pole, kopirovat zo zdrojoveho pola do cieloveho od indexu na index pocet poloziek
		//ako vo vektore copy
		if (length > 0) {
			if (srcStartIndex < 0 || srcStartIndex + length - 1 >= src.size_) {
				throw std::out_of_range("ArrArray<T>ay::copy: Invalid index in src array");
			}
			if (destStartIndex < 0 || destStartIndex + length - 1 >= src.size_) {
				throw std::out_of_range("Array<T>::copy: Invalid index in dest array");
			}

			Vector::copy(*src.vector_, src.mapFunction(srcStartIndex), *dest.vector_, dest.mapFunction(destStartIndex),
				length * sizeof(T));  //staticka metoda :: tak pristupujem;  vector je iba pointer
				//src.mapFunction(srcStartIndex)  presne mu ukazem bajt kde ma zacat
		}
	}

	template<typename T>
	inline int Array<T>::mapFunction(int index) const
	{
		return index * sizeof(T); //hodi ma na index kt chcem v tom poli
	}
}



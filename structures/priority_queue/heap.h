#pragma once

#include "priority_queue_list.h"
#include "../list/array_list.h"
#include "../utils.h"
#include <stdexcept>

namespace structures
{
	/// <summary> Prioritny front implementovany haldou. Implementujucim typom haldy je struktura ArrayList. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych v prioritnom fronte. </typepram>
	template<typename T>
	class Heap : public PriorityQueueList<T>
	{
	public:
		/// <summary> Konstruktor. </summary>
		Heap();

		/// <summary> Kopirovaci konstruktor. </summary>
		/// <param name = "other"> Halda, z ktorej sa prevezmu vlastnosti. </param>
		Heap(Heap<T>& other);

		/// <summary> Priradenie struktury. </summary>
		/// <param name = "other"> Struktura, z ktorej ma prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa struktura nachadza. </returns>
		Structure& assign(Structure& other) override;

		/// <summary> Vlozi prvok s danou prioritou do haldy. </summary>
		/// <param name = "priority"> Priorita vkladaneho prvku. </param>
		/// <param name = "data"> Vkladany prvok. </param>
		void push(int priority, const T& data) override;

		/// <summary> Odstrani prvok s najvacsou prioritou z haldy. </summary>
		/// <returns> Odstraneny prvok. </returns>
		/// <exception cref="std::logic_error"> Vyhodena, ak je halda prazdna. </exception>
		T pop() override;

	protected:
		/// <summary> Vrati index v ArrayList-e, na ktorom sa nachadza prvok s najvacsou prioritou. </summary>
		/// <returns> Index prvku s najvacsou prioritou. </returns>
		/// <exception cref="std::logic_error"> Vyhodena, ak je ArrayList prazdny. </exception>
		int indexOfPeek() override;

	private:
		/// <summary> Vrati index v ArrayList-e, na ktorom by sa mal nachadzat otec daneho prvku. </summary>
		/// <param name = "index"> Index prvku, ktoreho otca chceme vratit. </param>
		/// <returns> Index, na ktorom ba sa mal nachadzat otec prvku. </returns>
		int getParentIndex(int index);

		/// <summary> Vrati index v ArrayList-e, na ktorom by mal mat dany prvok syna s najvacsou prioritou. </summary>
		/// <param name = "index"> Index prvku, ktoreho syna chceme vratit. </param>
		/// <returns> Index, na ktorom by sa mal nachadzat syn prvku. </returns>
		int getGreaterSonIndex(int index);
	};

	template<typename T>
	Heap<T>::Heap() :
		PriorityQueueList<T>(new ArrayList<PriorityQueueItem<T>*>())
	{
	}

	template<typename T>
	Heap<T>::Heap(Heap<T>& other) :
		Heap<T>()
	{
		this->assign(other);
	}

	template<typename T>
	inline Structure& Heap<T>::assign(Structure& other)
	{
		return PriorityQueueList<T>::assign(dynamic_cast<Heap<T>&>(other));
	}

	template<typename T>
	void Heap<T>::push(int priority, const T& data)
	{
		PriorityQueueItem<T>* item = new PriorityQueueItem<T>(priority, data);
		PriorityQueueList<T>::list_->add(item);
		int index = static_cast<int>(PriorityQueueList<T>::list_->size() - 1);
		int parentIndex = this->getParentIndex(index);

		while (index > 0 && PriorityQueueList<T>::list_->at(index)->getPriority() < PriorityQueueList<T>::list_->at(parentIndex)->getPriority()) {
			Utils::swap(PriorityQueueList<T>::list_->at(index), PriorityQueueList<T>::list_->at(parentIndex));
			index = parentIndex;
			parentIndex = this->getParentIndex(index);
		}
	}

	template<typename T>
	T Heap<T>::pop()
	{
		int peekIndex = indexOfPeek();

		if (peekIndex == -1)
		{
		throw std::logic_error("PriorityQueueList<T>::peekPriority: Priority queue is empty!");
		}
		else
		{
			int indexLast = this->list_->size() - 1;

			if (peekIndex != indexLast) 
			{
				Utils::swap(this->list_->at(peekIndex), this->list_->at(indexLast));
			}

			PriorityQueueItem<T>* item = this->list_->removeAt(indexLast);

			int indexCur = indexOfPeek();
			int indexOfSon = getGreaterSonIndex(indexCur);

			while (indexOfSon != -1 && this->list_->at(indexCur)->getPriority() > this->list_->at(indexOfSon)->getPriority())
			{
				Utils::swap(this->list_->at(indexCur), this->list_->at(indexOfSon));
				indexCur = indexOfSon;
				indexOfSon = getGreaterSonIndex(indexCur);
			}

			T data = item->accessData();
			delete item;
			return data;
		}
	}

	template<typename T>
	inline int Heap<T>::getParentIndex(int index)
	{
		return (index - 1) / 2;
	}

	template<typename T>
	inline int Heap<T>::getGreaterSonIndex(int index)
	{
		int lSonIndex = 2 * index + 1;
		int rSonIndex = 2 * index + 2;

		PriorityQueueItem<T>* lSon = lSonIndex < this->list_->size() ?
			this->list_->at(lSonIndex) : nullptr;
		PriorityQueueItem<T>* rSon = rSonIndex < this->list_->size() ?
			this->list_->at(rSonIndex) : nullptr;

		if (rSon != nullptr && rSon->getPriority() < lSon->getPriority())
		{
			return rSonIndex;
		}
		else if (lSon == nullptr) 
		{
			return -1;
		}
		return lSonIndex;
	}

	template<typename T>
	inline int Heap<T>::indexOfPeek()
	{
		if (this->list_->size() == 0)
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}
}
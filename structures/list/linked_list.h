#pragma once

#include "list.h"
#include "../structure_iterator.h"
#include "../data_item.h"
#include "../utils.h"

namespace structures
{
    /// <summary> Prvok jednostranne zretazeneho zoznamu. </summary>
    /// <typeparam name = "T"> Typ dat ukladanych v prvku. </typepram>
    template<typename T>
    class LinkedListItem : public DataItem<T>
    {
    public:
        /// <summary> Konstruktor. </summary>
        /// <param name = "data"> Data, ktore uchovava. </param>
        LinkedListItem(T data);

        /// <summary> Kopirovaci konstruktor. </summary>
        /// <param name = "other"> Prvok jednstranne zretazeneho zoznamu, z ktoreho sa prevezmu vlastnosti.. </param>
        LinkedListItem(LinkedListItem<T>& other);

        /// <summary> Destruktor. </summary>
        ~LinkedListItem();

        /// <summary> Getter nasledujuceho prvku zretazeneho zoznamu. </summary>
        /// <returns> Nasledujuci prvok zretazeneho zoznamu. </returns>
        LinkedListItem<T>* getNext();

        /// <summary> Setter nasledujuceho prvku zretazeneho zoznamu. </summary>
        /// <param name´= "next"> Novy nasledujuci prvok zretazeneho zoznamu. </param>
        void setNext(LinkedListItem<T>* next);

    private:
        /// <summary> Nasledujuci prvok zretazeneho zoznamu. </summary>
        LinkedListItem<T>* next_;
    };

    /// <summary> Jednostranne zretazeny zoznam. </summary>
    /// <typeparam name = "T"> Typ dat ukladanych v zozname. </typepram>
    template<typename T>
    class LinkedList : public List<T>
    {
    public:
        /// <summary> Konstruktor. </summary>
        LinkedList();

        /// <summary> Kopirovaci konstruktor. </summary>
        /// <param name = "other"> LinkedList, z ktoreho sa prevezmu vlastnosti. </param>
        LinkedList(LinkedList<T>& other);

        /// <summary> Destruktor. </summary>
        ~LinkedList();

        /// <summary> Vrati pocet prvkov v zozname. </summary>
        /// <returns> Pocet prvkov v zozname. </returns>
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
        /// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>
        T& at(int index) override;

        /// <summary> Prida prvok do zoznamu. </summary>
        /// <param name = "data"> Pridavany prvok. </param>
        void add(const T& data) override;

        /// <summary> Vlozi prvok do zoznamu na dany index. </summary>
        /// <param name = "data"> Pridavany prvok. </param>
        /// <param name = "index"> Index prvku. </param>
        /// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>
        /// <remarks> Ak je ako index zadana hodnota poctu prvkov (teda prvy neplatny index), metoda insert sa sprava ako metoda add. </remarks>
        void insert(const T& data, int index) override;

        /// <summary> Odstrani prvy vyskyt prvku zo zoznamu. </summary>
        /// <param name = "data"> Odstranovany prvok. </param>
        /// <returns> true, ak sa podarilo prvok zo zoznamu odobrat, false inak. </returns>
        bool tryRemove(const T& data) override;

        /// <summary> Odstrani zo zoznamu prvok na danom indexe. </summary>
        /// <param name = "index"> Index prvku. </param>
        /// <returns> Odstraneny prvok. </returns>
        /// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>
        T removeAt(int index) override;

        /// <summary> Vrati index prveho vyskytu prvku v zozname. </summary>
        /// <param name = "data"> Prvok, ktoreho index sa hlada. </param>
        /// <returns> Index prveho vyskytu prvku v zozname, ak sa prvok v zozname nenachadza, vrati -1. </returns>
        int getIndexOf(const T& data) override;

        /// <summary> Vymaze zoznam. </summary>
        void clear() override;

        /// <summary> Vrati skutocny iterator na zaciatok struktury </summary>
        /// <returns> Iterator na zaciatok struktury. </returns>
        /// <remarks> Zabezpecuje polymorfizmus. </remarks>
        Iterator<T>* getBeginIterator() override;

        /// <summary> Vrati skutocny iterator na koniec struktury </summary>
        /// <returns> Iterator na koniec struktury. </returns>
        /// <remarks> Zabezpecuje polymorfizmus. </remarks>
        Iterator<T>* getEndIterator() override;

    private:
        /// <summary> Pocet prvkov v zozname. </summary>
        size_t size_;
        /// <summary> Prvy prvok zoznamu. </summary>
        LinkedListItem<T>* first_;
        /// <summary> Posledny prvok zoznamu. </summary>
        LinkedListItem<T>* last_;

    private:
        /// <summary> Vrati prvok zoznamu na danom indexe. </summary>
        /// <param name = "index"> Pozadovany index. </summary>
        /// <returns> Prvok zoznamu na danom indexe. </param>
        /// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>
        LinkedListItem<T>* getItemAtIndex(int index);

    private:
        /// <summary> Iterator pre LinkedList. </summary>
        class LinkedListIterator : public Iterator<T>
        {
        public:
            /// <summary> Konstruktor. </summary>
            /// <param name = "position"> Pozicia v zretazenom zozname, na ktorej zacina. </param>
            LinkedListIterator(LinkedListItem<T>* position);

            /// <summary> Destruktor. </summary>
            ~LinkedListIterator();

            /// <summary> Operator priradenia. Priradi do seba hodnotu druheho iteratora. </summary>
            /// <param name = "other"> Druhy iterator. </param>
            /// <returns> Vrati seba po priradeni. </returns>
            Iterator<T>& operator= (Iterator<T>& other) override;

            /// <summary> Porovna sa s druhym iteratorom na nerovnost. </summary>
            /// <param name = "other"> Druhy iterator. </param>
            /// <returns> True, ak sa iteratory nerovnaju, false inak. </returns>
            bool operator!=(Iterator<T>& other) override;

            /// <summary> Vrati data, na ktore aktualne ukazuje iterator. </summary>
            /// <returns> Data, na ktore aktualne ukazuje iterator. </returns>
            T operator*() override;

            /// <summary> Posunie iterator na dalsi prvok v strukture. </summary>
            /// <returns> Iterator na dalsi prvok v strukture. </returns>
            /// <remarks> Zvycajne vrati seba. Ak vrati iny iterator, povodny bude automaticky zruseny. </remarks>
            Iterator<T>& operator++() override;

        private:
            /// <summary> Aktualna pozicia v zozname. </summary>
            LinkedListItem<T>* position_;
        };
    };

    template<typename T>
    inline LinkedListItem<T>::LinkedListItem(T data) :
        DataItem<T>(data),
        next_(nullptr)
    {
    }

    template<typename T>
    inline LinkedListItem<T>::LinkedListItem(LinkedListItem<T>& other) :
        DataItem<T>(other),
        next_(other.next_)
    {
    }

    template<typename T>
    inline LinkedListItem<T>::~LinkedListItem()
    {
        next_ = nullptr;
    }

    template<typename T>
    inline LinkedListItem<T>* LinkedListItem<T>::getNext()
    {
        return next_;
    }

    template<typename T>
    inline void LinkedListItem<T>::setNext(LinkedListItem<T>* next)
    {
        next_ = next;
    }

    template<typename T>
    inline LinkedList<T>::LinkedList() :
        size_(0),
        first_(nullptr),
        last_(nullptr)
    {
    }

    template<typename T>
    inline LinkedList<T>::LinkedList(LinkedList<T>& other) :
        LinkedList() // pusti sa konstruktor a nastavi sa to na null
    {
        this->assign(other);
    }

    template<typename T>
    inline LinkedList<T>::~LinkedList() // zavolam clear a zmazem to co mam v konstruktore ale v konstruktore mame null takze nerobim nic
    {
        this->clear();
    }

    template<typename T>
    inline size_t LinkedList<T>::size()
    {
        return size_;
    }

    template<typename T>
    inline Structure& LinkedList<T>::assign(Structure& other)
    {
        if (this != &other)
        {
            LinkedList<T>& otherLL = dynamic_cast<LinkedList<T>&>(other);
            this->clear(); //foreach linklistu
            for (T data : otherLL) {
                this->add(data);
            }
        }
        return *this;
    }

    template<typename T>
    inline bool LinkedList<T>::equals(Structure& other)
    {
        LinkedList<T>* otherLL = dynamic_cast<LinkedList<T>*>(&other);
        if (otherLL == nullptr)
        {
            return false;
        }
        if (this->size_ != otherLL->size_)
        {
            return false;
        }

        LinkedListItem<T>* curThis = this->first_;
        LinkedListItem<T>* curOtherLL = otherLL->first_;

        while (curThis != nullptr)
        {
            if (curThis->accessData() != curOtherLL->accessData())
            {
                return false;
            }
            curThis = curThis->getNext();
            curOtherLL = curOtherLL->getNext();
        }
        return true;

    }

    template<typename T>
    inline T& LinkedList<T>::at(int index)
    {
        if (index < 0 || index >= this->size_)
        {
            throw std::out_of_range("LinkedList<T>::at: Invalid index.");
        }

        return this->getItemAtIndex(index)->accessData();
    }

    template<typename T>
    inline void LinkedList<T>::add(const T& data)
    {
        LinkedListItem<T>* item = new LinkedListItem<T>(data);
        if (this->first_ == nullptr) {
            this->first_ = item;
        }
        else {
            this->last_->setNext(item);
        }
        this->last_ = item;
        this->size_++;

    }

    template<typename T>
    inline void LinkedList<T>::insert(const T& data, int index)
    {
        if (index < 0 || index > this->size_)
        {
            throw std::out_of_range("LinkedList<T>::at: Invalid index.");
        }
        if (index == this->size_)
        {
            this->add(data);
        }
        else {
            LinkedListItem<T>* item = new LinkedListItem<T>(data);
            if (index == 0)
            {
                item->setNext(this->first_);
                this->first_ = item;
            } 
            else {
                LinkedListItem<T>* prev = this->getItemAtIndex(index - 1);
                item->setNext(prev->getNext());
                prev->setNext(item);
            }
            this->size_++;
        }
    }

    template<typename T>
    inline bool LinkedList<T>::tryRemove(const T& data)
    {
        int index = this->getIndexOf(data);
        if (index < 0)
        {
            return false;
        }
        this->removeAt(index);
        return true;
    }

    template<typename T>
    inline T LinkedList<T>::removeAt(int index) //DU podobne ako vkladanie nezabudnut zmazat a vratit data osetrit posledny alebo prvy
    {
        if (index < 0 || index > this->size_)
        {
            throw std::out_of_range("LinkedList<T>::at: Invalid index.");
        }

        LinkedListItem<T>* pom;
        if (index == 0)
        {
            pom = (this->getItemAtIndex(0));
            this->first_ = this->first_->getNext();
        } 
        else
        {
            if (index == this->size_)
            {
                LinkedListItem<T>* newLast = this->getItemAtIndex(static_cast<int>(this->size_ - 2));
                pom = newLast->getNext();
                newLast->setNext(nullptr);
                this->last_ = newLast;
            }
            else
            {
                pom = (this->getItemAtIndex(index));
                this->getItemAtIndex(index - 1)->setNext(pom->getNext());
            }
        }
        T data = pom->accessData();
        delete pom;
        this->size_--;
        return data;
    }

    template<typename T>
    inline int LinkedList<T>::getIndexOf(const T& data)
    {
        LinkedListItem<T>* cur = this->first_;
        int i = 0;
        while (cur != nullptr)
        {
            if (cur->accessData() == data)
            {
                return i;
            }
            i++;
            cur = cur->getNext();
        }
        return -1;
    }

    template<typename T>
    inline void LinkedList<T>::clear() //od zaciatku, od konca by to bolo narocne lebo musime nastavovat last*
    {
        LinkedListItem<T>* cur = this->first_;

        while (cur != nullptr)
        {
            this->first_ = cur->getNext();
            delete cur;
            cur = this->first_;
        }
        this->last_ = nullptr;
        this->size_ = 0;

    }

    template<typename T>
    inline Iterator<T>* LinkedList<T>::getBeginIterator()
    {
        return new LinkedListIterator(first_);
    }

    template<typename T>
    inline Iterator<T>* LinkedList<T>::getEndIterator()
    {
        return new LinkedListIterator(nullptr);
    }

    template<typename T>
    inline LinkedListItem<T>* LinkedList<T>::getItemAtIndex(int index) //zaviest si premennu current a v cykle sa dostat na ten index aky chceme
    {
        if (index == static_cast<int>(this->size_ - 1))
            return this->last_;

        LinkedListItem<T>* cur = this->first_;
        for (int i = 0; i < index; i++)
        {
            cur = cur->getNext();
        }
        return cur;
    }

    template<typename T>
    inline LinkedList<T>::LinkedListIterator::LinkedListIterator(LinkedListItem<T>* position) :
        position_(position)
    {
    }

    template<typename T>
    inline LinkedList<T>::LinkedListIterator::~LinkedListIterator()
    {
        this->position_ = nullptr;
    }

    template<typename T>
    inline Iterator<T>& LinkedList<T>::LinkedListIterator::operator=(Iterator<T>& other)
    {
        if (this != &other)
        {
            LinkedListIterator& otherIt = dynamic_cast<LinkedListIterator&>(other); //lebo ak mi to hodi nullptr tak s tym nic nespravim
            this->position_ = otherIt.position_;
        }
        return *this;
    }

    template<typename T>
    inline bool LinkedList<T>::LinkedListIterator::operator!=(Iterator<T>& other)
    {
        LinkedListIterator* otherIt = dynamic_cast<LinkedListIterator*>(&other);
        return otherIt == nullptr || this->position_ != otherIt->position_;
    }

    template<typename T>
    inline T LinkedList<T>::LinkedListIterator::operator*()
    {
        return this->position_->accessData();
    }

    template<typename T>
    inline Iterator<T>& LinkedList<T>::LinkedListIterator::operator++()
    {
        this->position_ = this->position_->getNext();
        return *this;
    }

}
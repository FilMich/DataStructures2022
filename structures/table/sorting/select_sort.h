#pragma once

#include "sort.h"
#include "../unsorted_sequence_table.h"

namespace structures
{
	template <typename T, typename O>
	class Criterium
	{
	public:
		virtual O getValue(const T& object) = 0; // O - navratovy typ
	};
	class UJ
	{
	public:
		std::string getName() const { return this->name_; }
	private:
		std::string name_;
	};
	class CriteriumName : 
		public Criterium<UJ, std::string>
	{
	public:
		std::string getValue(const UJ& object) override
		{
			return object.getName();
		}
	};

	/// <summary> Triedenie Select sort. </summary>
	/// <typeparam name = "K"> Kluc prvkov v tabulke. </typepram>
	/// <typeparam name = "T"> Typ dat ukladanych v tabulke. </typepram>
	template <typename K, typename T, typename O>
	class SelectSort : public Sort<K, T>
	{
	public:
		/// <summary> Utriedi tabulku triedenim Select sort. </summary>
		/// <param name = "table"> NonortedSequenceTable, ktoru ma utriedit. </param>
		void sort(UnsortedSequenceTable<K, T>& table);
		void sort2(UnsortedSequenceTable<K, T>& table, Criterium<T, O>& criterium);
	};

	template<typename K, typename T, typename O>
	inline void SelectSort<K, T, O>::sort(UnsortedSequenceTable<K, T>& table)
	{
		for (int i = 0; i < table.size(); i++)
		{
			K min = table.getItemAtIndex(i).getKey();
			int minIndex = i;
			for (int j = i + 1; j < table.size(); j++)
			{
				if (table.getItemAtIndex(j).getKey() < min)
				{
					min = table.getItemAtIndex(j).getKey();
					minIndex = j;
				}
			}
			table.swap(i, minIndex);
		}
	}
	template<typename K, typename T, typename O>
	inline void SelectSort<K, T, O>::sort2(UnsortedSequenceTable<K, T>& table, Criterium<T, O>& criterium)
	{
		for (int i = 0; i < table.size(); i++)
		{
			T min = criterium.getValue(table.getItemAtIndex(i).accessData());
			int minIndex = i;
			for (int j = i + 1; j < table.size(); j++)
			{
				if (criterium.getValue(table.getItemAtIndex(j).accessData()) < min)
				{
					min = criterium.getValue(table.getItemAtIndex(j).accessData());
					minIndex = j;
				}
			}
			table.swap(i, minIndex);
		}
	}
}